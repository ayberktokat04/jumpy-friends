#pragma once
#include <iostream>
#include <raylib-cpp.hpp>

#include "ground.hpp"
#include "player.hpp"

enum GameState {
    Start,
    Playing,
    Finish
};

class Game {
   private:
    raylib::Window* window;
    Camera3D camera;
    double worldSpeed = 0.02;
    Ground ground;
    Player player;

    void Display(double time, double deltaTime);
    void Update(double time, double deltaTime);
    void PollEvents();

    void onClick(Vector2 position);

   public:
    Game(int, int, std::string);
    void Start();
};