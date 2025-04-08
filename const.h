#ifndef _CONST__H
#define _CONST__H

#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 600;

#define WINDOW_TITLE "Tic tac toe"

#define BOARD_X 0
#define BOARD_Y 0
#define CELL_SIZE 30

#define BOARD_SIZE_WIDTH 20
#define BOARD_SIZE_HEIGHT 20
#define WIN_CONDITION 5

#define EMPTY_CELL ' '
#define O_CELL 'o'
#define X_CELL 'x'

extern SDL_Window* window;
extern SDL_Renderer* renderer;

#endif // _CONST__H

