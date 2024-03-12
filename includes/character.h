#ifndef CHARACTER_H
#define CHARACTER_H

#include "raylib.h"
#include <math.h>
#include <stdio.h>

void camera_settings(int *screenWidth, int *screenHeight, int transition);
void character_init();
void character_movement();
void draw_character();
void unload_charactertex();
void charac_dead();
int colisaoinimigosfase1();
int colisaoinimigosfase2();

#endif