#ifndef MENU_H
#define MENU_H

// Estrutura para representar um botão
typedef struct
{
    Rectangle rect;
    Color color;
    Color hoverColor;
    char *text;
    bool clicked;
} Button;

Button CreateButton(Rectangle, Color, Color, char *);
void DrawButton(Button, int, Color);
void DefineThings();
void DrawThings(int *button);
void choose_button(int *button);
//
void DrawThingsover(int *button);
void choose_buttonover(int *button);
#endif