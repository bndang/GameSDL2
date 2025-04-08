#include <iostream>

#include "logic.h"
#include "const.h"
#include "graphics.h"

void Tictactoe::init() {
    for (int i = 0; i < BOARD_SIZE_HEIGHT; i++)
        for (int j = 0; j < BOARD_SIZE_WIDTH; j++) board[i][j] = EMPTY_CELL;
}

// Hàm kiểm tra xem bàn cờ đã đầy chưa
bool Tictactoe::isBoardFull() {
    for (int i = 0; i < BOARD_SIZE_HEIGHT; i++) {
        for (int j = 0; j < BOARD_SIZE_WIDTH; j++) {
            if (board[i][j] == EMPTY_CELL) {
                return false; // Còn ít nhất một ô trống
            }
        }
    }
    return true; // Không còn ô trống nào
}

// kiểm tra thắng không
bool Tictactoe::checkLine(int row, int col) {
    char player = board[row][col];

    if (player == EMPTY_CELL) return false; // Không kiểm tra ô trống

    // Các hướng kiểm tra: ngang (0,1), dọc(1,0), chéo chính(1,1), chéo phụ(1,-1)
    const int dirX[] = {0, 1, 1, 1};
    const int dirY[] = {1, 0, 1, -1};


    for(int d = 0; d < 4; d ++){

    int count = 1;      // biến đếm ô liên tiếp (bao gồm ô hiện tại)
    int dx = dirX[d], dy=dirY[d];

    // Đếm về phía trước
        for (int i = 1; i < WIN_CONDITION; i++) {
            int x = row + i * dx, y = col + i * dy;
            if (x < 0 || x >= BOARD_SIZE_HEIGHT || y < 0 || y >= BOARD_SIZE_WIDTH || board[x][y] != player) break;
            count++;
        }

        // Đếm về phía sau
        for (int i = 1; i < WIN_CONDITION; i++) {
            int x = row - i * dx, y = col - i * dy;
            if (x < 0 || x >= BOARD_SIZE_HEIGHT || y < 0 || y >= BOARD_SIZE_WIDTH || board[x][y] != player) break;
            count++;
        }
        if (count == WIN_CONDITION) return true;
    }
    return false;

}

//kiểm tra có là ô trống hay không?
bool Tictactoe::check(int row, int column){
    if(board[row][column] == EMPTY_CELL) return true;
    return false;
}

// kiểm tra bước đi tiếp theo có hợp lệ?
bool Tictactoe::checkMove(int row, int column){
    if (row >= 0 && row < BOARD_SIZE_HEIGHT && column >= 0 && column < BOARD_SIZE_WIDTH && check(row, column)){
        return true;
    }
    return false;
}

//kiểm tra thắng, hòa hay là đi tiếp?
void Tictactoe::move(int row, int column) {
    if (row >= 0 && row < BOARD_SIZE_HEIGHT && column >= 0 && column < BOARD_SIZE_WIDTH) {

        if (!checkMove(row, column)) return;

        board[row][column] = nextMove;
        moveHistory.push({row, column}); // lưu bước đi

        if (checkLine(row, column)) {
            std::cout << (nextMove == O_CELL ? "O" : "X") << " wins!\n";
            winner = (nextMove == O_CELL) ? 2 : 1; // GÁN NGƯỜI THẮNG
            running = false;
            return;
        }
        else if (isBoardFull()) {
            std::cout << "Game is a draw!\n";
            winner = 0; // GÁN HÒA
            running = false;
            return;
        }

        // Đổi lượt nếu chưa thắng/hòa
        nextMove = (nextMove == O_CELL) ? X_CELL : O_CELL;
    }
}

//trả về người thắng
int Tictactoe::getWinner() {
    return winner;
}

bool Tictactoe::isGameOver() {
    return !running;
}

void Tictactoe::processClick(int x, int y) {
    // chuyển tọa độ màn hình x, y thành tọa độ hàng cột của game
    int clickedCol = (x - BOARD_X) / CELL_SIZE;
    int clickedRow = (y - BOARD_Y) / CELL_SIZE;
    move(clickedRow, clickedCol);
}

void Tictactoe::undo() {
    if (moveHistory.empty()) return;

    auto lastMove = moveHistory.top();
    moveHistory.pop();

    board[lastMove.first][lastMove.second] = EMPTY_CELL;

    // Đổi lượt lại
    nextMove = (nextMove == O_CELL) ? X_CELL : O_CELL;
    std::cout<<(nextMove == O_CELL ? "O" : "X") << " RETURN 1 STEP\n";
}




