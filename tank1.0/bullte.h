#pragma once
#include<windows.h>


#define BULLET_MAX 50

typedef struct _BULLTE  //�����ӵ��ṹ��
{
	COORD point;//�����ӵ�λ��
	bool alive;//�����ӵ�״̬
	int dir;  //�����ӵ�����
	clock_t end;
}BULLTE,*PBULLTE;

void BullPoint(PBULLTE Bull, PTANKINFO Tank);
//�����ӵ�
void DrawBull(PBULLTE Bull, bool show);

void MoveBull(PBULLTE Bull);

//״̬�ж�
bool CheckBullet(PBULLTE Bull);