#include "Sprite.h"
#include "Game.h"
#include "SDL_include.h"
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER

SDL_Texture* texture;
SDL_Rect clipRect;

Sprite::Sprite() {
    texture = nullptr;
    width = 0;
    height = 0;
}

Sprite::Sprite(std::string file) {
    texture = nullptr;
    Open(file);
}

Sprite::~Sprite(){
    if (texture != nullptr) {
        SDL_DestroyTexture(texture);
    };
}

void Sprite::Open(std::string file) {
    if (texture != nullptr) {
        SDL_DestroyTexture(texture);
    }

    texture = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());
    if (texture == nullptr) {
        SDL_Log("IMG_LoadTexture falhou: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);

    SetClip(0, 0, width, height);
}

void Sprite::SetClip(int x, int y, int w, int h) {
    clipRect.x = x;
    clipRect.y = y;
    clipRect.w = w;
    clipRect.h = h;
}

void Sprite::Render(int x, int y) {
    SDL_Rect dstRect;
    dstRect.x = x;
    dstRect.y = y;
    dstRect.w = GetWidth();
    dstRect.h = GetHeight();

    if (SDL_RenderCopy(Game::GetInstance().GetRenderer(), texture, &clipRect, &dstRect) != 0) {
        SDL_Log("SDL_RenderCopy falhou: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }
}

int Sprite::GetWidth() {
    return width;
}

int Sprite::GetHeight() {
    return height;
}

bool Sprite::IsOpen() {
    if (texture != nullptr) {
        return true;
    }
    return false;
}
