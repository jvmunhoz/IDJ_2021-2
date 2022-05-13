#ifndef IDJ_SPRITE_H
#define IDJ_SPRITE_H

#include <iostream>
#include "SDL_include.h"
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER

class Sprite {
public:
    Sprite();
    Sprite(std::string file);
    ~Sprite();
    void Open(std::string file);
    void SetClip(int x, int y, int w, int h);
    void Render(int x, int y);
    int GetWidth();
    int GetHeight();
    bool IsOpen();

private:
    int width;
    int height;
};

#endif //IDJ_SPRITE_H
