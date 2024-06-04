#include "chunkItemMoving.hpp"

Color movingChunkItemColors[2] = {RED, BROWN};

ChunkItemMoving::~ChunkItemMoving() {
    free(this);
}

ChunkItemMoving::ChunkItemMoving(MovingChunkItem type, float speedX, float position) {
    this->type = type;
    this->speedX = speedX;
    this->position = position;
}

void ChunkItemMoving::draw(Vector3 chunkPosition) {
    raylib::Vector3 itemPosition = raylib::Vector3(this->position, chunkPosition.y + 0.1, chunkPosition.z);

    itemPosition.DrawCube(2.0, 1.0, 0.6, movingChunkItemColors[this->type]);
}

void ChunkItemMoving::update() {
    this->position += speedX;
}