#pragma once
#include <stdio.h>
#include <windows.h>
// 用来表示玩家游戏场景的高度和宽度
enum {
	宽 = 40,
	高 = 40
};


extern int g_map[高][宽];

// 用来说明游戏中可能存在的所有地形
enum {
	空地 = 0,
	边界 = 1,
	玩家 = 2,
	子弹 = 3,
	砖墙 = 4,
	钢墙 = 5
};


void WriteChar(int High, int Wide, const char* Char, WORD wArr);

void DrawMap();
