//#include<iostream>
//#include <windows.h>
//#include <time.h>
//#include <conio.h>
//
//#define 空地   0
//#define 障碍物 1
//#define 草地   3 
//#define 坦克   6
//
//#define 上 0
//#define 下 1
//#define 左 2
//#define 右 3
//int g_nMap[40][40] = {};
//int map_x = 40;
//int map_y = 40;
//
//
//void WriteChar(int High, int Wide, const char* Char, WORD wArr) {
//	CONSOLE_CURSOR_INFO cci;
//	cci.bVisible = FALSE;//是否显示光标
//	cci.dwSize = 1;
//	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
//	COORD loc;
//	loc.X = Wide * 2;
//	loc.Y = High;
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wArr);
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), loc);
//	printf(Char);
//}
//
//
//
//void ndrawmap() {
//	for (int i = 0; i < map_x; i++)
//	{
//		for (int j = 0; j < map_y; j++)
//		{
//			if (i == 0 || j == 0 || i == map_x - 1 || j == map_y - 1) {
//				g_nMap[i][j] = 障碍物;
//			}
//			
//			else
//			{
//				g_nMap[i][j] = 空地;
//			}
//		}
//	}
//
//
//
//	for (int i = 5; i < 10; i++)
//	{
//		for (int j = 4; j < 8; j++)
//		{
//				g_nMap[i][j] = 障碍物;
//
//		}
//	}
//	for (int i = 25; i < 29; i++)
//	{
//		for (int j = 23; j < 27; j++)
//		{
//			g_nMap[i][j] = 障碍物;
//		}
//	}
//	for (int i = 27; i < 29; i++)
//	{
//		for (int j = 2; j < 30; j++)
//		{
//			g_nMap[i][j] = 草地;
//			WriteChar(i, j, "≈", 2 | 2);
//		}
//	}
//
//
//	for (int i = 11; i < 16; i++)
//	{
//		for (int j = 22; j < 30; j++)
//		{
//			g_nMap[i][j] = 空地;
//			WriteChar(i, j, "※", 2 | 4);
//		}
//	}
//
//
//
//	for (int i = 0; i < map_x; i++)
//	{
//		for (int j = 0; j < map_y; j++)
//		{
//			if (g_nMap[i][j] == 障碍物)
//			{
//				WriteChar(i, j, "■", 2 | 9);
//			}
//		}
//	}
//
//}
//
//
//typedef struct _TANKINFO
//{
//	COORD pos;
//	int nDir;
//	int map_x;
//	int map_y;
//}TANKINFO,*PTANKINFO;
//TANKINFO g_TANK;
//TANKINFO g_TANKB;
//
//
//typedef struct _BULLINFO
//{
//	COORD pos;
//	int nDir;
//	int map_x;
//	int map_y;
//	int nLastClock;
//	int nSpeed;
//	char a[3];
//	int nBULLNUM[100];
//	int nZT;
//}BULLINFO, * PBULLINFO;
//BULLINFO g_BULL;
//
//
//int GetKeyInput()
//{
//	if (_kbhit())
//		return _getch();
//	return 0;
//}
//
//void DrawTank(/*TANKINFO std=0*/)
//{
//	int x = g_TANK.pos.X;
//	int y = g_TANK.pos.Y;
//	g_nMap[x][y] = 坦克;
//	switch (g_TANK.nDir)
//	{
//	case 上:
//	{
//
//		WriteChar(x - 1, y - 1, "  □  ", 2 | 8);
//		WriteChar(x, y - 1, "□□□", 2 | 8);
//		WriteChar(x + 1, y - 1, "□  □", 2 | 8);
//
//
//
//	}			  
//		break;	  
//	case 下:	 
//	{			  
//		WriteChar(x - 1, y - 1, "□  □", 2 | 8);
//		WriteChar(x, y - 1,     "□□□", 2 | 8);
//		WriteChar(x + 1, y - 1, "  □  ", 2 | 8);
//
//	}			  
//		break;	  
//				  
//	case 左:	 
//	{			  
//		WriteChar(x - 1, y - 1, "  □□", 2 | 8);
//		WriteChar(x, y - 1,     "□□  ", 2 | 8);
//		WriteChar(x + 1, y - 1, "  □□", 2 | 8);
//	}
//		break;
//
//	case 右:
//	{
//		WriteChar(x - 1, y - 1, "□□  ", 2 | 8);
//		WriteChar(x, y - 1,     "  □□", 2 | 8);
//		WriteChar(x + 1, y - 1, "□□  ", 2 | 8);
//	}
//		break;
//
//	default:
//		break;
//	}
//}
//void CleanTank()
//{
//	int x = g_TANK.pos.X;
//	int y = g_TANK.pos.Y;
//	g_nMap[x][y] = 空地;
//	WriteChar(x - 1, y - 1, "      ", 2 | 8);
//	WriteChar(x, y - 1, "      ", 2 | 8);
//	WriteChar(x + 1, y - 1, "      ", 2 | 8);
//	//WriteChar(x + 1, y, "          ", 2 | 8);
//
//
//}
//
//
//void CleanBULL() {
//	WriteChar(g_BULL.pos.X, g_BULL.pos.Y, "  ", 2 | 8);
//}
//void DrawBULL()
//{
//	WriteChar(g_BULL.pos.X, g_BULL.pos.Y, "¤", 2 | 8);
//}
//
//void MoveBULL()
//{	
//
//		if (clock() - g_BULL.nLastClock > g_BULL.nSpeed)
//		{
//			CleanBULL();
//			g_BULL.nLastClock = clock();
//			switch (g_BULL.nDir)
//			{
//			case 上:
//			{
//				if (g_nMap[g_BULL.pos.X - 1][g_BULL.pos.Y] == 障碍物)
//				{
//				}
//				else if (g_nMap[g_BULL.pos.X - 1][g_BULL.pos.Y] == 草地)
//				{
//					g_nMap[g_BULL.pos.X - 1][g_BULL.pos.Y] = 空地;
//					g_BULL.nZT = 0;
//				}
//				else
//				{
//					g_BULL.pos.X--;
//					DrawBULL();
//				}
//
//
//			}
//			break;
//			case 下:
//			{
//				if (g_nMap[g_BULL.pos.X + 1][g_BULL.pos.Y] == 障碍物)
//				{
//				}
//				else if (g_nMap[g_BULL.pos.X + 1][g_BULL.pos.Y] == 草地)
//				{
//					g_nMap[g_BULL.pos.X + 1][g_BULL.pos.Y] = 空地;
//					g_BULL.nZT = 0;
//				}
//				else
//				{
//					g_BULL.pos.X++;
//					DrawBULL();
//				}
//
//			}
//			break;
//			case 左:
//			{
//				if (g_nMap[g_BULL.pos.X][g_BULL.pos.Y - 1] == 障碍物)
//				{
//				}
//				else if (g_nMap[g_BULL.pos.X][g_BULL.pos.Y - 1] == 草地)
//				{
//					g_nMap[g_BULL.pos.X][g_BULL.pos.Y - 1] = 空地;
//					g_BULL.nZT = 0;
//				}
//				else
//				{
//					g_BULL.pos.Y--;
//					DrawBULL();
//				}
//
//			}
//			break;
//			case 右:
//			{
//				if (g_nMap[g_BULL.pos.X][g_BULL.pos.Y + 1] == 障碍物)
//				{
//				}
//				else if (g_nMap[g_BULL.pos.X][g_BULL.pos.Y + 1] == 草地)
//				{
//					g_nMap[g_BULL.pos.X][g_BULL.pos.Y + 1] = 空地;
//					g_BULL.nZT = 0;
//				}
//				else
//				{
//					g_BULL.pos.Y++;
//					DrawBULL();
//				}
//
//			}
//			break;
//			default:
//				break;
//			}
//		}
//	
//}
//
//
//bool TankCheak()  //检测坦克前方障碍函数,参量为假坐标。返值1为可通过,返值0为阻挡(人机共用)
//{
//	switch (g_TANK.nDir)                    //direction变量   1上，2下，3左，4右
//	{
//	case 上:
//		if (g_nMap[g_TANK.pos.X - 2][g_TANK.pos.Y] == 0 && g_nMap[g_TANK.pos.X - 2][g_TANK.pos.Y - 1] == 0 && g_nMap[g_TANK.pos.X - 2][g_TANK.pos.Y + 1] == 0)
//			return 1;
//		else
//			return 0;
//	case 下:
//		if (g_nMap[g_TANK.pos.X + 2][g_TANK.pos.Y] == 0 && g_nMap[g_TANK.pos.X + 2][g_TANK.pos.Y - 1] == 0 && g_nMap[g_TANK.pos.X + 2][g_TANK.pos.Y+ 1] == 0)
//			return 1;
//		else
//			return 0;
//	case 左:
//		if (g_nMap[g_TANK.pos.X][g_TANK.pos.Y - 2] == 0 && g_nMap[g_TANK.pos.X - 1][g_TANK.pos.Y - 2] == 0 && g_nMap[g_TANK.pos.X + 1][g_TANK.pos.Y - 2] == 0)
//			return 1;
//		else
//			return 0;
//	case 右:
//		if (g_nMap[g_TANK.pos.X][g_TANK.pos.Y + 2] == 0 && g_nMap[g_TANK.pos.X - 1][g_TANK.pos.Y + 2] == 0 && g_nMap[g_TANK.pos.X + 1][g_TANK.pos.Y + 2] == 0)
//			return 1;
//		else
//			return 0;
//	default:
//		printf("错误！！");
//		Sleep(5000);
//		return 0;
//	}
//}
//
//
//
//
//int Get()
//{
//	g_TANK.pos.X = 20;
//	g_TANK.pos.Y = 20;
//	g_TANK.nDir = 左;
//	int Iit = 0;
//	g_BULL.pos.X = g_TANK.pos.X;
//	g_BULL.pos.Y = g_TANK.pos.Y;
//	DrawTank();
//	ndrawmap();
//	while (true)
//	{
//
//		Sleep(20);
//		CleanTank();
//		CleanBULL();
//		Iit = GetKeyInput();
//
//
//
//
//
//		if (TankCheak() == 0)
//		{
//		}
//		else
//		{
//
//			switch (Iit)
//			{
//			case 'w':
//			{
//
//				if (g_TANK.nDir != 上)
//				{
//					g_TANK.nDir = 上;
//				}
//				else
//				{
//					g_TANK.pos.X--;
//				}
//
//			}
//			break;
//			case 's':
//			{
//
//				////g_TANK.nDir = 下;
//				//if (TankCheak() == 0)
//				//{
//				//	g_TANK.nDir = 上;
//				//}
//				if (g_TANK.nDir != 下)
//				{
//					g_TANK.nDir = 下;
//				}
//				else
//				{
//					g_TANK.pos.X++;
//				}
//			}
//			break;
//			case 'a':
//			{
//
//				//g_TANK.nDir = 左;
//				/*if (TankCheak() == 0)
//				{
//					g_TANK.nDir = 右;
//				}*/
//				if (g_TANK.nDir != 左)
//				{
//					g_TANK.nDir = 左;
//				}
//				else
//				{
//					g_TANK.pos.Y--;
//				}
//
//			}
//			break;
//			case 'd':
//			{
//
//				//g_TANK.nDir = 右;
//				/*if (TankCheak() == 0)
//				{
//					g_TANK.nDir = 左;
//				}*/
//				if (g_TANK.nDir != 右)
//				{
//					g_TANK.nDir = 右;
//				}
//				else
//				{
//					g_TANK.pos.Y++;
//				}
//
//			}
//			break;
//			case 'j':
//			{
//				g_BULL.nZT = 0;
//				int a = 1;
//				g_BULL.nSpeed = 20;
//				g_BULL.nLastClock = clock();
//				switch (g_BULL.nDir)
//				{
//				case 上:
//				{
//					g_BULL.nDir = g_TANK.nDir;
//					g_BULL.pos.X = g_TANK.pos.X;
//					g_BULL.pos.Y = g_TANK.pos.Y;
//				}
//				break;
//				case 下:
//				{
//					g_BULL.nDir = g_TANK.nDir;
//					g_BULL.pos.X = g_TANK.pos.X;
//					g_BULL.pos.Y = g_TANK.pos.Y;
//				}
//				break;
//				case 左:
//				{
//					g_BULL.nDir = g_TANK.nDir;
//					g_BULL.pos.X = g_TANK.pos.X;
//					g_BULL.pos.Y = g_TANK.pos.Y;
//				}
//				break;
//				case 右:
//				{
//					g_BULL.nDir = g_TANK.nDir;
//					g_BULL.pos.X = g_TANK.pos.X;
//					g_BULL.pos.Y = g_TANK.pos.Y;
//				}
//				break;
//				default:
//					break;
//				}
//
//			}
//			break;
//
//			default:
//				break;
//			}
//		}
//		
//
//		DrawTank();
//
//				MoveBULL();
//
//
//
//
//		
//	}
//
//	
//
//
//	
//}
//
//
//
//
//void DrawMap(  )
//{
//	//for(int i=0;i<)
//}
//
//
//
//int main() {
//	system("mode con cols=120 lines=50");
//	SetConsoleTitle(TEXT("坦克大战"));
//	
//	//WriteChar(10 - 1, 20,   "□□  ", 2 | 8);
//	//WriteChar(10 , 20,     "  □□", 2 | 8);
//	//WriteChar(10 +1, 20, "□□  ", 2 | 8);
//	Get();
//
//
//}