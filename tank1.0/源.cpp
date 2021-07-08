//#include<iostream>
//#include <windows.h>
//#include <time.h>
//#include <conio.h>
//#define   UP    0
//#define   DOWN  1
//#define   LEFT  2
//#define   RIGHT 3
//
//#define 空地   0
//#define 障碍物 1
//#define 草地 3 
//#define 子弹 4
//typedef struct _TANKINFO
//{
//	COORD pos;
//	int nDirection;
//	int TankY;
//	int TankX;
//}TANKINFO,*PTANKINFO;
//TANKINFO objTank;
//int map[30][30] = {};
//int map_x = 30;
//int map_y = 30;
//
//
//char g_TankShape[4][3][3] = {
//	{
//		{ 0, 1, 0 },		// 方向向上的坦克 
//		{ 1, 1, 1 },
//		{ 1, 0, 1 },
//	},
//	{						// 方向向下的坦克 
//		{ 1, 0, 1 },
//		{ 1, 1, 1 },
//		{ 0, 1, 0 },
//	},
//	{						// 方向向左的坦克
//		{ 0, 1, 1 },
//		{ 1, 1, 0 },
//		{ 0, 1, 1 },
//	},
//	{						// 方向向右的坦克
//		{ 1, 1, 0 },
//		{ 0, 1, 1 },
//		{ 1, 1, 0 },
//	}
//};
//
//void PrintChar(int High, int Wide, const char* pszChar, WORD wArr) {
//	// 设置光标属性
//	CONSOLE_CURSOR_INFO cci;
//	cci.dwSize = 1;
//	cci.bVisible = FALSE;	// 是否显示光标
//	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
//	// 设置坐标
//	COORD loc;
//	loc.X = Wide * 2; // x的值是Wide的2倍
//	loc.Y = High;
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wArr);
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), loc);
//	printf(pszChar); //打印时需要注意有些特殊字符是占两个字节
//}
//
//
//void ndrawmap() {
//	for (int i = 0; i < map_x; i++)
//	{
//		for (int j = 0; j < map_y; j++)
//		{
//			if (i == 0 || j == 0 || i == map_x - 1 || j == map_y - 1) {
//				map[i][j] = 障碍物;
//			}
//			else
//			{
//				map[i][j] = 空地;
//			}
//		}
//	}
//	for (int i = 0; i < map_x; i++)
//	{
//		for (int j = 0; j < map_y; j++)
//		{
//			if (map[i][j] == 障碍物)
//			{
//				PrintChar(i, j, "■", 2 | 9);
//			}
//		}
//	}
//}
//
//
//void DrawTank(TANKINFO objTank) {  //画坦克
//	for (int nPosY = objTank.TankY - 1; nPosY < objTank.TankY + 2; nPosY++)
//	{
//		for (int nPosX = objTank.TankX - 1; nPosX < objTank.TankX + 2; nPosX++)
//		{
//			int nX = nPosX - objTank.TankX + 1;
//			int nY = nPosY - objTank.TankY + 1;
//			if (g_TankShape[objTank.nDirection][nY][nX])
//			{
//				PrintChar(nPosY, nPosX, "□", 2 | 8);
//			}
//		}
//	}
//}
//void ClsTank(TANKINFO objTank) {   //擦除坦克   
//	for (int nPosY = objTank.TankY - 1; nPosY < objTank.TankY + 2; nPosY++) {
//		for (int nPosX = objTank.TankX - 1; nPosX < objTank.TankX + 2; nPosX++)
//		{
//			int nX = nPosX - objTank.TankX + 1;
//			int nY = nPosY - objTank.TankY + 1;
//			if (g_TankShape[objTank.nDirection][nY][nX]) {
//				PrintChar(nPosY, nPosX, "  ", 2 | 8);
//			}
//		}
//	}
//}
//int main() {
//	TANKINFO objTank = {};
//	objTank.TankX = 3;
//	objTank.TankY = 3;
//	objTank.nDirection = DOWN;  //向下
//
//	TANKINFO old_objTank = objTank;
//	ndrawmap();
//	DrawTank(objTank);
//	while (1) {
//		if (!_kbhit())
//		{
//			continue;
//		}
//		char key = _getch();
//		switch (key)
//		{
//		case 'w':
//			if (objTank.nDirection != UP)
//			{
//				objTank.nDirection = UP;
//			}
//			else
//				objTank.TankY--;
//			break;
//		case 's':
//			if (objTank.nDirection != DOWN)
//			{
//				objTank.nDirection = DOWN;
//			}
//			else
//				objTank.TankY++;
//
//			break;
//		case 'a':
//			if (objTank.nDirection != LEFT)
//			{
//				objTank.nDirection = LEFT;
//			}
//			else
//				objTank.TankX--;
//			objTank.  nDirection = LEFT;
//			break;
//		case 'd':
//			if (objTank.nDirection != RIGHT)
//			{
//				objTank.nDirection = RIGHT;
//			}
//			else
//				objTank.TankX++;
//			break;
//		default:
//			continue;
//		}
//		//if(map[TankX][TankY]==)
//		ClsTank(old_objTank);
//		DrawTank(objTank);
//		old_objTank = objTank;
//	}
//	system("pause");
//	return 0;
//}