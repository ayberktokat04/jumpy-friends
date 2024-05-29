#pragma once
#include <iostream>
#include <raylib-cpp.hpp>

#include "ground.hpp"

class Game {
   private:
    raylib::Window* window;
    Camera3D camera;
    Ground ground = Ground(20);

    void Display(double time, double deltaTime);
    void Update(double time, double deltaTime);
    void PollEvents();

    void onClick(Vector2 position);

   public:
    Game(int, int, std::string);
    void Start();
};