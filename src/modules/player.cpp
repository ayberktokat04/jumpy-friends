#include "player.hpp"

Player::Player(double worldSpeed) {
    this->worldSpeed = worldSpeed;
}

void Player::Draw() {
    DrawSphere(this->position, 0.15, RED);
}

void Player::Update() {
    // Add world movement
    this->position.z -= this->worldSpeed;

    if (this->jumpType == JumpType::None) return;

    if (this->position.y < 0.25) {
        this->position.y = 0.25;
        this->jumpType = JumpType::None;
        return;
    }

    if (this->jumpType == JumpType::Forward)
        this->position.z += 0.5f / (JUMP_SPEED / abs(gravity));
    else if (this->jumpType == JumpType::Left)
        this->position.x += 0.5f / (JUMP_SPEED / abs(gravity));
    else if (this->jumpType == JumpType::Right)
        this->position.x -= 0.5f / (JUMP_SPEED / abs(gravity));
    else if (this->jumpType == JumpType::Backward)
        this->position.z -= 0.5f / (JUMP_SPEED / abs(gravity));

    this->currentSpeed += gravity;
    this->position.y += currentSpeed;
}

void Player::JumpForward() {
    if (this->jumpType != JumpType::None) return;

    this->currentSpeed = JUMP_SPEED;
    this->jumpType = JumpType::Forward;
}

void Player::JumpLeft() {
    if (this->jumpType != JumpType::None) return;

    this->currentSpeed = JUMP_SPEED;
    this->jumpType = JumpType::Left;
}

void Player::JumpRight() {
    if (this->jumpType != JumpType::None) return;

    this->currentSpeed = JUMP_SPEED;
    this->jumpType = JumpType::Right;
}

void Player::JumpBackward() {
    if (this->jumpType != JumpType::None) return;

    this->currentSpeed = JUMP_SPEED;
    this->jumpType = JumpType::Backward;
}

BoundingBox Player::GetBoundingBox() const {
    Vector3 min = { this->position.x - 0.15f, this->position.y - 0.15f, this->position.z - 0.15f };
    Vector3 max = { this->position.x + 0.15f, this->position.y + 0.15f, this->position.z + 0.15f };
    return BoundingBox{ min, max };
}