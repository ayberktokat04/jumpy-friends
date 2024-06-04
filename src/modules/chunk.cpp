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

    if (this->type == Road || this->type == River) {
        for (int d = 0; d < this->movingItemsNum; d++) {
            int idx = (startIdx + d) % this->movingItemCapacity;
            this->movingItems[idx]->draw(this->position);
        }
    }
}

void Chunk::Update(double speed) {
    this->generateMovingChunkItem();

    this->position.z -= speed;
    if (this->type == Road || this->type == River) {
        for (int d = 0; d < this->movingItemsNum; d++) {
            int idx = (startIdx + d) % this->movingItemCapacity;
            this->movingItems[idx]->update();
        }
    }
}

void Chunk::Despawn() {}

void Chunk::setPosition(raylib::Vector3 position) {
    this->position = position;
}

void Chunk::generateMovingChunkItem() {
    // the list is full
    if (this->movingItemCapacity == this->movingItemsNum) return;
    MovingChunkItem type = Car;

    if (this->type == River) {
        type = Surfboard;
    }

    this->movingItems[endIdx] = new ChunkItemMoving(type, 0.01, -6.0 + (this->movingItemsNum * 4.0));
    endIdx = (endIdx + 1) % this->movingItemCapacity;
    this->movingItemsNum += 1;
}
