#include <iostream>
#include "raylib.h"
using namespace std;

int main() {

    // left side of dna, radius .25 and 8 makes it an 8 sided cylinder
    DrawCylinderEx(Vector3{2, 1, 0}, Vector3{4, 3, 2}, .25, .25, 8, BLUE);
    DrawCylinderEx(Vector3{4, 3, 2}, Vector3{6, 5, 4}, .25, .25, 8, BLUE);
    DrawCylinderEx(Vector3{6, 5, 4}, Vector3{8, 7, 6}, .25, .25, 8, BLUE);
    //-----------------------------------------------------------------------
    // right side of dna, radius is .25 and 8 makes it an 8 sided cylinder
    DrawCylinderEx(Vector3{-2, 1, 0}, Vector3{-4, 3, -2}, .25, .25, 8, RED);
    DrawCylinderEx(Vector3{-4, 3, -2}, Vector3{-6, 5, -4}, .25, .25, 8, RED);
    DrawCylinderEx(Vector3{-6, 5, -4}, Vector3{-8, 7, -6}, .25, .25, 8, RED);
    // the cylinders that connect the two sides of dna
    // i did ask chat gpt for the x,y,z coords for these connectors given the vectors i came up with in the sides and it suggested these numbers, only the vector coords.
    DrawCylinderEx(Vector3{2, 1, 0}, Vector3{-2, 1, 0}, .10, .10, 8, YELLOW);
    DrawCylinderEx(Vector3{-2, 5, 0}, Vector3{2, 5, 0}, .10, .10, 8, YELLOW);
    DrawCylinderEx(Vector3{2, 9, 0}, Vector3{-2, 9, 0}, .10, .10, 8, YELLOW);

    return 0;
}