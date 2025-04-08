#include "EndGame.h"

void Endgame(SDL_Event e, bool& run, int winner) {
    SDL_Texture* background = IMG_LoadTexture(renderer, "img/background.png");

    if (background == NULL)
        std::cout << "FAIL TO LOAD BACKGROUND\n";

    SDL_Texture* exit_Texture = IMG_LoadTexture(renderer, "img/exit.jpg");
    SDL_Texture* out_Texture = IMG_LoadTexture(renderer, "img/out.jpg");

    if (exit_Texture == NULL || out_Texture == NULL)
        std::cout << "FAIL TO LOAD EXIT BUTTON\n";

    // Thiết lập nút Exit
    SDL_Rect Exit_button = {
        SCREEN_WIDTH / 2 - 90,
        SCREEN_HEIGHT / 2 + 50,
        180,
        80
    };

    // Thiết lập font
    TTF_Font* font = TTF_OpenFont("ttf/font.ttf", 48);
    SDL_Color textColor = {0, 0, 0}; // đen

    // Kết quả hiển thị
    std::string result;
    if (winner == 1) result = "Player X Wins!";
    else if (winner == 2) result = "Player O Wins!";
    else result = "Draw!";

    SDL_Surface* textSurface = TTF_RenderText_Solid(font, result.c_str(), textColor);
    SDL_Texture* result_Texture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_Rect textRect = {
        SCREEN_WIDTH / 2 - textSurface-> w / 2,
        SCREEN_HEIGHT / 2 - 100,
        textSurface->w,
        textSurface->h
    };

    SDL_FreeSurface(textSurface);

    // Vòng lặp end game
    bool out = false;
    int x, y;
    bool mouse_down = false;

    while (!out) {
        mouse_down = false;
        SDL_RenderClear(renderer);
        SDL_GetMouseState(&x, &y);

        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                run = false;
                return;
            }
            if (e.type == SDL_MOUSEBUTTONDOWN) {
                mouse_down = true;
            }
        }

        // Vẽ background + kết quả
        SDL_RenderCopy(renderer, background, NULL, NULL);
        SDL_RenderCopy(renderer, result_Texture, NULL, &textRect);

        // Vẽ nút exit
        bool on_exit_button = false;
        if (x > Exit_button.x && x < Exit_button.x + Exit_button.w &&
            y > Exit_button.y && y < Exit_button.y + Exit_button.h) {
            SDL_RenderCopy(renderer, out_Texture, NULL, &Exit_button);
            on_exit_button = true;
        } else {
            SDL_RenderCopy(renderer, exit_Texture, NULL, &Exit_button);
        }

        // Nếu nhấn vào nút Exit thì thoát chương trình
        if (on_exit_button && mouse_down) {
            run = false;
            out = true;
        }

        SDL_RenderPresent(renderer);
    }

    // Dọn dẹp
    SDL_DestroyTexture(background);
    SDL_DestroyTexture(exit_Texture);
    SDL_DestroyTexture(out_Texture);
    SDL_DestroyTexture(result_Texture);
    TTF_CloseFont(font);
}

