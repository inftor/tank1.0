#include"tank.h"




int TankMode[4][3][3] =
{
	{
		{0,1,0},
		{1,1,1},
		{1,0,1},
	},
	{
		{1,0,1},
		{1,1,1},
		{0,1,0},
	},
		{
		{0,1,1},
		{1,1,0},
		{0,1,1},
	},
		{

		{1,1,0},
		{0,1,1},
		{1,1,0},
	},


};





void DrawTank(PTANKINFO Tank, bool show) {

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (TankMode[Tank->nDir][i][j] == 1) {
				int x = Tank->point.X + i - 1;
				int y = Tank->point.Y + j - 1;
				g_map[x][y] = show ? 玩家 : 空地;
				WriteChar(x, y, "□", show ? 2 : 0);
			}
		}

	}
}

//初始化坦克坐标及位置
void InitTank(PTANKINFO Tank, int x, int y, int dir)
{
	Tank->point.X = x;
	Tank->point.Y = y;
	Tank->nDir = dir;
	Tank->end = Tank->end2 = clock();
	DrawTank(Tank, true);
}


bool TankCheak(PTANKINFO Tank)  //检测坦克前方障碍函数,参量为假坐标。返值1为可通过,返值0为阻挡(人机共用)
{
	switch (Tank->nDir)                    //direction变量   1上，2下，3左，4右
	{
	case 上:
		if (g_map[Tank->point.X - 2][Tank->point.Y] == 0 && g_map[Tank->point.X - 2][Tank->point.Y - 1] == 0 && g_map[Tank->point.X - 2][Tank->point.Y + 1] == 0)
			return 1;
		else
			return 0;
	case 下:
		if (g_map[Tank->point.X + 2][Tank->point.Y] == 0 && g_map[Tank->point.X + 2][Tank->point.Y - 1] == 0 && g_map[Tank->point.X + 2][Tank->point.Y+ 1] == 0)
			return 1;
		else
			return 0;
	case 左:
		if (g_map[Tank->point.X][Tank->point.Y - 2] == 0 && g_map[Tank->point.X - 1][Tank->point.Y - 2] == 0 && g_map[Tank->point.X + 1][Tank->point.Y - 2] == 0)
			return 1;
		else
			return 0;
	case 右:
		if (g_map[Tank->point.X][Tank->point.Y + 2] == 0 && g_map[Tank->point.X - 1][Tank->point.Y + 2] == 0 && g_map[Tank->point.X + 1][Tank->point.Y + 2] == 0)
			return 1;
		else
			return 0;
	default:
		printf("错误！！");
		//Sleep(5000);
		return 0;
	}
}




void MoveTank(PTANKINFO Tank, int Dir) {

	if (clock() - Tank->end < 50)
		return;
	DrawTank(Tank, false);
	if (Tank->nDir != Dir)
	{
		Tank->nDir = Dir;
	}
	else
	{
		if (TankCheak(Tank)) {
			switch (Tank->nDir)
			{
			case 上:
				Tank->point.X--; break;
			case 下:
				Tank->point.X++; break;
			case 左:
				Tank->point.Y--; break;
			case 右:
				Tank->point.Y++; break;

			default:
				break;
			}
		}
		
	}
	DrawTank(Tank, true);
	Tank->end = clock();

}
