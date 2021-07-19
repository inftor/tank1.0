
#include "tank.h"
#include "bullte.h"
//����һ���ӵ�
void BullPoint(PBULLTE Bull, PTANKINFO Tank)
{
	Bull->end = clock();
	Bull->point.X = Tank->point.X;
	Bull->point.Y = Tank->point.Y;
	Bull->dir = Tank->nDir;
	Bull->alive = true;
	switch (Bull->dir)
	{
	case ��:Bull->point.X -= 2; break;
	case ��:Bull->point.X += 2; break;
	case ��:Bull->point.Y -= 2; break;
	case ��:Bull->point.Y += 2; break;
	default:
		break;
	}
}
//�����ӵ�
void DrawBull(PBULLTE Bull, bool show)
{

	WriteChar(Bull->point.X, Bull->point.Y, "as", show ? 2 : 0);
	g_map[Bull->point.X][Bull->point.Y] = show ? �ӵ� : �յ�;
}
void MoveBull(PBULLTE Bull)
{
	if (clock() - Bull->end < 50)
	{
		return;
	}
	DrawBull(Bull, 0);
	switch (Bull->dir)
	{
	case ��:Bull->point.X--; break;
	case ��:Bull->point.X++; break;
	case ��:Bull->point.Y--; break;
	case ��:Bull->point.Y++; break;
	default:
		break;
	}
	if (CheckBullet( Bull))
	{
		DrawBull(Bull, 1);
		Bull->end = clock();
	}
	else
	{
		Bull->alive = 0;
	}
}


//״̬�ж�
bool CheckBullet(PBULLTE Bull) {
	if (g_map[Bull->point.X][Bull->point.Y]==�յ�)
	{
		return true;
	}
	else if (g_map[Bull->point.X][Bull->point.Y] == שǽ)
	{
		WriteChar(Bull->point.X, Bull->point.Y, " ", 0);
		g_map[Bull->point.X][Bull->point.Y] = �յ�;

	}
	else if (g_map[Bull->point.X][Bull->point.Y] == ��ǽ)
	{
		WriteChar(Bull->point.X, Bull->point.Y, "77", 2);
		g_map[Bull->point.X][Bull->point.Y] = שǽ;
	}
	else if (g_map[Bull->point.X][Bull->point.Y] == �߽�)
	{
		return false;
	}
	return false;
}