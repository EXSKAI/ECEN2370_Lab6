
#ifndef TETRIS_TETRISBLOCKS_H
#define TETRIS_TETRISBLOCKS_H

#include "LCD_Driver.h"

// 定义俄罗斯方块的颜色 blocks color
#define TETRIS_COLOR_RED     0xF800
#define TETRIS_COLOR_BLUE    0x001F
#define TETRIS_COLOR_GREEN   0x07E0
#define TETRIS_COLOR_YELLOW  0xFFE0
#define TETRIS_COLOR_PURPLE  0xF81F
#define TETRIS_COLOR_CYAN    0x07FF
#define TETRIS_COLOR_GRAY    0x8410

#define BLOCK_SIZE 20
#define GRID_HEIGHT 10
#define GRID_WIDTH  6
typedef enum {
    I_TYPE,
    O_TYPE,
    T_TYPE,
    S_TYPE,
    Z_TYPE,
    L_TYPE,
    J_TYPE
}TetrisBlockType;

typedef struct {
    int blocks[4][2]; // 存储方块的四个方块的坐标	coordinate
} TetrisMino;

void DrawBlock(uint16_t x, uint16_t y, uint16_t color);
void DrawTetrisI(uint16_t x, uint16_t y);
void DrawTetrisO(uint16_t x, uint16_t y);
void DrawTetrisT(uint16_t x, uint16_t y);
void DrawTetrisS(uint16_t x, uint16_t y);
void DrawTetrisZ(uint16_t x, uint16_t y);
void DrawTetrisL(uint16_t x, uint16_t y);
void DrawTetrisJ(uint16_t x, uint16_t y);
void DrawTetris(TetrisBlockType type, int x, int y);
void MoveDown(TetrisBlockType type, int x, int y);
void MoveLeft(TetrisBlockType type, int x, int y);
void MoveRight(TetrisBlockType type, int x, int y);
void DrawTetrisI_0(uint16_t x, uint16_t y);
void DrawTetrisI_90(uint16_t x, uint16_t y);
void DrawTetrisI_180(uint16_t x, uint16_t y);
void DrawTetrisI_270(uint16_t x, uint16_t y);
void DrawTetrisT_0(uint16_t x, uint16_t y);
void DrawTetrisT_90(uint16_t x, uint16_t y);
void DrawTetrisT_180(uint16_t x, uint16_t y);
void DrawTetrisT_270(uint16_t x, uint16_t y);
void DrawTetrisS_0(uint16_t x, uint16_t y);
void DrawTetrisS_90(uint16_t x, uint16_t y);
void DrawTetrisS_180(uint16_t x, uint16_t y);
void DrawTetrisS_270(uint16_t x, uint16_t y);
void DrawTetrisZ_0(uint16_t x, uint16_t y);
void DrawTetrisZ_90(uint16_t x, uint16_t y);
void DrawTetrisZ_180(uint16_t x, uint16_t y);
void DrawTetrisZ_270(uint16_t x, uint16_t y);
void DrawTetrisL_0(uint16_t x, uint16_t y);
void DrawTetrisL_90(uint16_t x, uint16_t y);
void DrawTetrisL_180(uint16_t x, uint16_t y);
void DrawTetrisL_270(uint16_t x, uint16_t y);
void DrawTetrisJ_0(uint16_t x, uint16_t y);
void DrawTetrisJ_90(uint16_t x, uint16_t y);
void DrawTetrisJ_180(uint16_t x, uint16_t y);
void DrawTetrisJ_270(uint16_t x, uint16_t y);

#endif //TETRIS_TETRISBLOCKS_H
