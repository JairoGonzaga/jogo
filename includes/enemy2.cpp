#include <stdio.h>
#include "raylib.h"
#include "enemy2.h"
#include <math.h>

#define qtdenemy2 2 // quantos inimigos q seguem o jogador serao inicializados

Texture2D enemy2_tex;
enemy2_data enemy2[qtdenemy2] = {0}; // vetor de inimigos q seguem (de structs)
float timer_enemy2 = 0.0f;
int maxframes_enemy2 = 15;
int frame_enemy2 = 0;
float frameWidth_enemy2;
float frameHeight_enemy2;

// inicializacao dos inimigos que perseguem o jogador
void enemy2_init()
{

	enemy2_tex = LoadTexture("resources/enemy2_tex.png");
	frameWidth_enemy2 = (float)enemy2_tex.width / 11;
	frameHeight_enemy2 = enemy2_tex.height;

	for (int i = 0; i < qtdenemy2; i++)
	{

		// coordenadas dos inimigos (so um exemplo, pode tirar do loop pra colocar coordenadas diferentes aleatorias)
		enemy2[i].pos.x = 50 + (800 * i);
		enemy2[i].pos.y = pow((-50), i); // coloquei potencia pra ele aparecer as vzs de baixo e as vzs de cima (resultado par ou impar)

		// tamanhos e cor do retangulo
		enemy2[i].recfps.width = frameWidth_enemy2;
		enemy2[i].recfps.height = frameHeight_enemy2;
		enemy2[i].rechitbox.width = frameWidth_enemy2;
		enemy2[i].rechitbox.height = frameHeight_enemy2;
	}
}

// movimento dos inimigos que perseguem durante o jogo
Rectangle enemy2_movement(float playerX, float playerY)
{

	for (int i = 0; i < qtdenemy2; i++)
	{

		// quando a posicao X ou Y do jogador eh maior que a posicao equivalente do inimigo,
		// o inimigo anda mais nessa direcao. caso contrario, ele volta.
		if (playerX > enemy2[i].pos.x)
			enemy2[i].pos.x += 0.2;	  // indo para a direita
		enemy2[i].rechitbox.x += 0.2; // indo para a direita
		if (playerX < enemy2[i].pos.x)
			enemy2[i].pos.x -= 0.2;	  // indo para a esquerda
		enemy2[i].rechitbox.x -= 0.2; // indo para a esquerda
		if (playerY > enemy2[i].pos.y)
			enemy2[i].pos.y += 0.2;	  // indo para baixo
		enemy2[i].rechitbox.y += 0.2; // indo para baixo
		if (playerY < enemy2[i].pos.y)
			enemy2[i].pos.y -= 0.2;	  // indo para cima
		enemy2[i].rechitbox.y -= 0.2; // indo para cima
		enemy2[i].rechitbox.x = enemy2[i].pos.x;
		enemy2[i].rechitbox.y = enemy2[i].pos.y;
	}

	//   enemy2
	for (int i = 0; i < qtdenemy2; i++)
	{
		if (playerX > enemy2[i].pos.x)
		{ // indo para a direita
			enemy2[i].recfps.width = -abs(enemy2[i].recfps.width);
			// enemy2[i].recfps.x = -frameWidth_enemy2 * frame_enemy2;
		}

		if (playerX < enemy2[i].pos.x)
		{ // indo para a esquerda
			enemy2[i].recfps.width = abs(enemy2[i].recfps.width);
		}
		enemy2[i].recfps.x = frameWidth_enemy2 * frame_enemy2;
		timer_enemy2 += GetFrameTime();

		if (timer_enemy2 >= 0.2f)
		{
			timer_enemy2 = 0.0f;
			frame_enemy2 += 1;
		}
	}

	frame_enemy2 = frame_enemy2 % maxframes_enemy2;
	for (int i = 0; i < 2; i++)
	{
		return enemy2[i].rechitbox;
	}
}

void draw_enemy2()
{
	for (int i = 0; i < qtdenemy2; i++)
	{
		DrawTextureRec(enemy2_tex, enemy2[i].recfps, (Vector2){enemy2[i].pos.x, enemy2[i].pos.y}, WHITE);
	}
}

void unload_enemy2_tex()
{
	UnloadTexture(enemy2_tex);
}
