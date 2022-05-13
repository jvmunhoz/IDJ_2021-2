#ifndef IDJ_STATE_H
#define IDJ_STATE_H

#include "Sprite.h"
#include "Music.h"
#include "SDL_include.h"
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER

class State {
public:
    State();
    bool QuitRequested();
    void LoadAssets();
    void Update();
    void Render();

private:
    Sprite bg;
    Music music;
    bool quitRequested;
};

#endif //IDJ_STATE_H
