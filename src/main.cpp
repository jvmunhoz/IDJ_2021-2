#include "Game.h"
#include "SDL_include.h"
#define INCLUDE_SDL_IMAGE
#define INCLUDE_SDL_MIXER

int main(int argc, char** argv) {

    Game& game = Game::GetInstance();
    game.Run();

    return 0;
}
