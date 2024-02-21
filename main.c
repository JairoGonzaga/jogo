#include "raylib.h"
#include <stdio.h>
#include "includes/colisao.h"
#include "includes/defs.h"
#include "includes/transicao.c"
#include "includes/fase1.c"
#include "includes/fase2.c"
#include "includes/structs.h"

int main()
{
    InitWindow(largura_tela, altura_tela, "mapa");
    while (!WindowShouldClose())
    {
        transicao1();
    }

    CloseWindow();

    return 0;
}
