#include "raylib.h"
#include <stdio.h>
#include "structs.h"
#include "fase1.h"
#include "defs.h"
#include "colisao.c"
#ifndef FASE1_C
#define FASE1_C

Texture2D backtext1;
int largura_background;
int altura_background;
fase fase1;

void fase1_init()
{
    backtext1 = LoadTexture("assets/mapajogoplat.png");
    largura_background = backtext1.width;
    altura_background = backtext1.height;

    fase1.plataformas[0].x = 0;
    fase1.plataformas[0].y = 14 + 21 * 32;
    fase1.plataformas[0].width = 9 * 32;
    fase1.plataformas[0].height = 32;

    fase1.plataformas[1].x = 9 * 32;
    fase1.plataformas[1].y = 14 + 18 * 32;
    fase1.plataformas[1].width = 9 * 32;
    fase1.plataformas[1].height = 32;

    fase1.plataformas[2].x = 18 * 32;
    fase1.plataformas[2].y = 14 + 11 * 32;
    fase1.plataformas[2].width = 8 * 32;
    fase1.plataformas[2].height = 32;

    fase1.plataformas[3].x = 27 * 32;
    fase1.plataformas[3].y = 14 + 7 * 32;
    fase1.plataformas[3].width = 14 * 32;
    fase1.plataformas[3].height = 32;

    fase1.plataformas[4].x = 40 * 32;
    fase1.plataformas[4].y = 14 + 18 * 32;
    fase1.plataformas[4].width = 11 * 32;
    fase1.plataformas[4].height = 32;

    fase1.plataformas[5].x = 51 * 32;
    fase1.plataformas[5].y = 14 + 15 * 32;
    fase1.plataformas[5].width = 5 * 32;
    fase1.plataformas[5].height = 32;

    fase1.plataformas[6].x = 56 * 32;
    fase1.plataformas[6].y = 14 + 12 * 32;
    fase1.plataformas[6].width = 5 * 32;
    fase1.plataformas[6].height = 32;

    fase1.plataformas[7].x = 51 * 32;
    fase1.plataformas[7].y = 14 + 9 * 32;
    fase1.plataformas[7].width = 5 * 32;
    fase1.plataformas[7].height = 32;

    fase1.plataformas[8].x = 56 * 32;
    fase1.plataformas[8].y = 14 + 5 * 32;
    fase1.plataformas[8].width = 19 * 32;
    fase1.plataformas[8].height = 32;

    fase1.plataformas[9].x = 74 * 32;
    fase1.plataformas[9].y = 14 + 9 * 32;
    fase1.plataformas[9].width = 6 * 32;
    fase1.plataformas[9].height = 32;

    fase1.plataformas[10].x = 68 * 32;
    fase1.plataformas[10].y = 14 + 13 * 32;
    fase1.plataformas[10].width = 7 * 32;
    fase1.plataformas[10].height = 32;

    fase1.plataformas[11].x = 74 * 32;
    fase1.plataformas[11].y = 14 + 17 * 32;
    fase1.plataformas[11].width = 6 * 32;
    fase1.plataformas[11].height = 32;

    fase1.plataformas[12].x = 66 * 32;
    fase1.plataformas[12].y = 14 + 21 * 32;
    fase1.plataformas[12].width = 14 * 32;
    fase1.plataformas[12].height = 32;
}
    
void draw_fase1(){
    DrawTexture(backtext1, 0, 0, WHITE);
    }

#endif