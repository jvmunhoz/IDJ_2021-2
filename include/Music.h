#ifndef IDJ_MUSIC_H
#define IDJ_MUSIC_H

#include <iostream>
#include "SDL_include.h"
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER

class Music {
public:
    Music();
    Music(std::string file);
    void Play(int times);
    void Stop(int msToStop);
    void Open(std::string file);
    bool IsOpen();
    ~Music();
};

#endif //IDJ_MUSIC_H
