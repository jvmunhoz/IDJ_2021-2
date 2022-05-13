#include <string>
#include <iostream>
#include "Game.h"
#include "SDL_include.h"
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER

Game *Game::instance = nullptr;

Game::Game (std::string title, int width, int height) {

    if (Game::instance != nullptr) {
        exit(EXIT_FAILURE);
    } else {
        Game::instance = this;
    }

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0) {
        SDL_Log("SDL_Init falhou: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF) == 0) {
        SDL_Log("IMG_Init falhou: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    if (Mix_Init(MIX_INIT_FLAC | MIX_INIT_MP3 | MIX_INIT_OGG | MIX_INIT_MOD | MIX_INIT_MID) == 0) {
        SDL_Log("Mix_Init falhou: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) != 0) {
        SDL_Log("Mix_OpenAudio falhou: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    Mix_AllocateChannels(32);

    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);

    if (window == nullptr) {
        SDL_Log("Window falhou: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (renderer == nullptr) {
        SDL_Log("Renderer falhou: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    state = new State();
}

Game::~Game() {
    delete Game::state;
    Mix_CloseAudio();
    Mix_Quit();
    IMG_Quit();
    SDL_DestroyWindow(Game::window);
    SDL_DestroyRenderer(Game::renderer);
    SDL_Quit();
}

State& Game::GetState() {
    return *state;
}

SDL_Renderer* Game::GetRenderer() {
    return renderer;
}

void Game::Run() {
    while (state->QuitRequested()!=true) {
        GetInstance().state->Update();
        GetInstance().state->Render();
        SDL_RenderPresent(Game::GetInstance().GetRenderer());
        SDL_Delay(33);
    }
}

Game& Game::GetInstance() {
    if (Game::instance != nullptr) {
        return *instance;;
    } else {
        Game::instance = new Game("João Victor Bohrer Munhoz - 16/0071101", 1024, 600);
    }
    return *instance;
}