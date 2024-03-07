#include "raylib.h"
#include "structs.h"
#include "colisao.h"

#ifndef COLISAO_C
#define COLISAO_C

Rectangle collision(Rectangle player, fase fase, int num_fase)
{
    int count;
    if (num_fase == 1)
    {
        count = 14;
    }
    else
        count = 26;

    for (int i = 0; i < count; i++)
    {
        if (CheckCollisionRecs(player, fase.plataformas[i]))
        {
            return (fase.plataformas[i]);
        }
    }
    return ((Rectangle){0, 0, 0, 0});
}
#endif