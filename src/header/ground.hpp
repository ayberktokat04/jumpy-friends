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

    void SetupGround(int chunkCount);

   public:
    Ground(int chunkCount = 10);
    void Step();
    void Update();
    void Draw();
    void PrintChunks();
};