#ifndef IDJ_GAME_H
#define IDJ_GAME_H

#include <string>
#include <iostream>
#include "SDL_include.h"
#include "State.h"
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER

class Game {
public:
    ~Game();
    void Run();
    SDL_Renderer* GetRenderer();
    State& GetState();
    static Game& GetInstance();

private:
    static Game* instance;
    Game(std::string title, int width, int height);
    SDL_Window* window;
    SDL_Renderer* renderer;
    State* state;
};



#endif //IDJ_GAME_H
