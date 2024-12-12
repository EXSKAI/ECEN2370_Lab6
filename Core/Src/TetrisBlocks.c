#include "TetrisBlocks.h"

#define TETRIS_COLOR_I  LCD_COLOR_CYAN  // cyan
#define TETRIS_COLOR_O  LCD_COLOR_YELLOW  // yellow
#define TETRIS_COLOR_T  LCD_COLOR_BLUE2  // purple
#define TETRIS_COLOR_S  LCD_COLOR_GREEN  // green
#define TETRIS_COLOR_Z  LCD_COLOR_RED  // red
#define TETRIS_COLOR_L  LCD_COLOR_BLUE  // blue
#define TETRIS_COLOR_J  LCD_COLOR_GREY  // gray

// 绘制I型俄罗斯方块的四种朝向
void DrawTetrisI_0(uint16_t x, uint16_t y) {
    for (int i = 0; i < 4; i++) {
        DrawBlock(x + i, y, TETRIS_COLOR_I);
    }
}

void DrawTetrisI_90(uint16_t x, uint16_t y) {
    for (int i = 0; i < 4; i++) {
        DrawBlock(x, y + i, TETRIS_COLOR_I);
    }
}

void DrawTetrisI_180(uint16_t x, uint16_t y) {
    for (int i = 0; i < 4; i++) {
        DrawBlock(x - i, y, TETRIS_COLOR_I);
    }
}

void DrawTetrisI_270(uint16_t x, uint16_t y) {
    for (int i = 0; i < 4; i++) {
        DrawBlock(x, y - i, TETRIS_COLOR_I);
    }
}

// 绘制正方形型/O型俄罗斯方块的四种朝向（O型方块不会改变）
void DrawTetrisO(uint16_t x, uint16_t y) {
    DrawBlock(x, y, TETRIS_COLOR_O);
    DrawBlock(x + 1, y, TETRIS_COLOR_O);
    DrawBlock(x, y + 1, TETRIS_COLOR_O);
    DrawBlock(x + 1, y + 1, TETRIS_COLOR_O);
}

// 绘制T型俄罗斯方块的四种朝向
void DrawTetrisT_0(uint16_t x, uint16_t y) {
    DrawBlock(x, y, TETRIS_COLOR_T);
    DrawBlock(x + 1, y, TETRIS_COLOR_T);
    DrawBlock(x, y + 1, TETRIS_COLOR_T);
    DrawBlock(x + 1, y + 1, TETRIS_COLOR_T);
}

void DrawTetrisT_90(uint16_t x, uint16_t y) {
    DrawBlock(x, y, TETRIS_COLOR_T);
    DrawBlock(x + 1, y, TETRIS_COLOR_T);
    DrawBlock(x + 1, y + 1, TETRIS_COLOR_T);
    DrawBlock(x + 2, y + 1, TETRIS_COLOR_T);
}

void DrawTetrisT_180(uint16_t x, uint16_t y) {
    DrawBlock(x, y, TETRIS_COLOR_T);
    DrawBlock(x - 1, y, TETRIS_COLOR_T);
    DrawBlock(x, y + 1, TETRIS_COLOR_T);
    DrawBlock(x - 1, y + 1, TETRIS_COLOR_T);
}

void DrawTetrisT_270(uint16_t x, uint16_t y) {
    DrawBlock(x, y, TETRIS_COLOR_T);
    DrawBlock(x - 1, y, TETRIS_COLOR_T);
    DrawBlock(x - 1, y + 1, TETRIS_COLOR_T);
    DrawBlock(x - 2, y + 1, TETRIS_COLOR_T);
}

// 绘制S型俄罗斯方块的四种朝向
void DrawTetrisS_0(uint16_t x, uint16_t y) {
    DrawBlock(x, y, TETRIS_COLOR_S);
    DrawBlock(x + 1, y, TETRIS_COLOR_S);
    DrawBlock(x + 1, y + 1, TETRIS_COLOR_S);
    DrawBlock(x + 2, y + 1, TETRIS_COLOR_S);
}

void DrawTetrisS_90(uint16_t x, uint16_t y) {
    DrawBlock(x, y, TETRIS_COLOR_S);
    DrawBlock(x, y + 1, TETRIS_COLOR_S);
    DrawBlock(x + 1, y + 1, TETRIS_COLOR_S);
    DrawBlock(x + 1, y + 2, TETRIS_COLOR_S);
}

void DrawTetrisS_180(uint16_t x, uint16_t y) {
    DrawBlock(x, y, TETRIS_COLOR_S);
    DrawBlock(x - 1, y, TETRIS_COLOR_S);
    DrawBlock(x - 1, y + 1, TETRIS_COLOR_S);
    DrawBlock(x - 2, y + 1, TETRIS_COLOR_S);
}

void DrawTetrisS_270(uint16_t x, uint16_t y) {
    DrawBlock(x, y, TETRIS_COLOR_S);
    DrawBlock(x, y - 1, TETRIS_COLOR_S);
    DrawBlock(x + 1, y - 1, TETRIS_COLOR_S);
    DrawBlock(x + 1, y - 2, TETRIS_COLOR_S);
}

// 绘制Z型俄罗斯方块的四种朝向
void DrawTetrisZ_0(uint16_t x, uint16_t y) {
    DrawBlock(x, y, TETRIS_COLOR_Z);
    DrawBlock(x + 1, y, TETRIS_COLOR_Z);
    DrawBlock(x + 1, y + 1, TETRIS_COLOR_Z);
    DrawBlock(x + 2, y + 1, TETRIS_COLOR_Z);
}

