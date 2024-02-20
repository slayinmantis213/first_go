/*******************************************************************************************
 *
 *   raylib [core] example - Basic window
 *
 *   Welcome to raylib!
 *
 *   To test examples, just press F6 and execute raylib_compile_execute script
 *   Note that compiled executable is placed in the same folder as .c file
 *
 *   You can find all basic examples on C:\raylib\raylib\examples folder or
 *   raylib official webpage: www.raylib.com
 *
 *   Enjoy using raylib. :)
 *
 *   Example originally created with raylib 1.0, last time updated with raylib 1.0
 *
 *   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
 *   BSD-like license that allows static linking with closed source software
 *
 *   Copyright (c) 2013-2024 Ramon Santamaria (@raysan5)
 *
 ********************************************************************************************/

#include "include/raylib.h"
#include "stdio.h"
#include "string.h"

#define MAX_KEY_LENGTH 15
//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1600;
    const int screenHeight = 900;

    // const int monitor = GetCurrentMonitor();
    // const int height = GetMonitorHeight(monitor);

    // printf("Monitor : %d\n", monitor);
    // printf("Monitor : %d\n", height);
    InitWindow(screenWidth, screenHeight, "MY FIRST GAME");

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    char pref[] = "Current Key :";
    bool started = false;
    char key[MAX_KEY_LENGTH] = "";
        // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        int keycode = GetKeyPressed();
        //----------------------------------------------------------------------------------
        if(keycode > 0)
        {   
            snprintf(key, MAX_KEY_LENGTH, "%d", keycode);
        }
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
            ClearBackground(BLACK);
            if (!started && IsKeyDown(32))
            {
                started = true;
            }
            if (!started)
            {
                DrawText("face your fears", 400, 400, 100, GREEN);
                DrawText("press space to begin", 750, 550, 20, GREEN);
            }
            else
            {
                DrawText("become nightmare", 400, 400, 100, GREEN);
                DrawText(pref, 500, 550, 50, GREEN);
                DrawText(key, 930, 550, 50, GREEN);
            }
        EndDrawing();
        //----------------------------------------------------------------------------------
    }
    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
    return 0;
}