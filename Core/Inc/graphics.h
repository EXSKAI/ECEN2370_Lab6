
#ifndef TETRIS_GRAPHICS_H
#define TETRIS_GRAPHICS_H

#include "LCD_Driver.h"
#include "fonts.h"
#include "stmpe811.h"
#include "RNG_Driver.h"
#include "stdio.h"

#define BLOCK_COUNT 7
#define BLOCK_WIDTH 5
#define BLOCK_HEIGHT 5

#define XGird  13
#define YGird  30

#define UNIT_SIZE 10	//小方块宽度block size

#define START_X 50		//方块降落框，方块降落起始位置 start piont
#define START_Y 10


#define MinX 10		//游戏左上角位置
#define MinY 10     //游戏右上角位置

void MainMenu(void);
void initGameScreen(void);
void finalScreen(uint32_t time);

extern int color[BLOCK_COUNT];
extern int block[BLOCK_COUNT * 4][BLOCK_WIDTH][BLOCK_HEIGHT];
extern int speed;
#endif //TETRIS_GRAPHICS_H
