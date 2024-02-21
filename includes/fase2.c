#include "raylib.h"
#include <stdio.h>
#include "structs.h"
#include "fase1.h"
#include "defs.h"
#include "colisao.c"

void jogo_fase2()
{
    Bola bola = {.x = 0,
                 .y = 100,
                 .size = 10.0,
                 .velocidadeY = 0,
                 .noChao = 0};

    Camera2D camera = {0};
    camera.target = (Vector2){largura_tela / 2.0f, altura_tela / 2.0f};
    camera.offset = (Vector2){largura_tela / 2.0f, altura_tela / 2.0f};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
    SetTargetFPS(60);
    Texture2D backtext2 = LoadTexture("assets/mapajogoplat.png");
    const int largura_background = backtext2.width;
    const int altura_background = backtext2.height;
    fase fase1;
    fase1.plataformas[0].x = 0;
    fase1.plataformas[0].y = 14 + 21 * 32;
    fase1.plataformas[0].largura = 9 * 32;
    fase1.plataformas[0].altura = 32;

    fase1.plataformas[1].x = 9 * 32;
    fase1.plataformas[1].y = 14 + 18 * 32;
    fase1.plataformas[1].largura = 9 * 32;
    fase1.plataformas[1].altura = 32;

    fase1.plataformas[2].x = 18 * 32;
    fase1.plataformas[2].y = 14 + 11 * 32;
    fase1.plataformas[2].largura = 8 * 32;
    fase1.plataformas[2].altura = 32;

    fase1.plataformas[3].x = 27 * 32;
    fase1.plataformas[3].y = 14 + 7 * 32;
    fase1.plataformas[3].largura = 14 * 32;
    fase1.plataformas[3].altura = 32;

    fase1.plataformas[4].x = 40 * 32;
    fase1.plataformas[4].y = 14 + 18 * 32;
    fase1.plataformas[4].largura = 11 * 32;
    fase1.plataformas[4].altura = 32;

    fase1.plataformas[5].x = 51 * 32;
    fase1.plataformas[5].y = 14 + 15 * 32;
    fase1.plataformas[5].largura = 5 * 32;
    fase1.plataformas[5].altura = 32;

    fase1.plataformas[6].x = 56 * 32;
    fase1.plataformas[6].y = 14 + 12 * 32;
    fase1.plataformas[6].largura = 5 * 32;
    fase1.plataformas[6].altura = 32;

    fase1.plataformas[7].x = 51 * 32;
    fase1.plataformas[7].y = 14 + 9 * 32;
    fase1.plataformas[7].largura = 5 * 32;
    fase1.plataformas[7].altura = 32;

    fase1.plataformas[8].x = 56 * 32;
    fase1.plataformas[8].y = 14 + 5 * 32;
    fase1.plataformas[8].largura = 19 * 32;
    fase1.plataformas[8].altura = 32;

    fase1.plataformas[9].x = 74 * 32;
    fase1.plataformas[9].y = 14 + 9 * 32;
    fase1.plataformas[9].largura = 6 * 32;
    fase1.plataformas[9].altura = 32;

    fase1.plataformas[10].x = 68 * 32;
    fase1.plataformas[10].y = 14 + 13 * 32;
    fase1.plataformas[10].largura = 7 * 32;
    fase1.plataformas[10].altura = 32;

    fase1.plataformas[11].x = 74 * 32;
    fase1.plataformas[11].y = 14 + 17 * 32;
    fase1.plataformas[11].largura = 6 * 32;
    fase1.plataformas[11].altura = 32;

    fase1.plataformas[12].x = 66 * 32;
    fase1.plataformas[12].y = 14 + 21 * 32;
    fase1.plataformas[12].largura = 14 * 32;
    fase1.plataformas[12].altura = 32;

    while (!WindowShouldClose())
    {
        int plat_atual = bola_na_plat(bola, fase1.plataformas, 2);
        if (plat_atual != -1)
        {
            if (bola.velocidadeY > 0)
            {
                bola.y = fase1.plataformas[plat_atual].y - bola.size;
                bola.velocidadeY = 0;
                bola.noChao = 1;
            }

            // Salto quando pressiona a barra de espaço
            if (IsKeyPressed(KEY_SPACE))
            {
                bola.velocidadeY = -17;
                bola.noChao = 0;
            }
        }
        else
        {
            if (bola.velocidadeY <= 15)
            {
                bola.velocidadeY += 1; // Gravidade simulada
            }
            else
            {
                bola.velocidadeY = 15;
            }
            bola.noChao = 0;
        }

        if (IsKeyDown(KEY_A))
        {
            bola.x -= 5;
        }

        if (IsKeyDown(KEY_D))
        {
            bola.x += 5;
        }

        bola.y += bola.velocidadeY;

        // Ajustar a posição da câmera para seguir a bola mantendo-a totalmente visível
        camera.target.x = bola.x;
        camera.target.y = bola.y;

        // Restringir a posição da câmera dentro dos limites do background
        if (camera.target.x < largura_tela / 2.0f)
            camera.target.x = largura_tela / 2.0f;
        if (camera.target.x > largura_background - largura_tela / 2.0f)
            camera.target.x = largura_background - largura_tela / 2.0f;
        if (camera.target.y < altura_tela / 2.0f)
            camera.target.y = altura_tela / 2.0f;
        if (camera.target.y > altura_background - altura_tela / 2.0f)
            camera.target.y = altura_background - altura_tela / 2.0f;

        BeginDrawing();

        BeginMode2D(camera);

        DrawTexture(backtext2, 0, 0, WHITE);

        DrawCircle(bola.x, bola.y, bola.size, RED);

        EndMode2D();

        EndDrawing();
    }
    CloseWindow();
}