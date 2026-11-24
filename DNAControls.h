#pragma once // Prevents this header file from being included multiple times,
             // with assistance from ChatGPT (OpenAI) - Luis Pineda 11/23/26
#include "raylib.h"

// Interactive controls for the 3D DNA model , with assistance from ChatGPT
// (OpenAI) - Luis Pineda 11/23/26
class DNAControls {
  public:
    bool rotating = true;
    bool paused = false;
    bool showHelp = true;

    float speed = 1.0f;
    float angle = 0.0f;

    void Update();
    void DrawPanel() const;
};
