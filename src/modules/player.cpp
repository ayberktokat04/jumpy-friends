#include "player.hpp"

Player::Player() {
    this->worldSpeed = 0.02;
}

Player::Player(double worldSpeed) {
    this->worldSpeed = worldSpeed;
}

void Player::ImportModel(const std::string& path) {
    this->model = LoadModel(path.c_str());
    this->model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = LoadTexture("src/models/OBJ/plane_diffuse.png");
    this->model.transform = MatrixScale(0.015, 0.015, 0.015);
}

void Player::Draw() {
    DrawModel(this->model, this->position, 1.0f, WHITE);
}

void Player::Update() {
    // Add world movement
    this->position.z -= this->worldSpeed;
    zProgress -= this->worldSpeed;

    if (this->movement > 0.95) {
        movement = -1;
        zProgress += 1;
        this->position.z = zProgress;

    } else if (this->movement >= 0) {
        this->position.z += (1 - movement) * 0.15;
        movement += (1 - movement) * 0.15;
    }

    if (!this->jumped) return;

    if (this->position.y < 0.25) {
        this->position.y = 0.25;
        this->jumpSpeed = 0;
        this->jumped = false;
        return;
    }

    this->jumpSpeed += gravity;
    this->position.y += jumpSpeed;
}

void Player::Jump() {
    if (!this->jumped) {
        this->jumpSpeed += 0.1;
        this->jumped = true;
        this->movement = 0;
    }
}