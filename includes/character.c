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

// Initialization
//--------------------------------------------------------------------------------------
Texture2D player_run_tex, player_idle_tex, player_jump_tex, player_landing_tex;

float frameWidth_run, frameHeight_run, frameWidth_idle, frameHeight_idle, frameWidth_jump, frameHeight_jump, frameWidth_landing, frameHeight_landing;

bool platformcollision = 0;
bool jump = 0;
bool moving = 0;
int jumptimer = 0;
int cont = 0;
int maxframes_run = 8;
int maxframes_idle = 12;
float timer = 0.0f;
int frame = 0;
Rectangle platform = {0, 0, 0, 0};
Vector2 posicao = {0, 0};
float gravity = 0.15;
float velocity_y = 0;

Rectangle player_run;
Rectangle player_idle;
Rectangle player_jump;
Rectangle player_landing;
Rectangle playerhitbox;
Rectangle Floor;
Camera2D camera = {0};

// character initialization
//--------------------------------------------------------------------------------------
void character_init()
{
    player_run_tex = LoadTexture("resources/player_run_tex.png");
    player_idle_tex = LoadTexture("resources/player_idle_tex.png");
    player_jump_tex = LoadTexture("resources/player_jump_tex.png");
    player_landing_tex = LoadTexture("resources/player_landing_tex.png");

    frameWidth_run = (float)player_run_tex.width / 8;
    frameHeight_run = player_run_tex.height;
    frameWidth_idle = (float)player_idle_tex.width / 12;
    frameHeight_idle = player_idle_tex.height;
    frameWidth_jump = player_jump_tex.width;
    frameHeight_jump = player_jump_tex.height;
    frameWidth_landing = player_landing_tex.width;
    frameHeight_landing = player_landing_tex.height;

    posicao = (Vector2){0, 320 - frameHeight_idle};
    player_run = (Rectangle){0, 0, frameWidth_run, frameHeight_run};
    player_idle = (Rectangle){0, 0, frameWidth_idle, frameHeight_idle};
    player_jump = (Rectangle){0, 0, frameWidth_jump, frameHeight_jump};
    player_landing = (Rectangle){0, 0, frameWidth_landing, frameHeight_landing};
    playerhitbox = (Rectangle){posicao.x, posicao.y, frameWidth_idle, frameHeight_idle};
}

// camera settings
//--------------------------------------------------------------------------------------
void camera_settings(int *screenWidth)
{
    camera.target = (Vector2){posicao.x + abs(player_idle.width) / 2 - *screenWidth / 2, 0};
    if (posicao.x < *screenWidth / 2)
        camera.target = (Vector2){abs(player_idle.width / 2), 0};
    if (posicao.x > largura_background - *screenWidth / 2 - abs(player_idle.width / 2))
        camera.target = (Vector2){largura_background - *screenWidth, 0};
    camera.offset = (Vector2){0, 0};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
}

