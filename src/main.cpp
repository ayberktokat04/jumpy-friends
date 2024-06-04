#include <raylib-cpp.hpp>

#include "game.hpp"

int main() {
    // Initialization
    int screenWidth = 800;
    int screenHeight = 450;

    SetRandomSeed(std::time(0));

    Game* game = new Game(screenWidth, screenHeight, "Jumpy Friends");

    game->isHere();

    delete game;

    return 0;
}