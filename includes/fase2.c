#include "raylib.h"
#include <stdio.h>
#include "structs.h"
#include "fase1.h"
#include "defs.h"
#include "colisao.h"
#ifndef FASE2_C
#define FASE2_C

Texture2D backtext2;

int largura_background2;
int altura_background2;
fase fase2;

void fase2_init()
{

    backtext2 = LoadTexture("assets/maps/fase2defin.png");

    largura_background2 = backtext2.width;
    altura_background2 = backtext2.height;

    fase2.plataformas[0].y = altura_background2 + 50;
    fase2.plataformas[0].x = 0;
    fase2.plataformas[0].width = largura_background2;
    fase2.plataformas[0].height = 10;

    fase2.plataformas[1].y = 155 + 4;
    fase2.plataformas[1].x = 0;
    fase2.plataformas[1].width = 64;
    fase2.plataformas[1].height = 10;

    fase2.plataformas[2].y = 640 + 4;
    fase2.plataformas[2].x = 0;
    fase2.plataformas[2].width = 352;
    fase2.plataformas[2].height = 10;

    fase2.plataformas[3].y = 800 + 4;
    fase2.plataformas[3].x = 512;
    fase2.plataformas[3].width = 352;
    fase2.plataformas[3].height = 10;

    fase2.plataformas[4].y = 640 + 4;
    fase2.plataformas[4].x = 1024;
    fase2.plataformas[4].width = 288;
    fase2.plataformas[4].height = 10;

    fase2.plataformas[5].y = 640 + 4;
    fase2.plataformas[5].x = 1376;
    fase2.plataformas[5].width = 224;
    fase2.plataformas[5].height = 10;

    fase2.plataformas[6].y = 448 + 4;
    fase2.plataformas[6].x = 1664;
    fase2.plataformas[6].width = 352;
    fase2.plataformas[6].height = 10;

    fase2.plataformas[7].y = 576 + 4;
    fase2.plataformas[7].x = 1952;
    fase2.plataformas[7].width = 160;
    fase2.plataformas[7].height = 10;

    fase2.plataformas[8].y = 736 + 4;
    fase2.plataformas[8].x = 2080;
    fase2.plataformas[8].width = 960;
    fase2.plataformas[8].height = 10;

    fase2.plataformas[9].y = 512 + 4;
    fase2.plataformas[9].x = 3040;
    fase2.plataformas[9].width = 352;
    fase2.plataformas[9].height = 10;

    fase2.plataformas[10].y = 288 + 4;
    fase2.plataformas[10].x = 2720;
    fase2.plataformas[10].width = 352;
    fase2.plataformas[10].height = 10;

    fase2.plataformas[11].y = 160 + 4;
    fase2.plataformas[11].x = 3296;
    fase2.plataformas[11].width = 640;
    fase2.plataformas[11].height = 10;

    fase2.plataformas[12].y = 288 + 4;
    fase2.plataformas[12].x = 3936;
    fase2.plataformas[12].width = 192;
    fase2.plataformas[12].height = 10;

    fase2.plataformas[13].y = 544 + 4;
    fase2.plataformas[13].x = 4096;
    fase2.plataformas[13].width = 608;
    fase2.plataformas[13].height = 10;

    fase2.plataformas[14].y = 672 + 4;
    fase2.plataformas[14].x = 4736;
    fase2.plataformas[14].width = 576;
    fase2.plataformas[14].height = 10;

    fase2.plataformas[15].y = 832 + 4;
    fase2.plataformas[15].x = 5344;
    fase2.plataformas[15].width = 192 + 32;
    fase2.plataformas[15].height = 10;

    fase2.plataformas[16].y = 832 + 4;
    fase2.plataformas[16].x = 5888;
    fase2.plataformas[16].width = 192;
    fase2.plataformas[16].height = 10;

    fase2.plataformas[17].y = 640 + 4;
    fase2.plataformas[17].x = 6176;
    fase2.plataformas[17].width = 192;
    fase2.plataformas[17].height = 10;

    fase2.plataformas[18].y = 416 + 4;
    fase2.plataformas[18].x = 6336;
    fase2.plataformas[18].width = 544 + 32;
    fase2.plataformas[18].height = 10;

    fase2.plataformas[19].y = 708;
    fase2.plataformas[19].x = 6912;
    fase2.plataformas[19].width = 1216 + 32;
    fase2.plataformas[19].height = 10;

    fase2.plataformas[20].y = 896 + 4;
    fase2.plataformas[20].x = 8160;
    fase2.plataformas[20].width = 256 + 32;
    fase2.plataformas[20].height = 10;

    fase2.plataformas[21].y = 708;
    fase2.plataformas[21].x = 8448;
    fase2.plataformas[21].width = 288;
    fase2.plataformas[21].height = 10;

    fase2.plataformas[22].y = 512 + 4;
    fase2.plataformas[22].x = 8768;
    fase2.plataformas[22].width = 288;
    fase2.plataformas[22].height = 10;

    fase2.plataformas[23].y = 512 + 4;
    fase2.plataformas[23].x = 9280;
    fase2.plataformas[23].width = 320;
    fase2.plataformas[23].height = 10;

    fase2.plataformas[24].y = 288 + 4;
    fase2.plataformas[24].x = 9632;
    fase2.plataformas[24].width = 192;
    fase2.plataformas[24].height = 10;

    fase2.plataformas[25].y = 128 + 12;
    fase2.plataformas[25].x = 9984;
    fase2.plataformas[25].width = 224;
    fase2.plataformas[25].height = 10;
}

void draw_fase2()
{
    DrawTexture(backtext2, 0, 0, WHITE);
}

#endif