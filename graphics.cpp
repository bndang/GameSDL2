#include "graphics.h"

SDL_Window* window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,
                                       SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

SDL_Renderer* renderer = SDL_CreateRenderer(window, -1,
                                        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

void Graphics::initG() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        std::cout<< "SDL_Init" << SDL_GetError();

    if (!IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG))
        std::cout << "SDL_image error:" << IMG_GetError();

    if (TTF_Init() < 0) {
        std::cout << "SDL_ttf error: " << TTF_GetError();
    }

    cellEmpty = IMG_LoadTexture(renderer, "img/cell_empty.png");
    cellX = IMG_LoadTexture(renderer, "img/cell_x.png");
    cellO = IMG_LoadTexture(renderer, "img/cell_o.png");
    background = IMG_LoadTexture(renderer, "img/background.png");

}

void Graphics::renderTexture(SDL_Texture *texture, int x, int y)
{
    SDL_Rect dest;

    dest.x = x;
    dest.y = y;
    SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

    SDL_RenderCopy(renderer, texture, NULL, &dest);
}

void Graphics::render(const Tictactoe& game) {
    // xóa màn hình
    SDL_RenderClear(renderer);

    // vẽ nền
    SDL_RenderCopy(renderer, background, NULL, NULL);

    // vẽ game board
    for (int i = 0; i < BOARD_SIZE_HEIGHT; i++) {
        for (int j = 0; j < BOARD_SIZE_WIDTH; j++) {
            int x = BOARD_X + j * CELL_SIZE;
            int y = BOARD_Y + i * CELL_SIZE;
            SDL_Texture* texture = nullptr;
            switch (game.board[i][j]) {
                case EMPTY_CELL: texture = cellEmpty; break;
                case X_CELL: texture = cellX; break;
                case O_CELL: texture = cellO; break;
            }
            if (texture) renderTexture(texture, x, y);
        }
    }
    SDL_RenderPresent(renderer); // Hiển thị lại màn hình
}

void Graphics::quitG()
{
    // giải phóng bộ nhớ
    SDL_DestroyTexture(cellEmpty);
    cellEmpty = nullptr;
    SDL_DestroyTexture(cellX);
    cellX = nullptr;
    SDL_DestroyTexture(cellO);
    cellO = nullptr;

    IMG_Quit();

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

