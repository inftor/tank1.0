#include"map.h"

	
int g_map[��][��] = {};



void WriteChar(int High, int Wide, const char* Char, WORD wArr) {
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




void DrawMap()
{
	for (int i = 0; i < ��; i++)
	{
		for (int j = 0; j < ��; j++)
		{
			// �����ǰ�����������࣬���ǽ�����Ϊ�߽�
			if (i == 0 || j == 0 || i == �� - 1 || j == �� - 1)
			{
				g_map[i][j] = �߽�;
				WriteChar(i, j, "��", 7);
			}
			else
			{
				g_map[i][j] = �յ�;
				WriteChar(i, j, "  ", 0);
			}

		}
	}

	for (int i = 10; i < 20; i++)
	{
		for (int j = 14; j < 19; j++)
		{
			WriteChar(i, j, "77", 2);
			g_map[i][j] = שǽ;
		}
	}
	for (int i = 10; i < 20; i++)
	{
		for (int j = 19; j < 24; j++)
		{
			WriteChar(i, j, "88", 2);
			g_map[i][j] = ��ǽ;
		}
	}
}
