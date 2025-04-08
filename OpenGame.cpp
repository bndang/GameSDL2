#include "OpenGame.h"

void Opengame(SDL_Event e, bool& run) {
    SDL_Texture* background = IMG_LoadTexture(renderer, "img/background.png");

    if (background == NULL)
        std::cout << "FAIL TO LOAD BACKGROUND\n";

    SDL_Texture* start_button = IMG_LoadTexture(renderer, "img/start.png");
    SDL_Texture* start_button_after = IMG_LoadTexture(renderer, "img/play.png");

    if (start_button == NULL || start_button_after == NULL)
        std::cout << "FAIL TO LOAD START BUTTON\n";

    // Thiết lập vị trí nút Start
    SDL_Rect Blank_button = {
        SCREEN_WIDTH / 2 - 90,
        SCREEN_HEIGHT / 2 - 40,
        180,
        80
    };

    bool on_start_button = false;
    int x, y;
    bool out = false, mouse_down = false;

    while (!out) {
        mouse_down = false;

        // Xoá renderer trước khi vẽ lại
        SDL_RenderClear(renderer);

        SDL_GetMouseState(&x, &y);

        // Xử lý các sự kiện (quit, click)
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                run = false;
                return;
            }
            if (e.type == SDL_MOUSEBUTTONDOWN) {
                mouse_down = true;
            }
        }

        // Vẽ nền
        SDL_RenderCopy(renderer, background, NULL, NULL);

        // Kiểm tra nếu chuột nằm trong khu vực nút
        if (x >= Blank_button.x && x <= Blank_button.x + Blank_button.w &&
            y >= Blank_button.y && y <= Blank_button.y + Blank_button.h) {
            SDL_RenderCopy(renderer, start_button_after, NULL, &Blank_button); // Vẽ khi hover
            on_start_button = true;
        }
        else {
            SDL_RenderCopy(renderer, start_button, NULL, &Blank_button); // Vẽ bình thường
            on_start_button = false;
        }

        if (on_start_button && mouse_down) {
            out = true;   // đánh dấu thoát
        }

        // Hiển thị lên màn hình
        SDL_RenderPresent(renderer);
    }

    // Dọn dẹp
    SDL_DestroyTexture(background);
    SDL_DestroyTexture(start_button);
    SDL_DestroyTexture(start_button_after);

}


