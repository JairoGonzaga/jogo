#include <stdio.h>
#include <math.h>
#include "raylib.h"
#include "character.h"
#include "fase1.h"
#include "fase1.c"
#include "fase2.h"
#include "fase2.c"
#include "colisao.h"
#include "colisao.c"
#include "enemy2.h"
#include "menugameover.h"

#ifndef MENUGAMEOVER_C
#define MENUGAMEOVER_C

// Estrutura para representar um botão
typedef struct
{
    Rectangle rect;
    Color color;
    Color hoverColor;
    char *text;
    bool clicked;
} Button;

// Função para criar um botão com parâmetros dados
Button CreateButton(Rectangle rect, Color color, Color hoverColor, char *text)
{
    Button button;
    button.rect = rect;
    button.color = color;
    button.hoverColor = hoverColor;
    button.text = text;
    button.clicked = false;
    return button;
}

// Função para desenhar um botão
void DrawButton(Button button, int borderWidth, Color borderColor)
{
    Color buttonColor = button.color;

    if (CheckCollisionPointRec(GetMousePosition(), button.rect))
    {
        buttonColor = button.hoverColor;
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            button.clicked = true; // Define o botão como clicado
        }
    }

    DrawRectangleRec(button.rect, buttonColor);
    DrawRectangleLinesEx(button.rect, borderWidth, borderColor);

    float textX = button.rect.x + (button.rect.width - MeasureText(button.text, 26)) / 2;
    float textY = button.rect.y + (button.rect.height - 26) / 2;
    DrawText(button.text, textX, textY, 26, BLACK);
}

void fimdejogo()
{
    int flagTela = 0;
    // Definindo os botões do menu
    Rectangle Restartrect = {largura_tela / 2 + 250, altura_tela / 2 - 175, 195, 65};
    Button restartbuton = CreateButton(Restartrect, LIME, LIGHTGRAY, "restart");

    Rectangle exitRect = {largura_tela / 2 + 250, altura_tela / 2 + 125, 195, 65};
    Button exitButton = CreateButton(exitRect, LIME, LIGHTGRAY, "Exit");

    Texture2D menugameover = LoadTexture("./assets/MENU.png");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Textura fundo do menu
        DrawTexture(menugameover, 0, 0, WHITE);

        // Desenhando os botões
        DrawButton(restartbuton, 2, BLACK);
        DrawButton(exitButton, 2, BLACK);

        if (CheckCollisionRecs(restartbuton.rect, (Rectangle){GetMouseX(), GetMouseY(), 1, 1}))
        {

            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                fase2_init();
                character_init();
                enemy2_init();
            }
        }
        // botão de exit
        else if (CheckCollisionRecs(exitButton.rect, (Rectangle){GetMouseX(), GetMouseY(), 1, 1}))
        {

            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                CloseWindow();
            }
        }
    }
}
#endif