#include <iostream>
#include "Music.h"
#include "SDL_include.h"
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER

Mix_Music* music;

Music::Music() {
    music = nullptr;
}

Music::Music(std::string file) {
    Open(file);
}

void Music::Play(int times = -1) {
    if (music == nullptr) {
        SDL_Log("Mix_PlayMusic falhou: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    Mix_PlayMusic(music, times);
}

void Music::Stop(int msToStop = 1500) {
    Mix_FadeOutMusic(msToStop);
}

void Music::Open(std::string file) {
    music = Mix_LoadMUS(file.c_str());
    if (music == nullptr) {
        SDL_Log("Mix_LoadMUS falhou: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }
}

bool Music::IsOpen() {
    if (music != nullptr) {
        return true;
    }
    return false;
}

Music::~Music() {
    if (music != nullptr) {
        Stop();
        Mix_FreeMusic(music);
    }
}


