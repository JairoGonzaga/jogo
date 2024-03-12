#ifndef ENEMY1_C
#define ENEMY1_C 
#include <stdio.h>
#include <math.h>
#include "enemy1.h"
#include "raylib.h"
#include "fase2.c"
#include "fase1.c"

Texture2D enemy1_tex;
float speed;
float timer_enemy1 = 0.0f;
int maxframes_enemy1 = 15;
int frame_enemy1 = 0;
float frameWidth_enemy1;
float frameHeight_enemy1;
enemy1_data enemy1[21];
void enemy1_init(){

    enemy1_tex = LoadTexture("resources/enemy1_tex.png");
    frameWidth_enemy1 = (float) enemy1_tex.width/15;
    frameHeight_enemy1 = enemy1_tex.height;
    for(int i = 0; i<21; i++)
        enemy1[i].recfps = (Rectangle) {0, 0, frameWidth_enemy1, frameHeight_enemy1}; 
    speed = 0.1; // velocidade dele
    for (int i = 0; i<21; i++)
        enemy1[i].moveright = true;

    //enemy1 da fase1
    enemy1[0].rechitbox = (Rectangle) {350, 428,frameWidth_enemy1,frameHeight_enemy1};
    enemy1[1].rechitbox = (Rectangle) {960, 428,frameWidth_enemy1,frameHeight_enemy1};
    enemy1[2].rechitbox = (Rectangle) {1650, 140,frameWidth_enemy1,frameHeight_enemy1};
    enemy1[3].rechitbox = (Rectangle) {2360, 620,frameWidth_enemy1,frameHeight_enemy1};
    enemy1[4].rechitbox = (Rectangle) {3330, 524,frameWidth_enemy1,frameHeight_enemy1};
    enemy1[5].rechitbox = (Rectangle) {4680, 332,frameWidth_enemy1,frameHeight_enemy1};
    enemy1[6].rechitbox = (Rectangle) {5110, 492,frameWidth_enemy1,frameHeight_enemy1};

    //enemy1 da fase 2
    enemy1[7].rechitbox = (Rectangle) {504, 765, frameWidth_enemy1, frameHeight_enemy1};
    enemy1[8].rechitbox = (Rectangle) {1560, 605, frameWidth_enemy1, frameHeight_enemy1};
    enemy1[9].rechitbox = (Rectangle) {2076, 701, frameWidth_enemy1, frameHeight_enemy1};
    enemy1[10].rechitbox = (Rectangle) {3000, 701, frameWidth_enemy1, frameHeight_enemy1};
    enemy1[11].rechitbox = (Rectangle) {2712, 253, frameWidth_enemy1, frameHeight_enemy1};
    enemy1[12].rechitbox = (Rectangle) {3288, 125, frameWidth_enemy1, frameHeight_enemy1};
    enemy1[13].rechitbox = (Rectangle) {4668, 509, frameWidth_enemy1, frameHeight_enemy1};
    enemy1[14].rechitbox = (Rectangle) {5280, 253, frameWidth_enemy1, frameHeight_enemy1};
    enemy1[15].rechitbox = (Rectangle) {6300, 605, frameWidth_enemy1, frameHeight_enemy1};
    enemy1[16].rechitbox = (Rectangle) {6852, 381, frameWidth_enemy1, frameHeight_enemy1};
    enemy1[17].rechitbox = (Rectangle) {6891, 669, frameWidth_enemy1, frameHeight_enemy1};
    enemy1[18].rechitbox = (Rectangle) {8112, 669, frameWidth_enemy1, frameHeight_enemy1};
    enemy1[19].rechitbox = (Rectangle) {8700, 669, frameWidth_enemy1, frameHeight_enemy1};
    enemy1[20].rechitbox = (Rectangle) {9552, 477, frameWidth_enemy1, frameHeight_enemy1};
    }

void enemy1_movement(){
    
    //movimentacao fase1
    for(int i=0; i<7; i++)
        for(int j=0; j<19; j++){
            if (enemy1[i].moveright)
                {
                enemy1[i].rechitbox.x += speed;
                if (enemy1[i].rechitbox.x + enemy1[i].recfps.width >= fase1.plataformas[j].x + fase1.plataformas[j].width && CheckCollisionRecs(enemy1[i].rechitbox,fase1.plataformas[j]))
                    {
                    enemy1[i].rechitbox.x = fase1.plataformas[j].x + fase1.plataformas[j].width - enemy1[i].recfps.width;
                    enemy1[i].moveright = false;
                    }
                }
            else 
                {
                    enemy1[i].rechitbox.x -= speed;
                    if (enemy1[i].rechitbox.x <= fase1.plataformas[j].x && CheckCollisionRecs(enemy1[i].rechitbox,fase1.plataformas[j]))
                    {
                        enemy1[i].rechitbox.x = fase1.plataformas[j].x;
                        enemy1[i].moveright = true;
                    }
                }
        }

    //movimentação fase 2
    for(int i=7; i<21; i++)
        for(int j=1; j<26; j++){
            if (enemy1[i].moveright)
                {
                enemy1[i].rechitbox.x += speed;
                if (enemy1[i].rechitbox.x + enemy1[i].recfps.width >= fase2.plataformas[j].x + fase2.plataformas[j].width && CheckCollisionRecs(enemy1[i].rechitbox,fase2.plataformas[j]))
                    {
                    enemy1[i].rechitbox.x = fase2.plataformas[j].x + fase2.plataformas[j].width - enemy1[i].recfps.width;
                    enemy1[i].moveright = false;
                    }
                }
            else 
                {
                    enemy1[i].rechitbox.x -= speed;
                    if (enemy1[i].rechitbox.x <= fase2.plataformas[j].x && CheckCollisionRecs(enemy1[i].rechitbox,fase2.plataformas[j]))
                    {
                        enemy1[i].rechitbox.x = fase2.plataformas[j].x;
                        enemy1[i].moveright = true;
                    }
                }
        }

    //enemy1 animation
    for(int i=0; i<21; i++){
        if(enemy1[i].moveright == false){
            enemy1[i].recfps.width = -abs(enemy1[i].recfps.width); 
            enemy1[i].recfps.x = (frameWidth_enemy1 * frame_enemy1); 
        }

        else{ 
             enemy1[i].recfps.width = abs(enemy1[i].recfps.width); 
            enemy1[i].recfps.x = -(frameWidth_enemy1 * frame_enemy1); 
        }

        timer_enemy1 += GetFrameTime();
    
        if(timer_enemy1 >=0.2f){
            timer_enemy1 = 0.0f;
            frame_enemy1 += 1;
        }

        frame_enemy1 = frame_enemy1%maxframes_enemy1;
    }

}
void draw_enemy1_map1(){
    for(int i = 0; i<7; i++)
        DrawTextureRec(enemy1_tex,enemy1[i].recfps, (Vector2) {enemy1[i].rechitbox.x,enemy1[i].rechitbox.y},WHITE);
}

void draw_enemy1_map2(){
    for(int i = 7; i<21; i++)
        DrawTextureRec(enemy1_tex,enemy1[i].recfps, (Vector2) {enemy1[i].rechitbox.x,enemy1[i].rechitbox.y},WHITE);
}

void unload_enemy1_tex(){
     UnloadTexture(enemy1_tex);
}



#endif