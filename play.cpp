#include <iostream>

#include "logic.h"
#include "graphics.h"
#include "music.h"
#include "play.h"
#include "EndGame.h"

void runGame(){
    Graphics graphics;
    graphics.initG();

    Music music;
    music.initM();
    music.playMusic();

    Tictactoe game;
    game.init();
    graphics.render(game);

    int x, y;
    SDL_Event event;
    bool run = true;

    while (run) {
        while(SDL_PollEvent(&event)){

            //click vào X thì thoát game
            if(event.type == SDL_QUIT){
                std::cout <<"EXIT\n";
                run = false;
            }

            //bấm nút esc thì sẽ thoát game
            if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) {
                std::cout<<"EXIT\n";
                run = false;
            }

            // bấm r để reset bàn cờ ngay lập tức
            if (event.key.keysym.sym == SDLK_r) {
                std::cout<<"RESET BOARD \n";
                game.init();  // Reset bàn cờ
                graphics.render(game);
            }

            // bấm z để quay lại 1 bước
            if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_z) {
                game.undo();
                graphics.render(game);
            }

            if(event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT){
                SDL_GetMouseState(&x, &y);
                game.processClick(x, y);
                music.playClickSound();
                graphics.render(game);

                if (game.isGameOver()) {
                    music.quitM();
                    int winner = game.getWinner();
                    Endgame(event, run, winner);
                }
            }
        }
        SDL_Delay(10);
    }

    graphics.quitG();
}


