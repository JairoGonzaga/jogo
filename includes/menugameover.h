#ifndef MENUGAMEOVER_H
#define MENUGAMEOVER_H

#include "raylib.h"

typedef struct
{
    Rectangle rect;
    Color color;
    Color hoverColor;
    char *text;
    bool clicked;
} Button;

void fimdejogo();
Button CreateButton(Rectangle rect, Color color, Color hoverColor, char *text);
void DrawButton(Button button, int borderWidth, Color borderColor);

#endif
