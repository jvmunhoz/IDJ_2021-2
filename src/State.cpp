#include <string>
#include <iostream>
#include "State.h"
#include "SDL_include.h"
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER

State::State() {
    quitRequested = false;
    LoadAssets();
    music.Play(-1);
}

void State::LoadAssets() {
    bg.Open("assets/img/ocean.jpg");
    music.Open("assets/audio/stageState.ogg");
}

void State::Update() {
    if (SDL_QuitRequested()) {
        quitRequested = true;
    }
}

void State::Render() {
    bg.Render(0, 0);
}

bool State::QuitRequested() {
    return quitRequested;
}



