#include "DNAControls.h"
#include "raylib.h"

void DNAControls::Update() {
    // Press R to turn rotation on or off
    if (IsKeyPressed(KEY_R)) {
        rotating = !rotating;
    }

    // Press SPACE to pause or resume
    if (IsKeyPressed(KEY_SPACE)) {
        paused = !paused;
    }

    // Increase animation speed
    if (IsKeyPressed(KEY_UP)) {
        if (speed < 3.0f) {
            speed += 0.5f;
        }
    }

    // Decrease animation speed
    if (IsKeyPressed(KEY_DOWN)) {
        if (speed > 0.5f) {
            speed -= 0.5f;
        }
    }

    // Show or hide instructions
    if (IsKeyPressed(KEY_H)) {
        showHelp = !showHelp;
    }

    // Update rotation animation
    if (rotating && !paused) {
        angle += GetFrameTime() * speed;
    }
}

void DNAControls::DrawPanel() const {
    if (!showHelp)
        return;

    int k = 80;
    DrawRectangle(10, 110 + k, 320, 150, Fade(LIGHTGRAY, 0.9f));
    DrawRectangleLines(10, 110 + k, 320, 150, GRAY);

    DrawText("DNA INTERACTIVE CONTROLS", 20, 120 + k, 18, BLACK);

    DrawText("R - Start/Stop Rotation", 20, 150 + k, 16, DARKGRAY);

    DrawText("SPACE - Pause/Resume", 20, 175 + k, 16, DARKGRAY);

    DrawText("UP/DOWN - Change Speed", 20, 200 + k, 16, DARKGRAY);

    DrawText("H - Hide/Show Controls", 20, 225 + k, 16, DARKGRAY);
}