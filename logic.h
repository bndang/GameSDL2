#ifndef _LOGIC__H
#define _LOGIC__H

#include "const.h"

class Tictactoe {
private:
    bool running = true;
    char nextMove = O_CELL;    // cho bước đầu tiên là o
    int winner = -1; // chưa end (-1), hòa (0), x thắng (1), o thắng (2)

public:
    char board[BOARD_SIZE_HEIGHT][BOARD_SIZE_WIDTH];

    void init();

    bool isBoardFull();

    bool checkLine(int row, int col);

    char checkWinner(char board[BOARD_SIZE_HEIGHT][BOARD_SIZE_WIDTH]);

    bool check(int row, int column);

    bool checkMove(int row, int column);

    void move(int row, int column);

    int getWinner();

    bool isGameOver();

    void processClick(int x, int y);

    void reset();
};

#endif // _LOGIC__H

