#ifndef ENEMY_H
#define ENEMY_H

typedef struct{
    Rectangle rechitbox;
    Rectangle recfps;
    bool moveright;
}
    enemy1_data;

void enemy1_init();
void enemy1_movement();
void draw_enemy1_map1();
void draw_enemy1_map2();
void unload_enemy1_tex();

#endif