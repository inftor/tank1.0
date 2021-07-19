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
				g_map[x][y] = show ? ��� : �յ�;
				WriteChar(x, y, "��", show ? 2 : 0);
			}
		}

	}
}

//��ʼ��̹�����꼰λ��
void InitTank(PTANKINFO Tank, int x, int y, int dir)
{
	Tank->point.X = x;
	Tank->point.Y = y;
	Tank->nDir = dir;
	Tank->end = Tank->end2 = clock();
	DrawTank(Tank, true);
}


bool TankCheak(PTANKINFO Tank)  //���̹��ǰ���ϰ�����,����Ϊ�����ꡣ��ֵ1Ϊ��ͨ��,��ֵ0Ϊ�赲(�˻�����)
{
	switch (Tank->nDir)                    //direction����   1�ϣ�2�£�3��4��
	{
	case ��:
		if (g_map[Tank->point.X - 2][Tank->point.Y] == 0 && g_map[Tank->point.X - 2][Tank->point.Y - 1] == 0 && g_map[Tank->point.X - 2][Tank->point.Y + 1] == 0)
			return 1;
		else
			return 0;
	case ��:
		if (g_map[Tank->point.X + 2][Tank->point.Y] == 0 && g_map[Tank->point.X + 2][Tank->point.Y - 1] == 0 && g_map[Tank->point.X + 2][Tank->point.Y+ 1] == 0)
			return 1;
		else
			return 0;
	case ��:
		if (g_map[Tank->point.X][Tank->point.Y - 2] == 0 && g_map[Tank->point.X - 1][Tank->point.Y - 2] == 0 && g_map[Tank->point.X + 1][Tank->point.Y - 2] == 0)
			return 1;
		else
			return 0;
	case ��:
		if (g_map[Tank->point.X][Tank->point.Y + 2] == 0 && g_map[Tank->point.X - 1][Tank->point.Y + 2] == 0 && g_map[Tank->point.X + 1][Tank->point.Y + 2] == 0)
			return 1;
		else
			return 0;
	default:
		printf("���󣡣�");
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
			case ��:
				Tank->point.X--; break;
			case ��:
				Tank->point.X++; break;
			case ��:
				Tank->point.Y--; break;
			case ��:
				Tank->point.Y++; break;

			default:
				break;
			}
		}
		
	}
	DrawTank(Tank, true);
	Tank->end = clock();

}
