#include "raylib.h"
#include <iostream>
using namespace std;

int main(void) {
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "3D DNA Demo");
    ToggleBorderlessWindowed();

    // Define the camera to look into our 3d world
    Camera3D camera = {0};
    camera.position = (Vector3){10.0f, 10.0f, 10.0f}; // Camera position
    camera.target = (Vector3){0.0f, 0.0f, 0.0f};      // Camera looking at point
    camera.up = (Vector3){0.0f, 1.0f,
                          0.0f}; // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;         // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE; // Camera projection type

    Vector3 cubePosition = {0.0f, 0.0f, 0.0f};

    DisableCursor(); // Limit cursor to relative movement inside the window

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        UpdateCamera(&camera, CAMERA_FREE);

        if (IsKeyPressed(KEY_Z))
            camera.target = (Vector3){0.0f, 5.0f, 0.0f};
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        // left side of dna, radius .25 and 8 makes it an 8 sided cylinder
        DrawCylinderEx(Vector3{2, 1, 0}, Vector3{4, 3, 2}, .25, .25, 8, BLUE);
        DrawCylinderEx(Vector3{4, 3, 2}, Vector3{6, 5, 4}, .25, .25, 8, BLUE);
        DrawCylinderEx(Vector3{6, 5, 4}, Vector3{8, 7, 6}, .25, .25, 8, BLUE);
        //-----------------------------------------------------------------------
        // right side of dna, radius is .25 and 8 makes it an 8 sided cylinder
        DrawCylinderEx(Vector3{-2, 1, 0}, Vector3{-4, 3, -2}, .25, .25, 8, RED);
        DrawCylinderEx(Vector3{-4, 3, -2}, Vector3{-6, 5, -4}, .25, .25, 8,
                       RED);
        DrawCylinderEx(Vector3{-6, 5, -4}, Vector3{-8, 7, -6}, .25, .25, 8,
                       RED);
        // the cylinders that connect the two sides of dna
        // i did ask chat gpt for the x,y,z coords for these connectors given
        // the vectors i came up with in the sides and it suggested these
        // numbers, only the vector coords.
        DrawCylinderEx(Vector3{2, 1, 0}, Vector3{-2, 1, 0}, .10, .10, 8,
                       YELLOW);
        DrawCylinderEx(Vector3{-2, 5, 0}, Vector3{2, 5, 0}, .10, .10, 8,
                       YELLOW);
        DrawCylinderEx(Vector3{2, 9, 0}, Vector3{-2, 9, 0}, .10, .10, 8,
                       YELLOW);

        DrawGrid(10, 1.0f);

        EndMode3D();

        DrawRectangle(10, 10, 320, 93, Fade(SKYBLUE, 0.5f));
        DrawRectangleLines(10, 10, 320, 93, BLUE);

        DrawText("Free camera default controls:", 20, 20, 10, BLACK);
        DrawText("- Mouse Wheel to Zoom in-out", 40, 40, 10, DARKGRAY);
        DrawText("- Mouse Wheel Pressed to Pan", 40, 60, 10, DARKGRAY);
        DrawText("- Z to zoom to (0, 5, 0)", 40, 80, 10, DARKGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
