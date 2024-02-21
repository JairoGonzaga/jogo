#ifndef STRUCTS_H
#define STRUCTS_H
#include "raylib.h"
typedef struct
{
    int x;
    int y;
    float size;
    int velocidadeY;
    int noChao;
} Bola;
typedef enum
{
    PLATFORM,
    FLOOR,
} PlatformType;
typedef struct
{
    int x;
    int y;
    int largura;
    int altura;
    PlatformType type;
} Platform;
typedef struct
{
    Texture2D background;
    Platform plataformas[17];
} fase;

#endif