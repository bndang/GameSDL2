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
            if(event.type == SDL_QUIT){
                run = false;
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


