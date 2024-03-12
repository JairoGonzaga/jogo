#include <stdio.h>
#include "raylib.h"
#include "enemy2.h"
Rectangle startRect;
Button startButton;
Rectangle instructionsRect;
Button instructionsButton;
Rectangle creditsRect;
Button creditsButton;
Rectangle exitRect;
Button exitButton;
Rectangle restartRect;
Button restartButton;
Texture2D instructions;
Texture2D menuPrincipal;
Texture2D credits;
Texture2D restart;

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

void DefineThings()
{
    restartRect = (Rectangle){1000 / 2 + 250, 736 / 2 + 25, 195, 65};
    restartButton = CreateButton(restartRect, LIME, LIGHTGRAY, "restart");

    startRect = (Rectangle){1000 / 2 + 250, 736 / 2 - 175, 195, 65};
    startButton = CreateButton(startRect, LIME, LIGHTGRAY, "Start");

    instructionsRect = (Rectangle){1000 / 2 + 250, 736 / 2 - 75, 195, 65};
    instructionsButton = CreateButton(instructionsRect, LIME, LIGHTGRAY, "Instruções");

    creditsRect = (Rectangle){1000 / 2 + 250, 736 / 2 + 25, 195, 65};
    creditsButton = CreateButton(creditsRect, LIME, LIGHTGRAY, "Créditos");

    exitRect = (Rectangle){1000 / 2 + 250, 736 / 2 + 125, 195, 65};
    exitButton = CreateButton(exitRect, LIME, LIGHTGRAY, "Sair");

    instructions = LoadTexture("assets/menu/instructions.png");
    credits = LoadTexture("assets/menu/credits.png");
    restart = LoadTexture("assets/menu/gameover.png");

    menuPrincipal = LoadTexture("./assets/MENU.png");
}

void DrawThings(int *button)
{

    if (*button == 0)
    {
        DrawTexture(menuPrincipal, 0, 0, WHITE);
        DrawButton(startButton, 2, BLACK);
        DrawButton(instructionsButton, 2, BLACK);
        DrawButton(creditsButton, 2, BLACK);
        DrawButton(exitButton, 2, BLACK);
    }
    // if(*button == 1)
    // começa o jogo
    if (*button == 2)
    {
        DrawTexture(instructions, 0, 0, WHITE);
        if (IsKeyPressed(KEY_SPACE))
            *button = 0;
    }
    if (*button == 3)
    {
        DrawTexture(credits, 0, 0, WHITE);
        if (IsKeyPressed(KEY_SPACE))
            *button = 0;
    }
}

void choose_button(int *button)
{

    // Verificando se o botão Start foi clicado
    if (CheckCollisionRecs(startButton.rect, (Rectangle){GetMouseX(), GetMouseY(), 1, 1}) && *button == 0)
    {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            *button = 1;
        // começar o jogo
    }

    // botão de instruções
    else if (CheckCollisionRecs(instructionsButton.rect, (Rectangle){GetMouseX(), GetMouseY(), 1, 1}) && *button == 0)
    {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            *button = 2;
    }

    // botão de créditos
    else if (CheckCollisionRecs(creditsButton.rect, (Rectangle){GetMouseX(), GetMouseY(), 1, 1}) && *button == 0)
    {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            *button = 3;
    }

    // botão de exit
    else if (CheckCollisionRecs(exitButton.rect, (Rectangle){GetMouseX(), GetMouseY(), 1, 1}) && *button == 0)
    {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            CloseWindow();
    }

    if (*button != 0)
        if (IsKeyPressed(KEY_SPACE))
            *button = 0;
}
void DrawThingsover(int *button)
{

    if (*button == 4)
    {
        DrawTexture(restart, 0, 0, WHITE);
        DrawButton(restartButton, 2, BLACK);
        DrawButton(exitButton, 2, BLACK);
    }
}

void choose_buttonover(int *button)
{

    if (CheckCollisionRecs(restartButton.rect, (Rectangle){GetMouseX(), GetMouseY(), 1, 1}) && *button == 4)
    {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            *button = 1;
        enemy1_init();
        enemy2_init();
        character_init();
    }

    // botão de exit
    else if (CheckCollisionRecs(exitButton.rect, (Rectangle){GetMouseX(), GetMouseY(), 1, 1}) && *button == 4)
    {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            CloseWindow();
    }

    if (*button != 4)
        if (IsKeyPressed(KEY_SPACE))
            *button = 4;
}