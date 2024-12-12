
#ifndef TETRIS_GAMELOGIC_H
#define TETRIS_GAMELOGIC_H



typedef enum {		//方块朝向bolck towards
    BLOCK_UP,
    BLOCK_RIGHT,
    BLOCK_LEFT,
    BLOCK_DOWN
}block_dir_t;

typedef enum {		//方块移动方向moving toward
    MOVE_DOWN,
    MOVE_LEFT,
    MOVE_RIGHT
}move_dir_t;

void run_game();

#endif //TETRIS_GAMELOGIC_H
