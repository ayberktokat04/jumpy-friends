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

    this->position.DrawPlane({12, 1}, chunkColors[this->type]);
}

void Chunk::Update() {
    this->position.z -= 0.05;
}

void Chunk::Despawn() {}

void Chunk::setPosition(raylib::Vector3 position) {
    this->position = position;
}