#include "reset.h"
#include "const.h"

void resetGame() {
    for (int i = 0; i < BOARD_SIZE_HEIGHT; i++) {
        for (int j = 0; j < BOARD_SIZE_WIDTH; j++) {
            board[i][j] = EMPTY_CELL;
        }
    }
    nextMove = O_CELL;
    running = true;        // Cho phép đi tiếp
    winner = 0;            // Reset người thắng
}
