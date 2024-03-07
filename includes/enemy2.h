#ifndef enemy2_h
#define enemy2_h

// estrutura do inimigo tipo 2 (inimigo que persegue a direcao do jogador)
typedef struct
{
    Rectangle rechitbox;
    Rectangle recfps;
    Vector2 pos;

} enemy2_data;

void enemy2_init();
Rectangle enemy2_movement(float playerX, float playerY);
void draw_enemy2();
void unload_enemy2_tex();

#endif