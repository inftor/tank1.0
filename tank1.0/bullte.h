#pragma once
#include<windows.h>


#define BULLET_MAX 50

typedef struct _BULLTE  //定义子弹结构体
{
	COORD point;//定义子弹位置
	bool alive;//定义子弹状态
	int dir;  //定义子弹方向
	clock_t end;
}BULLTE,*PBULLTE;

void BullPoint(PBULLTE Bull, PTANKINFO Tank);
//绘制子弹
void DrawBull(PBULLTE Bull, bool show);

void MoveBull(PBULLTE Bull);

//状态判断
bool CheckBullet(PBULLTE Bull);