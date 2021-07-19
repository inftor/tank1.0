#include"map.h"

	
int g_map[高][宽] = {};



void WriteChar(int High, int Wide, const char* Char, WORD wArr) {
	CONSOLE_CURSOR_INFO cci;
	cci.bVisible = FALSE;//是否显示光标
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
	for (int i = 0; i < 高; i++)
	{
		for (int j = 0; j < 宽; j++)
		{
			// 如果当前是数组的最外侧，我们将它作为边界
			if (i == 0 || j == 0 || i == 高 - 1 || j == 宽 - 1)
			{
				g_map[i][j] = 边界;
				WriteChar(i, j, "□", 7);
			}
			else
			{
				g_map[i][j] = 空地;
				WriteChar(i, j, "  ", 0);
			}

		}
	}

	for (int i = 10; i < 20; i++)
	{
		for (int j = 14; j < 19; j++)
		{
			WriteChar(i, j, "77", 2);
			g_map[i][j] = 砖墙;
		}
	}
	for (int i = 10; i < 20; i++)
	{
		for (int j = 19; j < 24; j++)
		{
			WriteChar(i, j, "88", 2);
			g_map[i][j] = 钢墙;
		}
	}
}
