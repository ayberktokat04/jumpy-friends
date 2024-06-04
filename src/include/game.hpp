#pragma once
#include <iostream>
#include <raylib-cpp.hpp>

#include "startScreen.hpp"

#include "ground.hpp"
#include "player.hpp"
#include "rlights.h"

#define RENDER_CHUNK_SIZE 30

enum GameState {
    Start,
    Playing,
    Finish
};

class Game {
   private:
    raylib::Window* window;
    // Shader shader = LoadShader("glsl/phong.vs", "glsl/phong.fs");
    // Light light = CreateLight(LIGHT_DIRECTIONAL, (Vector3){2, 2, 1}, Vector3Zero(), YELLOW, shader);
    Camera3D camera;
    double worldSpeed = 0.01;
    GameState gameState = Start;
    Ground ground = Ground(RENDER_CHUNK_SIZE, this->worldSpeed);
    Player player = Player(this->worldSpeed);

    void DisplayStart(double time, double deltaTime);
    void DisplayPlay(double time, double deltaTime);
    void DisplayFinish(double time, double deltaTime);

    void Update(double time, double deltaTime);
    void PollEvents();

    void onClick(Vector2 position);
    void onKeyPress(int key);

   public:
    Game(int, int, std::string);
    void isHere();
    
};