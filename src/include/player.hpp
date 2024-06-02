#pragma once

#include <iostream>
#include <raylib-cpp.hpp>

class Player {
   private:
    Vector3 position = Vector3{0, 0.25, 0};
    double worldSpeed;
    double jumpSpeed;
    double gravity = -0.01f;
    double zProgress = 0;
    double movement = -1;
    bool jumped = false;
    Model model;
    
    void UpdateY();

   public:
   
    Player();
    Player(double speed);
    void Draw();
    void ImportModel(const std::string& path);
    void Update();
    void Jump();
};