void DrawTetrisZ_90(uint16_t x, uint16_t y) {
    DrawBlock(x, y, TETRIS_COLOR_Z);
    DrawBlock(x, y + 1, TETRIS_COLOR_Z);
    DrawBlock(x + 1, y + 1, TETRIS_COLOR_Z);
    DrawBlock(x + 1, y + 2, TETRIS_COLOR_Z);
}

void DrawTetrisZ_180(uint16_t x, uint16_t y) {
    DrawBlock(x, y, TETRIS_COLOR_Z);
    DrawBlock(x - 1, y, TETRIS_COLOR_Z);
    DrawBlock(x - 1, y + 1, TETRIS_COLOR_Z);
    DrawBlock(x - 2, y + 1, TETRIS_COLOR_Z);
}

void DrawTetrisZ_270(uint16_t x, uint16_t y) {
    DrawBlock(x, y, TETRIS_COLOR_Z);
    DrawBlock(x, y - 1, TETRIS_COLOR_Z);
    DrawBlock(x + 1, y - 1, TETRIS_COLOR_Z);
    DrawBlock(x + 1, y - 2, TETRIS_COLOR_Z);
}

// 绘制L型俄罗斯方块的四种朝向
void DrawTetrisL_0(uint16_t x, uint16_t y) {
    DrawBlock(x, y, TETRIS_COLOR_L);
    DrawBlock(x + 1, y, TETRIS_COLOR_L);
    DrawBlock(x + 1, y + 1, TETRIS_COLOR_L);
    DrawBlock(x + 2, y + 1, TETRIS_COLOR_L);
}

void DrawTetrisL_90(uint16_t x, uint16_t y) {
    DrawBlock(x, y, TETRIS_COLOR_L);
    DrawBlock(x, y + 1, TETRIS_COLOR_L);
    DrawBlock(x + 1, y + 1, TETRIS_COLOR_L);
    DrawBlock(x + 1, y + 2, TETRIS_COLOR_L);
}

void DrawTetrisL_180(uint16_t x, uint16_t y) {
    DrawBlock(x, y, TETRIS_COLOR_L);
    DrawBlock(x - 1, y, TETRIS_COLOR_L);
    DrawBlock(x - 1, y + 1, TETRIS_COLOR_L);
    DrawBlock(x - 2, y + 1, TETRIS_COLOR_L);
}

void DrawTetrisL_270(uint16_t x, uint16_t y) {
    DrawBlock(x, y, TETRIS_COLOR_L);
    DrawBlock(x, y - 1, TETRIS_COLOR_L);
    DrawBlock(x + 1, y - 1, TETRIS_COLOR_L);
    DrawBlock(x + 1, y - 2, TETRIS_COLOR_L);
}


// 绘制J型俄罗斯方块的四种朝向
void DrawTetrisJ_0(uint16_t x, uint16_t y) {
    DrawBlock(x, y, TETRIS_COLOR_J);
    DrawBlock(x + 1, y, TETRIS_COLOR_J);
    DrawBlock(x + 1, y + 1, TETRIS_COLOR_J);
    DrawBlock(x + 2, y + 1, TETRIS_COLOR_J);
}




// 绘制单个方块的辅助函数
void DrawBlock(uint16_t x, uint16_t y, uint16_t color) {
    LCD_Draw_Square_Fill(x * BLOCK_SIZE, y * BLOCK_SIZE, 20, color);

}

// 绘制I型俄罗斯方块
void DrawTetrisI(uint16_t x, uint16_t y) {
    uint16_t colors[] = {TETRIS_COLOR_CYAN, TETRIS_COLOR_CYAN, TETRIS_COLOR_CYAN, TETRIS_COLOR_CYAN};
    for (int i = 0; i < 4; i++) {
        DrawBlock(x + i, y, colors[i]);
    }
}

void DrawTetris(TetrisBlockType type, int x, int y) {
    switch (type) {
        case I_TYPE:
            DrawTetrisI(x, y);
            break;
        case O_TYPE:
            DrawTetrisO(x, y);
            break;
        case T_TYPE:
            DrawTetrisT(x, y);
            break;
        case S_TYPE:
            DrawTetrisS(x, y);
            break;
        case Z_TYPE:
            DrawTetrisZ(x, y);
            break;
        case L_TYPE:
            DrawTetrisL(x, y);
            break;
        case J_TYPE:
            DrawTetrisJ(x, y);
            break;
    }
}

// 向下移动方块
void MoveDown(TetrisBlockType type, int x, int y) {
    DrawTetris(type, x, y + 1); // 绘制方块到新位置
}

// 向左移动方块
void MoveLeft(TetrisBlockType type, int x, int y) {
    DrawTetris(type, x - 1, y); // 绘制方块到新位置
}

// 向右移动方块
void MoveRight(TetrisBlockType type, int x, int y) {
    DrawTetris(type, x + 1, y); // 绘制方块到新位置
}



//int clear_full_lines(int grid[GRID_HEIGHT][GRID_WIDTH]) {
//    int full_lines_to_clear = 0;
//    for (int y = 0; y < GRID_HEIGHT; y++) {
//        bool is_full = true;
//        for (int x = 0; x < GRID_WIDTH; x++) {
//            if (grid[y][x] == 0) {
//                is_full = false;
//                break;
//            }
//        }
//        if (is_full) {
//            full_lines_to_clear++;
//            for (int above = y; above > 0; above--) {
//                grid[above][x] = grid[above - 1][x]; // 将上面的行下移
//            }
//            for (int x = 0; x < GRID_WIDTH; x++) {
//                grid[0][x] = 0; // 顶部填充空行
//            }
//        }
//    }
//    return full_lines_to_clear;
//}
