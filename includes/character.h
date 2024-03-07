#ifndef CHARACTER_H
#define CHARACTER_H

#include "raylib.h"
#include <math.h>
#include <stdio.h>

void camera_settings();
void character_init();
void character_movement();
void draw_character();
void unload_charactertex();
void charac_dead();
void colisaoinimigos();

#endif