//#include<iostream>
//#include <windows.h>
//#include <time.h>
//#include <conio.h>
//#define   UP    0
//#define   DOWN  1
//#define   LEFT  2
//#define   RIGHT 3
//
//#define �յ�   0
//#define �ϰ��� 1
//#define �ݵ� 3 
//#define �ӵ� 4
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
//		{ 0, 1, 0 },		// �������ϵ�̹�� 
//		{ 1, 1, 1 },
//		{ 1, 0, 1 },
//	},
//	{						// �������µ�̹�� 
//		{ 1, 0, 1 },
//		{ 1, 1, 1 },
//		{ 0, 1, 0 },
//	},
//	{						// ���������̹��
//		{ 0, 1, 1 },
//		{ 1, 1, 0 },
//		{ 0, 1, 1 },
//	},
//	{						// �������ҵ�̹��
//		{ 1, 1, 0 },
//		{ 0, 1, 1 },
//		{ 1, 1, 0 },
//	}
//};
//
//void PrintChar(int High, int Wide, const char* pszChar, WORD wArr) {
//	// ���ù������
//	CONSOLE_CURSOR_INFO cci;
//	cci.dwSize = 1;
//	cci.bVisible = FALSE;	// �Ƿ���ʾ���
//	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
//	// ��������
//	COORD loc;
//	loc.X = Wide * 2; // x��ֵ��Wide��2��
//	loc.Y = High;
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wArr);
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), loc);
//	printf(pszChar); //��ӡʱ��Ҫע����Щ�����ַ���ռ�����ֽ�
//}
//
//
//void ndrawmap() {
//	for (int i = 0; i < map_x; i++)
//	{
//		for (int j = 0; j < map_y; j++)
//		{
//			if (i == 0 || j == 0 || i == map_x - 1 || j == map_y - 1) {
//				map[i][j] = �ϰ���;
//			}
//			else
//			{
//				map[i][j] = �յ�;
//			}
//		}
//	}
//	for (int i = 0; i < map_x; i++)
//	{
//		for (int j = 0; j < map_y; j++)
//		{
//			if (map[i][j] == �ϰ���)
//			{
//				PrintChar(i, j, "��", 2 | 9);
//			}
//		}
//	}
//}
//
//
//void DrawTank(TANKINFO objTank) {  //��̹��
//	for (int nPosY = objTank.TankY - 1; nPosY < objTank.TankY + 2; nPosY++)
//	{
//		for (int nPosX = objTank.TankX - 1; nPosX < objTank.TankX + 2; nPosX++)
//		{
//			int nX = nPosX - objTank.TankX + 1;
//			int nY = nPosY - objTank.TankY + 1;
//			if (g_TankShape[objTank.nDirection][nY][nX])
//			{
//				PrintChar(nPosY, nPosX, "��", 2 | 8);
//			}
//		}
//	}
//}
//void ClsTank(TANKINFO objTank) {   //����̹��   
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
//	objTank.nDirection = DOWN;  //����
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