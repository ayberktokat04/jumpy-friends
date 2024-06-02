#include "game.hpp"
#include "player.hpp"
Game::Game(int width, int height, std::string title) {
    this->window = new raylib::Window(width, height, title);
    
    this->player.ImportModel("src/models/OBJ/plane.obj", "src/models/OBJ/plane_diffuse.png", 0.015f);
    this->player.ImportModel("src/models/OBJ/castle.obj", "src/models/OBJ/castle_diffuse.png", 0.020f);
    this->player.ImportModel("src/models/OBJ/well.obj", "src/models/OBJ/well_diffuse.png", 0.12f);
    this->player.ImportModel("src/models/OBJ/turret.obj", "src/models/OBJ/turret_diffuse.png", 0.06f);

    SetTargetFPS(60);

    this->camera.position = (Vector3){-4.0f, 7.50f, -5.0f};
    this->camera.target = (Vector3){0.0f, 0.0f, 2.0f};
    this->camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    this->camera.fovy = 40.0f;
    this->camera.projection = CAMERA_PERSPECTIVE;

    // this->shader.locs[SHADER_LOC_VECTOR_VIEW] = GetShaderLocation(shader, "viewPos");

    // float cameraPos[3] = {camera.position.x, camera.position.y, camera.position.z};
    // SetShaderValue(shader, shader.locs[SHADER_LOC_VECTOR_VIEW], cameraPos, SHADER_UNIFORM_VEC3);
}

void Game::Start() {
    while (!this->window->ShouldClose()) {
        double time = GetTime();
        double deltaTime = GetFrameTime();
        this->PollEvents();
        this->Update(time, deltaTime);
        // UpdateLightValues(shader, light);
        this->Display(time, deltaTime);
    }
}

void Game::PollEvents() {
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        this->onClick(GetMousePosition());

    if (IsKeyPressed(KEY_UP))
        this->onKeyPress(KEY_UP);

    if (IsKeyPressed(KEY_S))
        this->player.SwitchModel();
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
    this->player.Jump();
}

void Game::onKeyPress(int key) {
    if (key == KEY_UP)
        this->player.Jump();
}