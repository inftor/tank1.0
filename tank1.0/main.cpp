#include<iostream>
#include <windows.h>
#include <time.h>
#include <conio.h>

int g_nMap[40][40] = {};

#define �� 0
#define �� 1
#define �� 2
#define �� 3
typedef struct _TANKINFO
{
	COORD pos;
	int nDir;
	int map_x;
	int map_y;
}TANKINFO,*PTANKINFO;
TANKINFO g_TANK;

void WriteChar(int High ,int Wide ,const char* Char ,WORD wArr) {
	CONSOLE_CURSOR_INFO cci;
	cci.bVisible = FALSE;//�Ƿ���ʾ���
	cci.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
	COORD loc;
	loc.X = Wide * 2;
	loc.Y = High;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wArr);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), loc);
	printf(Char);
}

int GetKeyInput()
{
	if (_kbhit())
		return _getch();
	return 0;
}

void DrawTank(/*TANKINFO std=0*/)
{
	int y = g_TANK.pos.X;
	int x = g_TANK.pos.Y;
	switch (g_TANK.nDir)
	{
	case ��:
	{
		WriteChar(x - 1, y - 1, "  ��  ", 2 | 8);
		WriteChar(x - 1, y, "������", 2 | 8);
		WriteChar(x - 1, y + 1, "��  ��", 2 | 8);
	}
		break;
	case ��:
	{
		WriteChar(x - 1, y - 1, "��  ��", 2 | 8);
		WriteChar(x - 1, y, "������", 2 | 8);
		WriteChar(x - 1, y + 1, "  ��  ", 2 | 8);
	}
		break;

	case ��:
	{
		WriteChar(x - 1, y - 1, "  ����", 2 | 8);
		WriteChar(x - 1, y, "����  ", 2 | 8);
		WriteChar(x - 1, y + 1, "  ����", 2 | 8);
	}
		break;

	case ��:
	{
		WriteChar(x - 1, y - 1, "����  ", 2 | 8);
		WriteChar(x - 1, y, "  ����", 2 | 8);
		WriteChar(x - 1, y + 1, "����  ", 2 | 8);
	}
		break;

	default:
		break;
	}
}


void Get()
{
	g_TANK.pos.X = 20;
	g_TANK.pos.Y = 20;
	g_TANK.nDir = ��;
	int Iit = 0;
	while (true)
	{
		Iit = GetKeyInput();
		switch (Iit)
		{
		case 'w':
		{
			g_TANK.nDir = ��;
			g_TANK.pos.Y--;
		}
			break;
		case 's':
		{
			g_TANK.nDir = ��;
			g_TANK.pos.Y++;
		}
			break;
		case 'a':
		{
			g_TANK.nDir = ��;
			g_TANK.pos.X--;
		}
			break;
		case 'd':
		{
			g_TANK.nDir = ��;
			g_TANK.pos.X++;
		}
			break;
		case ' ':

			break;

		default:
			break;
		}
		DrawTank();
	}  


	
}




void DrawMap()
{
	 
}



int main() {
	system("mode con cols=120 lines=50");
	SetConsoleTitle(TEXT("̹�˴�ս"));
	WriteChar(10 - 1, 20,   "����  ", 2 | 8);
	WriteChar(10 , 20,     "  ����", 2 | 8);
	WriteChar(10 +1, 20, "����  ", 2 | 8);
	Get();


}