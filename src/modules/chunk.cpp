#include "chunk.hpp"

std::ostream& operator<<(std::ostream& os, const Chunk& chunk) {
    return os << "ChunkType: " << chunk.type << std::endl;
}

void Chunk::Draw() {
    Color chunkColors[] = {
        GREEN,
        GRAY,
        DARKGRAY,
        GRAY,
        PURPLE,
        BLUE,
        PURPLE};

    this->position.DrawPlane({30, 1}, chunkColors[this->type]);
}

void Chunk::Update(double speed) {
    this->position.z -= speed;
}

void Chunk::Despawn() {}

void Chunk::setPosition(raylib::Vector3 position) {
    this->position = position;
}