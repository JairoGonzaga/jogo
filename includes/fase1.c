#include "raylib.h"
#include <stdio.h>
#include "structs.h"
#include "fase1.h"
#include "defs.h"
#include "colisao.h"

void jogo_fase1()
{
    Texture2D backtext1 = LoadTexture("assets/definitivo.png");

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
    const int largura_background = backtext1.width;
    const int altura_background = backtext1.height;
    fase fase2;
    fase2.plataformas[0].y = altura_background + 50;
    fase2.plataformas[0].x = 0;
    fase2.plataformas[0].largura = largura_background;
    fase2.plataformas[0].altura = 10;

    fase2.plataformas[1].y = 160;
    fase2.plataformas[1].x = 0;
    fase2.plataformas[1].largura = 64;
    fase2.plataformas[1].altura = 10;

    fase2.plataformas[2].y = 640;
    fase2.plataformas[2].x = 0;
    fase2.plataformas[2].largura = 288;
    fase2.plataformas[2].altura = 10;

    fase2.plataformas[3].y = 640;
    fase2.plataformas[3].x = 354;
    fase2.plataformas[3].largura = 224;
    fase2.plataformas[3].altura = 10;

    fase2.plataformas[4].y = 593;
    fase2.plataformas[4].x = 608;
    fase2.plataformas[4].largura = 160;
    fase2.plataformas[4].altura = 10;

    fase2.plataformas[5].y = 465;
    fase2.plataformas[5].x = 450;
    fase2.plataformas[5].largura = 160;
    fase2.plataformas[5].altura = 10;

    fase2.plataformas[6].y = 369;
    fase2.plataformas[6].x = 450;
    fase2.plataformas[6].largura = 160;
    fase2.plataformas[6].altura = 10;

    fase2.plataformas[7].y = 305;
    fase2.plataformas[7].x = 642;
    fase2.plataformas[7].largura = 224;
    fase2.plataformas[7].altura = 10;

    fase2.plataformas[8].y = 547;
    fase2.plataformas[8].x = 1058;
    fase2.plataformas[8].largura = 384;
    fase2.plataformas[8].altura = 10;

    fase2.plataformas[9].y = 419;
    fase2.plataformas[9].x = 1410;
    fase2.plataformas[9].largura = 192;
    fase2.plataformas[9].altura = 10;

    fase2.plataformas[10].y = 404;
    fase2.plataformas[10].x = 1666;
    fase2.plataformas[10].largura = 160;
    fase2.plataformas[10].altura = 10;

    fase2.plataformas[11].y = 291;
    fase2.plataformas[11].x = 1922;
    fase2.plataformas[11].largura = 352;
    fase2.plataformas[11].altura = 10;

    fase2.plataformas[12].y = 180;
    fase2.plataformas[12].x = 2178;
    fase2.plataformas[12].largura = 128;
    fase2.plataformas[12].altura = 10;

    fase2.plataformas[13].y = 116;
    fase2.plataformas[13].x = 2402;
    fase2.plataformas[13].largura = 128;
    fase2.plataformas[13].altura = 10;

    const int largura_in = 30;
    const int altura_in = 30;

    Rectangle inimigo = {largura_in / 2 - 100, largura_in / 2 - 100, 25, 25};
    float speed = 2; // velocidade dele
    bool moveRight = true;

    inimigo.y = 530;
    inimigo.x = 980;

    while (!WindowShouldClose())
    {
        int plat_atual = bola_na_plat(bola, fase2.plataformas, 1);
        if (plat_atual != -1)
        {
            if (bola.velocidadeY > 0)
            {
                bola.y = fase2.plataformas[plat_atual].y - bola.size;
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
        if (inimigo.y > fase2.plataformas[8].y)
        {
            inimigo.y = -30;
        }

        // movimentação dele
        if (moveRight)
        {
            inimigo.x += speed;
            if (inimigo.x + inimigo.width >= fase2.plataformas[8].x + fase2.plataformas[8].largura)
            {
                inimigo.x = fase2.plataformas[8].x + fase2.plataformas[8].largura - inimigo.width;
                moveRight = false;
            }
        }
        else
        {
            inimigo.x -= speed;
            if (inimigo.x <= fase2.plataformas[8].x)
            {
                inimigo.x = fase2.plataformas[8].x;
                moveRight = true;
            }
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

        DrawTexture(backtext1, 0, 0, WHITE);

        DrawCircle(bola.x, bola.y, bola.size, RED);
        DrawRectangleRec(inimigo, VIOLET);

        if (plat_atual == 13)
        {
            transicao2();
        }
        EndMode2D();

        EndDrawing();
    }
}