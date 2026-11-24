#include "raylib.h"
#include <iostream>
#include <vector>
#include <math.h> //this was needed for the calculation for the displacement for x and z (cos and sin), also from Claude - Hao Yu 11/19/26
#include "DNAControls.h" // Used to add interactive keyboard controls for rotation, pausing, and speed adjustment, with assistance from ChatGPT (OpenAI) - Luis Pineda 11/23/26
using namespace std;

int main(void)
{
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
                          0.0f};            // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                    // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE; // Camera projection type

    Vector3 cubePosition = {0.0f, 0.0f, 0.0f};

    DisableCursor(); // Limit cursor to relative movement inside the window

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    DNAControls controls; // (Luis)

    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        controls.Update(); // (Luis)
        //----------------------------------------------------------------------------------
        UpdateCamera(&camera, CAMERA_FREE);

        if (IsKeyPressed(KEY_Z))
            camera.target = (Vector3){0.0f, 25.0f, 0.0f};
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        BeginMode3D(camera);

        /* the cylinders that connect the two sides of dna
        i did ask chat gpt for the x,y,z coords for these connectors given
        the vectors i came up with in the sides and it suggested these
        numbers, only the vector coords. -Uziel C */

        /* I figured we should do a for loop since it will be slowly twisting as it goes up.
        I asked Claude for how I can calculate the displacement for x and z coordinates based on i. - Hao Yu 11/19/26*/
        int i;
        vector<Color> Lcolors = {GREEN, RED, BLUE};
        vector<Color> Scolors = {RED, BLACK};
        const float degPerRung = 100.0f;                     // the degree that each segments rotate after each other
        const int rungEvery = 6;                             // strand segments per rung
        const float step = degPerRung * DEG2RAD / rungEvery; // radians per segment
        int steps = 50;
        for (i = 0; i < steps; ++i)
        {
            int r = 2; // Radius, adjusts the length of the segments
            float j = i * step + controls.angle; // (Luis)
            float x1 = 2 + r * cos(j);  // x-coordinate of first end
            float x2 = -2 - r * cos(j); // x-coordinate of other end
            float z1 = 0 + r * sin(j);  // same with z
            float z2 = 0 - r * sin(j);
            float y = 1 + i;
            float sph_size = 0.5;
            DrawCylinderEx(Vector3{x1, y, z1}, Vector3{x2, y, z2}, .10, .10, 8, Lcolors.at(i % 3));
            DrawSphere(Vector3{x1, y, z1}, sph_size, Scolors.at(i % 2));
            DrawSphere(Vector3{x2, y, z2}, sph_size, Scolors.at(i % 2));
        }

        DrawGrid(10, 1.0f);

        EndMode3D();
        controls.DrawPanel(); // (Luis)

        DrawRectangle(10, 10, 320, 93, Fade(SKYBLUE, 0.5f));
        DrawRectangleLines(10, 10, 320, 93, BLUE);

        DrawText("Free camera default controls:", 20, 20, 10, BLACK);
        DrawText("- Mouse Wheel to Zoom in-out", 40, 40, 10, DARKGRAY);
        DrawText("- Mouse Wheel Pressed to Pan", 40, 60, 10, DARKGRAY);
        DrawText("- Z to zoom to (0, 25, 0)", 40, 80, 10, DARKGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
