#include "raylib.h"
#include "structs.h"
#include "colisao.h"

int bola_na_plat(Bola bola, Platform plataforma[], int fase)
{
    int count;
    if (fase == 1)
    {
        count = 14;
    }
    else
        count = 17;

    for (int i = 0; i < count; i++)
    {
        Platform plataforms = plataforma[i];
        Rectangle platform_rec = {.x = plataforms.x, .y = plataforms.y, .height = plataforms.altura, .width = plataforms.largura};
        Rectangle pos_bola = {
            .x = bola.x - bola.size + 5,
            .y = bola.y + bola.size / 2,
            .width = bola.size * 2 - 10,
            .height = bola.size / 2 + 1};
        if (CheckCollisionRecs(pos_bola, platform_rec))
        {
            return i;
        }
    }
    return -1;
}