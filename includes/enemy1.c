#ifndef ENEMY1_C
#define ENEMY1_C 
#include <stdio.h>
#include <math.h>
#include "enemy1.h"
#include "raylib.h"
#include "fase2.c"

Rectangle inimigo;
Texture2D enemy1_tex;
float speed;
bool moveRight;
float timer_enemy1 = 0.0f;
int maxframes_enemy1 = 15;
int frame_enemy1 = 0;
float frameWidth_enemy1;
float frameHeight_enemy1;
Vector2 posicao_enemy1;

void enemy1_init(){

    enemy1_tex = LoadTexture("resources/enemy1_tex.png");
    frameWidth_enemy1 = (float) enemy1_tex.width/15;
    frameHeight_enemy1 = enemy1_tex.height;
    inimigo = (Rectangle) {0, 0, frameWidth_enemy1, frameHeight_enemy1};
    speed = 3; // velocidade dele
    moveRight = true;
    posicao_enemy1 = (Vector2) {980,510}; // x = 980
}
void enemy1_movement(){
    if (moveRight)
        {
        posicao_enemy1.x += speed;
        if (posicao_enemy1.x + inimigo.width >= fase2.plataformas[8].x + fase2.plataformas[8].width)
            {
            posicao_enemy1.x = fase2.plataformas[8].x + fase2.plataformas[8].width - inimigo.width;
            moveRight = false;
            }
        }
        else
        {
            posicao_enemy1.x -= speed;
            if (posicao_enemy1.x <= fase2.plataformas[8].x)
            {
                posicao_enemy1.x = fase2.plataformas[8].x;
                moveRight = true;
            }
        }

    //   enemy1 animation
    if(moveRight == false){
        enemy1_tex.width = -abs(enemy1_tex.width); 
        inimigo.x = (frameWidth_enemy1 * frame_enemy1); 
    }

    else{ 
        enemy1_tex.width = abs(enemy1_tex.width); 
        inimigo.x = -(frameWidth_enemy1 * frame_enemy1); 
    }

    timer_enemy1 += GetFrameTime();
   
    if(timer_enemy1 >=0.2f){
        timer_enemy1 = 0.0f;
        frame_enemy1 += 1;
    }

    frame_enemy1 = frame_enemy1%maxframes_enemy1;

}
void draw_enemy1(){
    DrawTextureRec(enemy1_tex,inimigo, posicao_enemy1,WHITE);
}

void unload_enemy1_tex(){
     UnloadTexture(enemy1_tex);
}



#endif