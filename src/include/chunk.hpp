#pragma once

#include <iostream>
#include <raylib-cpp.hpp>

enum ChunkType {
    FreeWalk,
    RoadBegin,
    Road,
    RoadEnd,
    RiverBegin,
    River,
    RiverEnd,
};

enum ChunkState {
    Spawning,
    Despawning,
    JustExisting
};

struct Chunk {
    ChunkType type;
    raylib::Vector3 position;
    ChunkState state;

    Chunk() {
        this->type = FreeWalk;
        this->state = JustExisting;
        this->position = Vector3{0, 0, 0};
    }

    Chunk(ChunkType type, ChunkState state, raylib::Vector3 position = {0, 0, 0}) {
        this->type = type;
        this->state = state;
        this->position = position;
    }

    void Despawn();
    void Spawn();
    void Update();
    void Draw();
    void setPosition(raylib::Vector3);
};