// Player movement && animation && collision
//--------------------------------------------------------------------------------------
void character_movement()
{

    // character movement && animation
    if (IsKeyDown(KEY_RIGHT))
    {
        moving = 1;

        // character animation
        if (player_run.width < 0)
            player_run.width = -player_run.width;

        timer += GetFrameTime();
        player_run.x = frameWidth_run * frame;

        if (timer >= 0.2f)
        {
            timer = 0.0f;
            frame += 1;
        }

        frame = frame % maxframes_run;

        // movement
        posicao.x += 5;
        playerhitbox.x = posicao.x;
    }

    // character movement && animation
    else if (IsKeyDown(KEY_LEFT))
    {
        moving = 1;

        // animation
        if (player_run.width > 0)
            player_run.width = -player_run.width;

        timer += GetFrameTime();
        player_run.x = frameWidth_run * frame;

        if (timer >= 0.2f)
        {
            timer = 0.0f;
            frame += 1;
        }

        frame = frame % maxframes_run;

        // movement
        posicao.x -= 5;
        playerhitbox.x = posicao.x;
    }

    else
        moving = 0;

    // character jump
    if (IsKeyPressed(KEY_SPACE))
        jump = true;

    if (jump)
    {

        // jump animation
        if (player_run.width < 0)
        {
            player_jump.width = -abs(player_jump.width);
            player_landing.width = -abs(player_landing.width);
        }
        else
        {
            player_jump.width = abs(player_jump.width);
            player_landing.width = abs(player_landing.width);
        }

        // jump
        velocity_y = 6;
        jumptimer++;

        if (jumptimer < 40)
        {
            posicao.y -= velocity_y * jumptimer - gravity * jumptimer * jumptimer / 2 - (velocity_y * (jumptimer - 1) - gravity * (jumptimer - 1) * (jumptimer - 1) / 2);
            playerhitbox.y = posicao.y;
        }

        // fall
        else
        {
            posicao.y -= velocity_y * jumptimer - gravity * jumptimer * jumptimer / 2 - (velocity_y * (jumptimer - 1) - gravity * (jumptimer - 1) * (jumptimer - 1) / 2);
            playerhitbox.y = posicao.y;
        }

        // double jump
        if (!platformcollision)
            if (IsKeyPressed(KEY_SPACE) && cont == 0)
            {
                jumptimer = 0;
                cont = 1;
            }
    }

    if (!platformcollision && !jump)
    {
        // fall animation
        if (player_run.width < 0)
        {
            player_landing.width = -abs(player_landing.width);
        }
        else
        {
            player_landing.width = abs(player_landing.width);
        }

        // fall
        jumptimer++;
        posicao.y -= -gravity * jumptimer * jumptimer / 2 + (gravity * (jumptimer - 1) * (jumptimer - 1) / 2);
        playerhitbox.y = posicao.y;
    }

    // idle animation
    if (moving == 0 && jump == 0)
    {
        if (player_run.width < 0)
            player_idle.width = -abs(player_idle.width);
        else
            player_idle.width = abs(player_idle.width);

        timer += GetFrameTime();
        player_idle.x = frameWidth_idle * frame;

        if (timer >= 0.2f)
        {
            timer = 0.0f;
            frame += 1;
        }

        frame = frame % maxframes_idle;
    }

    // Platform collision
    platform = collision(playerhitbox, fase2, 2);
    if (platform.y != -1 && (posicao.y + playerhitbox.height - 10) < platform.y && (jump == 0 || (jump == 1 && jumptimer >= 40)) && (posicao.x + playerhitbox.width / 2 >= platform.x && posicao.x + playerhitbox.width / 2 <= platform.x + platform.width))
    {
        platformcollision = 1;
        if (jump == 0)
            jumptimer = 0;

        posicao.y = platform.y - playerhitbox.height + 1;
        playerhitbox.y = posicao.y;

        if ((jump == 1) & (jumptimer >= 40))
        {
            jump = false;
            cont = 0;
            jumptimer = 0;
        }
    }

    else
        platformcollision = 0;
    if (platformcollision == 1)
        printf("posicao %f\n", posicao.x);
}

// character drawing
//--------------------------------------------------------------------------------------
void draw_character()
{
    DrawRectangleRec(playerhitbox, BLANK);

    if (jump == 0 && platformcollision == 0)
        DrawTextureRec(player_landing_tex, player_landing, posicao, WHITE);
    if (moving == 1 && jump == 0 && platformcollision == 1)
        DrawTextureRec(player_run_tex, player_run, posicao, WHITE);
    if (moving == 0 && jump == 0 && platformcollision == 1)
        DrawTextureRec(player_idle_tex, player_idle, posicao, WHITE);
    if (jump == 1 && jumptimer < 40)
        DrawTextureRec(player_jump_tex, player_jump, posicao, WHITE);
    if (jump == 1 && jumptimer >= 40)
        DrawTextureRec(player_landing_tex, player_landing, posicao, WHITE);
}

void colisaoinimigos()
{
    platform = collision(playerhitbox, fase2, 2);

    Rectangle inimigo;
    inimigo = enemy2_movement(playerhitbox.x, playerhitbox.y);

    if (CheckCollisionRecs(playerhitbox, inimigo) || platform.y >= altura_tela)
    {
        posicao.x = 0;
        posicao.y = 0;
        playerhitbox.x = posicao.x;
        playerhitbox.y = posicao.y;
        unload_charactertex();
        unload_enemy2_tex();
        fimdejogo();
    }
}
// Unload characrer textures
//--------------------------------------------------------------------------------------
void unload_charactertex()
{
    UnloadTexture(player_run_tex);
    UnloadTexture(player_idle_tex);
    UnloadTexture(player_jump_tex);
    UnloadTexture(player_landing_tex);
}
