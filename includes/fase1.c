#include "raylib.h"
#include <stdio.h>
#include "structs.h"
#include "fase1.h"
#include "defs.h"
#include "colisao.c"
#ifndef FASE1_C
#define FASE1_C

Texture2D backtext1;
int largura_background1;
int altura_background1;
fase fase1;

void fase1_init()
{
    backtext1 = LoadTexture("assets/maps/map1.png");
    largura_background1 = backtext1.width;
    altura_background1 = backtext1.height;

    fase1.plataformas[0].x = 0 * 32;
    fase1.plataformas[0].y = 14 + (21 * 32);
    fase1.plataformas[0].width = 12 * 32;
    fase1.plataformas[0].height = 32;

    fase1.plataformas[1].x = 9 * 32;
    fase1.plataformas[1].y = 14 + (17 * 32);
    fase1.plataformas[1].width = 4 * 32;
    fase1.plataformas[1].height = 32;

    fase1.plataformas[2].x = 11 * 32;
    fase1.plataformas[2].y = 14 + (14 * 32);
    fase1.plataformas[2].width = 11 * 32;
    fase1.plataformas[2].height = 32;

    fase1.plataformas[3].x = 22 * 32;
    fase1.plataformas[3].y = 14 + (10 * 32);
    fase1.plataformas[3].width = 8 * 32;
    fase1.plataformas[3].height = 32;

    fase1.plataformas[4].x = 30 * 32;
    fase1.plataformas[4].y = 14 + (14 * 32);
    fase1.plataformas[4].width = 9 * 32;
    fase1.plataformas[4].height = 32;

    fase1.plataformas[5].x = 38 * 32;
    fase1.plataformas[5].y = 14 + (10 * 32);
    fase1.plataformas[5].width = 8 * 32;
    fase1.plataformas[5].height = 32;

    fase1.plataformas[6].x = 46 * 32;
    fase1.plataformas[6].y = 14 + (5 * 32);
    fase1.plataformas[6].width = 17 * 32;
    fase1.plataformas[6].height = 32;

    fase1.plataformas[7].x = 63 * 32;
    fase1.plataformas[7].y = 14 + (10 * 32);
    fase1.plataformas[7].width = 9 * 32;
    fase1.plataformas[7].height = 32;

    fase1.plataformas[8].x = 70 * 32;
    fase1.plataformas[8].y = 14 + (20 * 32);
    fase1.plataformas[8].width = 14 * 32;
    fase1.plataformas[8].height = 32;

    fase1.plataformas[9].x = 85 * 32;
    fase1.plataformas[9].y = 14 + (14 * 32);
    fase1.plataformas[9].width = 13 * 32;
    fase1.plataformas[9].height = 32;

    fase1.plataformas[10].x = 99 * 32;
    fase1.plataformas[10].y = 14 + (17 * 32);
    fase1.plataformas[10].width = 12 * 32;
    fase1.plataformas[10].height = 32;

    fase1.plataformas[11].x = 112 * 32;
    fase1.plataformas[11].y = 14 + (11 * 32);
    fase1.plataformas[11].width = 12 * 32;
    fase1.plataformas[11].height = 32;

    fase1.plataformas[12].x = 125 * 32;
    fase1.plataformas[12].y = 14 + (6 * 32);
    fase1.plataformas[12].width = 4 * 32;
    fase1.plataformas[12].height = 32;

    fase1.plataformas[13].x = 134 * 32;
    fase1.plataformas[13].y = 14 + (6 * 32);
    fase1.plataformas[13].width = 4 * 32;
    fase1.plataformas[13].height = 32;

    fase1.plataformas[14].x = 138 * 32;
    fase1.plataformas[14].y = 14 + (11 * 32);
    fase1.plataformas[14].width = 15 * 32;
    fase1.plataformas[14].height = 32;

    fase1.plataformas[15].x = 153 * 32;
    fase1.plataformas[15].y = 14 + (16 * 32);
    fase1.plataformas[15].width = 10 * 32;
    fase1.plataformas[15].height = 32;

    fase1.plataformas[16].x = 163 * 32;
    fase1.plataformas[16].y = 14 + (20 * 32);
    fase1.plataformas[16].width = 5 * 32;
    fase1.plataformas[16].height = 32;

    fase1.plataformas[17].x = 171 * 32;
    fase1.plataformas[17].y = 14 + (22 * 32);
    fase1.plataformas[17].width = 2 * 32;
    fase1.plataformas[17].height = 32;

    fase1.plataformas[18].x = 175 * 32;
    fase1.plataformas[18].y = 14 + (22 * 32);
    fase1.plataformas[18].width = 2 * 32;
    fase1.plataformas[18].height = 32;

    // plataforma de morte do personagem, ta como colisao por enquanto

    fase1.plataformas[19].x = 0 * 32;
    fase1.plataformas[19].y = 14 + (25 * 32);
    fase1.plataformas[19].width = 180 * 32;
    fase1.plataformas[19].height = 32;
}

void draw_fase1()
{
    DrawTexture(backtext1, 0, 0, WHITE);
    //     for(int i=0; i<20; i++)
    //         DrawRectangleRec(fase1.plataformas[i],BLACK);
}
#endif