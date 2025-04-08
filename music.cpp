#include <iostream>

#include "music.h"
#include "logic.h"

Tictactoe game;

void Music::initM(){
    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 ) {
        std::cout<<"SDL_mixer could not initialize! SDL_mixer Error: %s\n"<<Mix_GetError();
    }

    gMusic = Mix_LoadMUS("sound/backgroundMusic.mp3");
    gChunk = Mix_LoadWAV("sound/click.wav");
}

void Music::playMusic()
{
    if (gMusic == nullptr) return;

    if (Mix_PlayingMusic() == 0) {
        Mix_PlayMusic( gMusic, -1 );
    }
    else if( Mix_PausedMusic() == 1 ) {
        Mix_ResumeMusic();
    }
}


void Music::playClickSound() {
    if (gChunk != nullptr) {
        Mix_PlayChannel( -1, gChunk, 0 );
    }
}

void Music::quitM(){
    if (gMusic != nullptr) Mix_FreeMusic( gMusic );
    if (gChunk != nullptr) Mix_FreeChunk( gChunk);
}


