#ifndef TRANSITION_C
#define TRANSITION_C

#include "raylib.h"

int transition_num=1;

int transition(Rectangle* playerhitbox, Vector2* posicao, int* jumptimer){

    Rectangle finalf1, finalf2;

    finalf1.x=173*32;
    finalf1.y=23*32;
    finalf1.width=2*32;
    finalf1.height=1*32;

    finalf2.x=76*32;
    finalf2.y=1*32;
    finalf2.width=2*32;
    finalf2.height=2*32;


    if(transition_num==1)
        if(CheckCollisionRecs(*playerhitbox, finalf1)==1){
            transition_num=2;
            *jumptimer=40;
            *posicao = (Vector2) {14,15};
            (*playerhitbox).x = (*posicao).x;
            (*playerhitbox).y = (*posicao).y;
        }
        
    if(transition_num==2)
        if(CheckCollisionRecs(*playerhitbox, finalf2)==1){
            //acaba o jogo
        }

    return transition_num;
}

#endif


