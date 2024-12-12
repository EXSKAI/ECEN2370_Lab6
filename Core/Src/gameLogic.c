#include "gameLogic.h"
#include "graphics.h"
#include "LCD_Driver.h"
#include "RNG_Driver.h"
#include "Button_Driver.h"
#include "string.h"

bool gameFiled = 0;

int speed = 250;  //游戏速度 game speed


uint32_t NextIndex = -1;
uint32_t BlockIndex = -1;

int visit[YGird][XGird];
int markColor[YGird][XGird];

static STMPE811_TouchData StaticTouchData;

static void clearBlock_side(void);
static void drawBlock_begin(int x, int y);
static void nextBlock(void);
static void newBlock(void);
static void move(void);
static bool moveable(int x0, int y0, move_dir_t moveDir, block_dir_t blockDir);
static void failCheck();
static void clearBlock(int x, int y, block_dir_t blockDir);
static bool rotatable(int x, int y, block_dir_t dir);
static void drawBlock_falling(int x, int y, block_dir_t dir);
static void mark(int x, int y, block_dir_t dir);
static void check(void);
static void updateGrade(void);
static void addScore(int lines);
static void down(int x);

void clearBlock_side() {
    LCD_SetTextColor(LCD_COLOR_BLACK);
    LCD_SetFont(&Font16x24);
    // TODO: wait to add func
    for (int i = 0; i < BLOCK_HEIGHT; ++i) {
        for (int j = 0; j < BLOCK_WIDTH; ++j) {
            int x = 170 + j * UNIT_SIZE;
            int y = 30 + i * UNIT_SIZE;
            LCD_Draw_Square_Fill(x, y, 10, LCD_COLOR_BLACK);
        }
    }
}

void clearBlock(int x, int y, block_dir_t blockDir) {
    uint32_t id = BlockIndex * 4 + blockDir;
    for (int i = 0; i < BLOCK_HEIGHT; ++i) {
        for (int j = 0; j < BLOCK_WIDTH; ++j) {
            if (block[id][i][j] == 1) {
                int x2 = x + j * UNIT_SIZE;
                int y2 = y + i * UNIT_SIZE;
                LCD_Draw_Square_Fill(x2, y2, 10, LCD_COLOR_BLACK);
            }
        }
    }
}

void drawBlock_begin(int x, int y) {
    for (int i = 0; i < BLOCK_HEIGHT; ++i) {
        for (int j = 0; j < BLOCK_WIDTH; ++j) {
            if (block[NextIndex * 4][i][j] == 1) {
                int x2 = x + j * UNIT_SIZE;
                int y2 = y + i * UNIT_SIZE;
                LCD_Draw_Square_Fill(x2, y2, 10, color[NextIndex]);
            }
        }
    }
}

void drawBlock_falling(int x, int y, block_dir_t dir) {
    int id = BlockIndex * 4 + dir;
    for (int i = 0; i < BLOCK_HEIGHT; ++i) {
        for (int j = 0; j < BLOCK_WIDTH; ++j) {
            if (block[id][i][j] == 1) {
                LCD_Draw_Square_Fill(x + j * UNIT_SIZE, y + i * UNIT_SIZE, 10, color[BlockIndex]);
            }
        }
    }
}

void nextBlock(void) {
    clearBlock_side();
    NextIndex = RNG_getNum() % BLOCK_COUNT;
    drawBlock_begin(170, 30);
}

bool moveable(int x0, int y0, move_dir_t moveDir, block_dir_t blockDir) {
    int x = (y0 - MinY) / UNIT_SIZE;
    int y = (x0 - MinX) / UNIT_SIZE;
    int ret = 1;
    int id = BlockIndex * 4 + blockDir;
    if (moveDir == MOVE_DOWN) {
        for (int i = 0; i < BLOCK_HEIGHT; ++i) {
            for (int j = 0; j < BLOCK_WIDTH; ++j) {
                if (block[id][i][j] == 1 &&
                    (x + i + 1 == 30 || visit[x + i + 1][y + j] == 1)) {
                    ret = 0;
                }
            }
        }
    }
    else if (moveDir == MOVE_LEFT) {
        for (int i = 0; i < BLOCK_HEIGHT; ++i) {
            for (int j = 0; j < BLOCK_WIDTH; ++j) {
                if (block[id][i][j] == 1 &&
                    (y + j <= 0 || visit[x + i][y + j - 1] == 1)) {
                    ret = 0;
                }
            }
        }
    }
    else if (moveDir == MOVE_RIGHT) {
        for (int i = 0; i < BLOCK_HEIGHT; ++i) {
            for (int j = 0; j < BLOCK_WIDTH; ++j)
            {
                //向下不能运动的条件：实心方块已经达到右边界（y+j+1>=15)，或者右边已有方块
                if (block[id][i][j] == 1 &&
                    (y + j + 1 >= 15 || visit[x + i][y + j + 1] == 1)) {
                    ret = 0;
                }
            }
        }
    }
    return ret;
}

