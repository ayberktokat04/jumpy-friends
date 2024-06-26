#pragma once

#include <iostream>
#include <raylib-cpp.hpp>
#include <vector>

#include "chunk.hpp"
#include "utils.hpp"

class Ground {
   private:
    std::vector<Chunk> chunks;
    Chunk collapseNextChunk(Chunk previousChunk);
    Chunk getLastChunk();
    double worldSpeed;

    void SetupGround(int chunkCount);

   public:
    Ground(int chunkCount = 10, double worldSpeed = 0.02);
    void Step();
    void Update();
    void Draw();
    void PrintChunks();

    const std::vector<Chunk>& getChunks() const;
};