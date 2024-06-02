#include "player.hpp"

Player::Player() {
    this->worldSpeed = 0.02;
}

Player::Player(double worldSpeed) {
    this->worldSpeed = worldSpeed;
}

void Player::ImportModel(const std::string& path, const std::string& texturePath, float scale) {
    Model model = LoadModel(path.c_str());
    model.materials[0].maps[MATERIAL_MAP_DIFFUSE].texture = LoadTexture(texturePath.c_str());
    model.transform = MatrixScale(scale, scale, scale);
    models.push_back(model);
    scales.push_back(scale);
}

void Player::SwitchModel() {
    if (!models.empty()) {
        currentModelIndex = (currentModelIndex + 1) % models.size();  // Switch to the next model
    }
}

void Player::Draw() {
    if (!models.empty()) {
        DrawModel(this->models[currentModelIndex], this->position, 1.0f, WHITE);
    }
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