void failCheck() {
    if (!moveable(START_X, START_Y, MOVE_DOWN, (block_dir_t)BLOCK_UP)) {
        LCD_SetTextColor(LCD_COLOR_RED);
        LCD_SetFont(&Font16x24);
        char gameOver[13] = "GAME OVER!!!";
        LCD_DisplayChar(115,140,'G');
        LCD_DisplayChar(130,140,'A');
        LCD_DisplayChar(145,140,'M');
        LCD_DisplayChar(165,140,'E');

        LCD_DisplayChar(100,160,'O');
        LCD_DisplayChar(115,160,'V');
        LCD_DisplayChar(130,160,'E');
        LCD_DisplayChar(145,160,'R');
        LCD_Delay(1000);
        //game move to next state;
        gameFiled = 1;
    }
}

bool rotatable(int x, int y, block_dir_t dir) {
    if (!moveable(x, y, MOVE_DOWN, dir)) {
        return false;
    }
    int x2 = (y - MinY) / UNIT_SIZE;
    int y2 = (x - MinX) / UNIT_SIZE;
    int id = BlockIndex * 4 + dir;
    for (int i = 0; i < BLOCK_HEIGHT; ++i) {
        for (int j = 0; j < BLOCK_WIDTH; ++j) {
            if (block[id][i][j] == 1 && (y2 + j < 0 || y2 + j >= 15 || visit[x2 + i][y2 + j] == 1)) {
                return false;
            }
        }
    }
    return true;
}

void mark(int x, int y, block_dir_t dir) {
    int id = BlockIndex * 4 + dir;
    int x2 = (y - MinY) / UNIT_SIZE;
    int y2 = (x - MinX) / UNIT_SIZE;
    for (int i = 0; i < BLOCK_HEIGHT; ++i) {
        for (int j = 0; j < BLOCK_WIDTH; ++j) {
            if (block[id][i][j] == 1) {
                visit[x2 + i][y2 + j] = 1;
                markColor[x2 + i][y2 + j] = color[BlockIndex];
            }
        }
    }
}

void move() {
    int x = START_X;
    int y = START_Y;
    int k = 0;
    block_dir_t blockDir = (block_dir_t)BLOCK_UP;
    int curSpeed = speed;

    failCheck();

    while (1) {
        curSpeed = speed;

        clearBlock(x, k + y, blockDir);

        if (returnTouchStateAndLocation(&StaticTouchData) == STMPE811_State_Pressed) {
            if (StaticTouchData.x <= 120) {
                if (moveable(x, y + k + 10, MOVE_LEFT, blockDir)) {
                    x += UNIT_SIZE;
                }
            } else {
                if (moveable(x, y + k + 10, MOVE_RIGHT, blockDir)) {
                    x -= UNIT_SIZE;
                }
            }
        }
        if (getpressed()) {
            block_dir_t nextDir = (block_dir_t)((blockDir + 1) % 4);
            if (rotatable(x, y + k, nextDir)) {
                blockDir = nextDir;
            }
            setpressed0();
        }

        k += 10;
        drawBlock_falling(x, y + k, blockDir);

        LCD_Delay(curSpeed);
        if (!moveable(x, y + k, MOVE_DOWN, blockDir)) {
            mark(x, y + k, blockDir);
            break;
        }
    }
}

void newBlock(void) {
    BlockIndex = NextIndex;
    drawBlock_begin(START_X, START_Y);
    LCD_Delay(200);
    nextBlock();
    move();
}

void down(int x) {
    for (int i = x; i > 0; --i) {
        for (int j = 0; j < XGird; ++j) {
            if (visit[i - 1][j] == 1) {
                visit[i][j] = 1;
                markColor[i][j] = markColor[i - 1][j];
                LCD_Draw_Square_Fill(10 * j + MinX, 10 * i + MinY, 10, markColor[i][j]);
            }
            else {
                visit[i][j] = 0;
                LCD_Draw_Square_Fill(10 * j + MinX, 10 * i + MinY, 10, LCD_COLOR_BLACK);
            }
        }
    }
    for (int j = 0; j < XGird; ++j) {
        visit[0][j] = 0;
        LCD_Draw_Square_Fill(10 * j + MinX, MinY, 10, LCD_COLOR_BLACK);
    }
}

void check() {
    int i, j;
    int clearLines = 0;
    for (i = YGird; i >= 0; i--) {
        for (j = 0; j < XGird && visit[i][j]; j++);
        if (j >= XGird) {
            down(i);
            i++;
            clearLines++;
        }
    }
}

void run_game(){
    gameState state = init;
    uint32_t game_time = 0;
    while(state != done){
        switch(state){
            case init:{
                titlescreen();
                state = lvl1;
                break;
            }
            case lvl1:{
                MainMenu();
                if (getpressed()) {
                    state = lvl2;  //TODO: wait for debug
                    printf("start button is pressed\n");
                    setpressed0();
                }
                break;
            }
            case lvl2:{
                game_time = HAL_GetTick();
                initGameScreen();
                nextBlock();
                HAL_Delay(300);
                memset(visit, 0, sizeof(visit));
                while (!gameFiled) {
                    newBlock();
                    check();
                }
                state = lvl3;
                break;
            }
            case lvl3:{
                uint32_t time = HAL_GetTick() - game_time;
                finalScreen(time);
                HAL_Delay(10000);
                state = done;
                break;
            }
            case done:{
                break;
            }
        }
    }

    LCD_Clear(0, LCD_COLOR_BLACK);
}
