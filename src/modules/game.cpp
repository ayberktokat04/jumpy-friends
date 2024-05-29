#include "game.hpp"

Game::Game(int width, int height, std::string title) {
    this->window = new raylib::Window(width, height, title);
    SetTargetFPS(60);

    this->camera.position = (Vector3){-10.0f, 10.0f, -10.0f};
    this->camera.target = (Vector3){0.0f, 0.0f, 0.0f};
    this->camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    this->camera.fovy = 60.0f;
    this->camera.projection = CAMERA_PERSPECTIVE;
}

void Game::Start() {
    while (!this->window->ShouldClose()) {
        double time = GetTime();
        double deltaTime = GetFrameTime();
        this->PollEvents();
        this->Update(time, deltaTime);
        this->Display(time, deltaTime);
    }
}

void Game::PollEvents() {
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        this->onClick(GetMousePosition());
}

void Game::Update(double time, double deltaTime) {
    this->ground.Update();
}

void Game::Display(double time, double deltaTime) {
    BeginDrawing();
    {
        ClearBackground(RAYWHITE);
        BeginMode3D(camera);
        {
            DrawGrid(40, 0.5f);
            this->ground.Draw();
        }
        EndMode3D();
    }
    EndDrawing();
}

void Game::onClick(Vector2 position) {
    this->ground.Step();
}