#pragma once

#include <iostream>
#include <raylib-cpp.hpp>

#define JUMP_SPEED 0.1

enum JumpType {
    Forward,
    Left,
    Right,
    Backward,
    None
};

class Player {
   private:
    raylib::Material material;
    Vector3 position = Vector3{0, 0.25, 0};
    double worldSpeed;
    double currentSpeed;
    double gravity = -0.02f;
    double movement = -1;
    JumpType jumpType = JumpType::None;

   public:
    Player(double speed);
    void Draw();
    void Update();
    void JumpForward();
    void JumpLeft();
    void JumpRight();
    void JumpBackward();
    BoundingBox GetBoundingBox() const;
};