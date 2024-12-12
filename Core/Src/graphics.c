#include "graphics.h"

int color[BLOCK_COUNT] = {
        LCD_COLOR_GREEN,
        LCD_COLOR_CYAN,
        LCD_COLOR_MAGENTA,
        LCD_COLOR_YELLOW,
        LCD_COLOR_BLUE,
        LCD_COLOR_BLUE2,
        LCD_COLOR_RED
};

int block[BLOCK_COUNT * 4][BLOCK_WIDTH][BLOCK_HEIGHT] = {
        // | 形方块
        { 0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0 },
        // L 形方块
        { 0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,1,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,1,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,1,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0 },
        // O 形方块
        { 0,0,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0 },
        // T 形方块
        { 0,0,0,0,0,0,1,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,0,1,0,0,0,1,1,0,0,0,0,1,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,1,0,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0,0,0 },
        // Z 形方块
        { 0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,1,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,1,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0,0,0 },
        //S 形方块
        { 0,0,0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,1,0,0,0,0,1,1,0,0,0,0,1,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,1,0,0,0,0,1,1,0,0,0,0,1,0,0,0,0,0,0,0 },
        // J 形方块
        { 0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,1,1,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,1,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,1,1,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0 },
        { 0,0,0,0,0,0,1,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0 },
        };

void drawBlock(int x, int y, int NextIndex) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (block[NextIndex * 4][i][j] == 1) {
                int x2 = x + j * UNIT_SIZE;
                int y2 = y + i * UNIT_SIZE;
                LCD_Draw_Square_Fill(x2, y2, 10, color[NextIndex]);
            }
        }
    }
}

void initGameScreen(void) {

    char SCORE[5] = "SCORE";
    char NEXT[4] = "NEXT";
    char TIME[4] = "TIME";
    char Recording[9] = "00";
    char Speed[5] = "SPEED";
    int NEXT_xPos = 160;
    int TIME_xPos = 160;
    int NEXT_yPos = 110;
    int SCORE_yPos = 150;
    int TIME_yPos = 150;//210;
    int Recording_yPos = 180;
    int Recording_xPos = 150;
    int SPeed_xPos = 155;
    int Speed_yPos = 195;
    int SpeedBuf_yPos = 220;
    LCD_Clear(0, LCD_COLOR_BLACK);
    LCD_SetTextColor(LCD_COLOR_WHITE);
    LCD_SetFont(&Font16x24);

    LCD_Draw_Triangle(10, 10, 300, 130, LCD_COLOR_GREY);
    LCD_Draw_Triangle(8, 8, 304, 134, LCD_COLOR_GREY);
    LCD_Draw_Square(150, 10, 85, LCD_COLOR_GREY);
    LCD_Draw_Square(148, 8, 89, LCD_COLOR_GREY);

    for(int i = 0; i < 4; i++){
        LCD_DisplayChar(NEXT_xPos+i*15, NEXT_yPos, NEXT[i]);
    }
    LCD_SetTextColor(LCD_COLOR_CYAN);
    for(int i = 0; i < 4; i++){
        LCD_DisplayChar(TIME_xPos+i*15, TIME_yPos, TIME[i]);
    }

    LCD_SetTextColor(LCD_COLOR_YELLOW);
    LCD_SetFont(&Font12x12);
//    for(int i = 0; i < 4; i++){
//        LCD_DisplayChar(Recording_xPos+i*10, Recording_yPos, Recording[i]);
//    }
    for(int i = 0; i < 9; i++){
        LCD_DisplayChar(Recording_xPos+i*10, Recording_yPos, Recording[i]);
    }

    LCD_SetFont(&Font16x24);
    LCD_SetTextColor(LCD_COLOR_BLUE);
    for(int i = 0; i < 5; i++){
        LCD_DisplayChar(SPeed_xPos+i*15, Speed_yPos, Speed[i]);
    }

    char Buf[4];
    LCD_SetFont(&Font12x12);
    LCD_SetTextColor(LCD_COLOR_GREEN);
    sprintf(Buf, "%u", speed);
    for(int i = 0; i < 4; i++){
        LCD_DisplayChar(SPeed_xPos+i*8, SpeedBuf_yPos, Buf[i]);
    }
    LCD_DisplayChar(190, SpeedBuf_yPos, 'm');
    LCD_DisplayChar(198, SpeedBuf_yPos, 's');
//    LCD_DisplayChar(150, 180, 's');
}

void MainMenu(void) {
//    LCD_Clear(0, LCD_COLOR_BLACK);
    LCD_SetTextColor(LCD_COLOR_WHITE);
    LCD_SetFont(&Font16x24);

    // 显示“START”按钮 show "start"
    char START[5] = "START";
    char Grid[13] = "Grid:13x30";
    int xpos = 60;
    for(int i = 0; i < 5; i++){
        LCD_DisplayChar(xpos+=15, 30, START[i]);
    }
    LCD_SetFont(&Font12x12);
    for(int i = 0; i < 13; i++){
        LCD_DisplayChar(40+i*15, 60, Grid[i]);
    }
    // 显示所有七个俄罗斯方块 TODO: 安排方块位置 show the Tetrisblock
    drawBlock(20, 80, 0);
    drawBlock(40, 80, 1);
    drawBlock(80, 90, 2);
    drawBlock(110, 90, 3);
    drawBlock(150, 90, 4);
    drawBlock(70, 130, 5);
    drawBlock(110, 120, 6);
}

void finalScreen(uint32_t time){
    LCD_Clear(0, LCD_COLOR_BLACK);
    LCD_SetTextColor(LCD_COLOR_WHITE);
    LCD_SetFont(&Font16x24);

    LCD_DisplayChar(40,140,'T');
    LCD_DisplayChar(55,140,'I');
    LCD_DisplayChar(70,140,'M');
    LCD_DisplayChar(85,140,'E');
    LCD_DisplayChar(100,140,':');
    char str[2];
    int xPos = 110;
//    int yPos = 140;
    sprintf(str, "%lu", time);
    for(int i = 0; i < sizeof str; i++){
        LCD_DisplayChar(xPos+i*15, 140, str[i]);
    }
    LCD_SetFont(&Font16x24);
    LCD_DisplayChar(150,140,'s');
}
