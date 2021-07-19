#pragma once
// ÿһ���ļ���Ӧ��ֱ�Ӱ����Լ���Ҫ��ͷ�ļ�
#include "map.h"
#include <time.h>
#include <windows.h>
#include <stdbool.h>

enum
{
	�� = 0, ��, ��, ��

};
typedef struct _TANKINFO
{
	COORD point;
	int nspeed;
	int nDir;
	clock_t end;
	clock_t end2;

}TANKINFO, * PTANKINFO;
extern TANKINFO Tank;

void WriteChar(int High, int Wide, const char* Char, WORD wArr);
int GetKeyInput();
void DrawTank(PTANKINFO Tank, bool show);
void InitTank(PTANKINFO Tank, int x, int y, int dir);

bool TankCheak(PTANKINFO Tank);
void MoveTank(PTANKINFO Tank, int Dir);
