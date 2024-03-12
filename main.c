#include <stdio.h>
#include <math.h>
#include "raylib.h"
#include "includes/character.h"
#include "includes/character.c"
#include "includes/fase1.h"
#include "includes/fase1.c"
#include "includes/fase2.h"
#include "includes/fase2.c"
#include "includes/enemy1.c"
#include "includes/enemy2.cpp"
#include "includes/enemy2.h"
#include "includes/menu.h"
#include "includes/menu.c"
#include "includes/transition.h"
#include "includes/transition.c"

int main()
{

    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 1000;
    int screenHeight = 736;
    int button = 0;
    int colidiu1 = 0, colidiu2 = 0;
    bool WindowFullscreen = IsWindowFullscreen();

    InitWindow(screenWidth, screenHeight, "Al Sem Ammy");

    fase1_init();
    fase2_init();
    character_init();
    enemy1_init();
    enemy2_init();
    // fimdejogo();
    DefineThings();

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    // Main game loop
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {

        if (IsKeyPressed(KEY_F) && !WindowFullscreen)
        {
            ToggleFullscreen();
        }

        if (IsKeyPressed(KEY_F) && WindowFullscreen)
        {
            ToggleBorderlessWindowed();
        }
        if (button == 0 || button == 2 || button == 3)
            choose_button(&button);
        if (button == 1)
        {
            camera_settings(&screenWidth, &screenHeight, transition(&playerhitbox, &posicao, &jumptimer));
            character_movement();
            enemy1_movement();
            enemy2_movement(posicao.x, posicao.y);
        }
        if (button == 4)
        {
            choose_buttonover(&button);
        }
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(RAYWHITE);
        if (button == 0 || button == 2 || button == 3)
            DrawThings(&button);
        if (button == 4)
        {
            DrawThingsover(&button);
        }
        if (button == 1)
        {
            BeginMode2D(camera);

            if (transition(&playerhitbox, &posicao, &jumptimer) == 1)
            {
                draw_fase1();
                draw_enemy1_map1();
                draw_enemy2_map1();
                // colidiu1 = colisaoinimigosfase1();
                if (colidiu1 == 1)
                {
                    button = 4;
                }
            }
            if (transition(&playerhitbox, &posicao, &jumptimer) == 2)
            {
                draw_fase2();
                draw_enemy1_map2();
                draw_enemy2_map2();
                colisaoinimigosfase2();
                colidiu2 = colisaoinimigosfase2();
                if (colidiu2 == 1)
                {
                    button = 4;
                }
            }
            draw_character();
            EndMode2D();
        }

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // FALTA DESCARREGAR OUTRAS TEXTURAS
    unload_charactertex();
    unload_enemy1_tex();
    unload_enemy2_tex();
    //----------------------------------------------------------------------------------
    CloseWindow(); // Close window and OpenGL context
                   //--------------------------------------------------------------------------------------
    return 0;
}
