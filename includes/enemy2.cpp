#include <stdio.h>
#include "raylib.h"
#include "enemy2.h"
#include <math.h>

#ifndef ENEMY2_CPP
#define ENEMY2_CPP

Texture2D enemy2_tex;
enemy2_data enemy2[42] = {0}; // vetor de inimigos q seguem (de structs)
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

	// coordenadas dos inimigos mapa1
	enemy2[0].pos.x = 430;
	enemy2[0].pos.y = 4;

	enemy2[1].pos.x = 735;
	enemy2[1].pos.y = 584;

	enemy2[2].pos.x = 1270;
	enemy2[2].pos.y = 2;

	enemy2[3].pos.x = 1825;
	enemy2[3].pos.y = -15;

	enemy2[4].pos.x = 1685;
	enemy2[4].pos.y = 609;

	enemy2[5].pos.x = 2515;
	enemy2[5].pos.y = 338;

	enemy2[6].pos.x = 3125;
	enemy2[6].pos.y = 63;

	enemy2[7].pos.x = 3690;
	enemy2[7].pos.y = 661;

	enemy2[8].pos.x = 3840;
	enemy2[8].pos.y = 113;

	enemy2[9].pos.x = 4540;
	enemy2[9].pos.y = 155;

	enemy2[10].pos.x = 4585;
	enemy2[10].pos.y = 543;

	enemy2[11].pos.x = 5495;
	enemy2[11].pos.y = 266;

	// coordenadas dos inimigos mapa2
	enemy2[12].pos.x = 395;
	enemy2[12].pos.y = 184;

	enemy2[13].pos.x = 410;
	enemy2[13].pos.y = 859;

	enemy2[14].pos.x = 610;
	enemy2[14].pos.y = 336;

	enemy2[15].pos.x = 1315;
	enemy2[15].pos.y = 390;

	enemy2[16].pos.x = 1740;
	enemy2[16].pos.y = 75;

	enemy2[17].pos.x = 1470;
	enemy2[17].pos.y = 871;

	enemy2[18].pos.x = 2015;
	enemy2[18].pos.y = 1005;

	enemy2[19].pos.x = 2585;
	enemy2[19].pos.y = 165;

	enemy2[20].pos.x = 2770;
	enemy2[20].pos.y = 863;

	enemy2[21].pos.x = 2160;
	enemy2[21].pos.y = 421;

	enemy2[22].pos.x = 3595;
	enemy2[22].pos.y = 481;

	enemy2[23].pos.x = 4005;
	enemy2[23].pos.y = 831;

	enemy2[24].pos.x = 4405;
	enemy2[24].pos.y = 142;

	enemy2[25].pos.x = 5065;
	enemy2[25].pos.y = 606;

	enemy2[26].pos.x = 5780;
	enemy2[26].pos.y = 1005;

	enemy2[27].pos.x = 5780;
	enemy2[27].pos.y = 105;

	enemy2[28].pos.x = 6620;
	enemy2[28].pos.y = -41;

	enemy2[29].pos.x = 7230;
	enemy2[29].pos.y = 287;

	enemy2[30].pos.x = 6745;
	enemy2[30].pos.y = 698;

	enemy2[31].pos.x = 7670;
	enemy2[31].pos.y = 288;

	enemy2[32].pos.x = 7840;
	enemy2[32].pos.y = 1005;

	enemy2[33].pos.x = 8680;
	enemy2[33].pos.y = 873;

	enemy2[34].pos.x = 8320;
	enemy2[34].pos.y = 253;

	enemy2[35].pos.x = 8735;
	enemy2[35].pos.y = 231;

	enemy2[36].pos.x = 9295;
	enemy2[36].pos.y = 206;

	enemy2[37].pos.x = 9380;
	enemy2[37].pos.y = 722;

	enemy2[38].pos.x = 8995;
	enemy2[38].pos.y = 803;

	enemy2[39].pos.x = 9505;
	enemy2[39].pos.y = 16;

	enemy2[40].pos.x = 10105;
	enemy2[40].pos.y = 226;

	enemy2[41].pos.x = 10030;
	enemy2[41].pos.y = 705;

	for (int i = 0; i < 42; i++)
	{

		// tamanho dos frames
		enemy2[i].recfps.width = frameWidth_enemy2;
		enemy2[i].recfps.height = frameHeight_enemy2;
		enemy2[i].rechitbox.width = frameWidth_enemy2;
		enemy2[i].rechitbox.height = frameHeight_enemy2;
	}
}

// movimento dos inimigos que perseguem durante o jogo
void enemy2_movement(float playerX, float playerY)
{

	for (int i = 0; i < 42; i++)
	{

		// quando a posicao X ou Y do jogador eh maior que a posicao equivalente do inimigo,
		// o inimigo anda mais nessa direcao. caso contrario, ele volta.
		if (playerX > enemy2[i].pos.x && abs(enemy2[i].pos.x - playerX) <= 600)
			enemy2[i].pos.x += 0.8; // indo para a direita
		if (playerX < enemy2[i].pos.x && abs(enemy2[i].pos.x - playerX) <= 600)
			enemy2[i].pos.x -= 0.8; // indo para a esquerda
		if (playerY > enemy2[i].pos.y && abs(enemy2[i].pos.x - playerX) <= 600)
			enemy2[i].pos.y += 0.8;	  // indo para baixo
		enemy2[i].rechitbox.y += 0.8; // indo para baixo
		if (playerY < enemy2[i].pos.y && abs(enemy2[i].pos.x - playerX) <= 600)
			enemy2[i].pos.y -= 0.8; // indo para cima
		enemy2[i].rechitbox.x = enemy2[i].pos.x;
		enemy2[i].rechitbox.y = enemy2[i].pos.y;
	}

	//   enemy2
	for (int i = 0; i < 42; i++)
	{ // animation
		if (playerX > enemy2[i].pos.x)
		{
			enemy2[i].recfps.width = -abs(enemy2[i].recfps.width);
		}

		if (playerX < enemy2[i].pos.x)
		{
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
}

void draw_enemy2_map1()
{
	for (int i = 0; i < 12; i++)
	{
		DrawTextureRec(enemy2_tex, enemy2[i].recfps, (Vector2){enemy2[i].pos.x, enemy2[i].pos.y}, WHITE);
	}
}

void draw_enemy2_map2()
{
	for (int i = 12; i < 42; i++)
	{
		DrawTextureRec(enemy2_tex, enemy2[i].recfps, (Vector2){enemy2[i].pos.x, enemy2[i].pos.y}, WHITE);
	}
}

void unload_enemy2_tex()
{
	UnloadTexture(enemy2_tex);
}

#endif
