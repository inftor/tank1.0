
#include "tank.h"
#include "bullte.h"
//´´ÔìÒ»¿Å×Óµ¯
void BullPoint(PBULLTE Bull, PTANKINFO Tank)
{
	Bull->end = clock();
	Bull->point.X = Tank->point.X;
	Bull->point.Y = Tank->point.Y;
	Bull->dir = Tank->nDir;
	Bull->alive = true;
	switch (Bull->dir)
	{
	case ÉÏ:Bull->point.X -= 2; break;
	case ÏÂ:Bull->point.X += 2; break;
	case ×ó:Bull->point.Y -= 2; break;
	case ÓÒ:Bull->point.Y += 2; break;
	default:
		break;
	}
}
//»æÖÆ×Óµ¯
void DrawBull(PBULLTE Bull, bool show)
{

	WriteChar(Bull->point.X, Bull->point.Y, "as", show ? 2 : 0);
	g_map[Bull->point.X][Bull->point.Y] = show ? ×Óµ¯ : ¿ÕµØ;
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
	case ÉÏ:Bull->point.X--; break;
	case ÏÂ:Bull->point.X++; break;
	case ×ó:Bull->point.Y--; break;
	case ÓÒ:Bull->point.Y++; break;
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


//×´Ì¬ÅĞ¶Ï
bool CheckBullet(PBULLTE Bull) {
	if (g_map[Bull->point.X][Bull->point.Y]==¿ÕµØ)
	{
		return true;
	}
	else if (g_map[Bull->point.X][Bull->point.Y] == ×©Ç½)
	{
		WriteChar(Bull->point.X, Bull->point.Y, " ", 0);
		g_map[Bull->point.X][Bull->point.Y] = ¿ÕµØ;

	}
	else if (g_map[Bull->point.X][Bull->point.Y] == ¸ÖÇ½)
	{
		WriteChar(Bull->point.X, Bull->point.Y, "77", 2);
		g_map[Bull->point.X][Bull->point.Y] = ×©Ç½;
	}
	else if (g_map[Bull->point.X][Bull->point.Y] == ±ß½ç)
	{
		return false;
	}
	return false;
}