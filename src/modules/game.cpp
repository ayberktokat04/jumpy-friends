#include "game.hpp"

Game::Game(int width, int height, std::string title) {
    this->window = new raylib::Window(width, height, title);

    SetTargetFPS(60);

    this->camera.position = (Vector3){-4.0f, 7.50f, -5.0f};
    this->camera.target = (Vector3){0.0f, 0.0f, 2.0f};
    this->camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    this->camera.fovy = 40.0f;
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

    if (IsKeyPressed(KEY_UP))
        this->onKeyPress(KEY_UP);

    if (IsKeyPressed(KEY_LEFT))
        this->onKeyPress(KEY_LEFT);

    if (IsKeyPressed(KEY_RIGHT))
        this->onKeyPress(KEY_RIGHT);

    if (IsKeyPressed(KEY_DOWN))
        this->onKeyPress(KEY_DOWN);
}

void Game::Update(double time, double deltaTime) {
    this->ground.Update();
    this->player.Update();
}

void Game::Display(double time, double deltaTime) {
    BeginDrawing();
    {
        ClearBackground(Color{0, 232, 0, 1});
        BeginMode3D(camera);
        {
            // DrawGrid(40, 0.5f);
            this->ground.Draw();
            this->player.Draw();
        }
        EndMode3D();
    }
    EndDrawing();
}

void Game::onClick(Vector2 position) {
    this->player.JumpForward();
}

void Game::onKeyPress(int key) {
    if (key == KEY_UP) {
        this->player.JumpForward();
        return;
    }

    if (key == KEY_LEFT) {
        this->player.JumpLeft();
        return;
    }

    if (key == KEY_RIGHT) {
        this->player.JumpRight();
        return;
    }

    if (key == KEY_DOWN) {
        this->player.JumpBackward();
        return;
    }
}