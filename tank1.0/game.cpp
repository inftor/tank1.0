#include "game.h"
#include "tank.h"                                                                                                                     
#include"bullte.h"
#include "bullte.h"
#include <stdbool.h>
#include<conio.h>



TANKINFO Tank;
TANKINFO TankA;
TANKINFO TankB;
TANKINFO TankC;
TANKINFO TankD;
BULLTE  Bull[BULLET_MAX];
int GetKeyInput()
{
	if (_kbhit())
		return _getch();
	return 0;
}




void GameRun() {
	InitTank(&Tank, 10, 10, ��);
	InitTank(&TankA, 25, 25, ��);
	InitTank(&TankB, 13, 13, ��);
	InitTank(&TankC, 17, 17, ��);
	InitTank(&TankD, 30, 30, ��);

	DrawMap();
	while (true)
	{
		int dir = GetKeyInput();


		if (dir == 'w') MoveTank(&Tank, ��);
		if (dir == 's') MoveTank(&Tank, ��);
		if (dir == 'a') MoveTank(&Tank, ��);
		if (dir == 'd') MoveTank(&Tank, ��);
		if (dir == 'j') CreatBull(&Tank);
		if (dir == '5') MoveTank(&TankA, ��);
		if (dir == '2') MoveTank(&TankA, ��);
		if (dir == '1') MoveTank(&TankA, ��);
		if (dir == '3') MoveTank(&TankA, ��);
		if (dir == ' ') CreatBull(&TankA);

		/*switch (dir)
		{
		case 'w':MoveTank(&Tank, ��); break;
		case 's':MoveTank(&Tank, ��); break;
		case 'a':MoveTank(&Tank, ��); break;
		case 'd':MoveTank(&Tank, ��); break;
		case '5':MoveTank(&TankA, ��); break;
		case '2':MoveTank(&TankA, ��); break;
		case '1':MoveTank(&TankA, ��); break;
		case '3':MoveTank(&TankA, ��); break;
		default:			   
			break;
		}*/
		MoveBulls();
		AITank();
	}

}

// ����һ���ӵ��������ӵ���ӵ��ӵ�������
void CreatBull(PTANKINFO Tank)
{
	for (int i = 0; i < BULLET_MAX; i++)
	{
		if (Bull[i].alive==false)
		{
			BullPoint( &Bull[i],  Tank);
			DrawBull(&Bull[i], 1);
			break;
		}
	}
}


//�ƶ����е��ӵ�
void MoveBulls() {
	for (int i = 0; i < BULLET_MAX; i++)
	{
		if (Bull[i].alive == true)
		{
			MoveBull(&Bull[i]);
		}
	}
}

//���̹�˴���
void AITank() {


	MoveTank(&TankB, rand() % 4);
	CreatBull(&TankB);
	MoveTank(&TankC, rand() % 4);
	CreatBull(&TankC);
	MoveTank(&TankD, rand() % 4);
	Sleep(50);
	CreatBull(&TankD);

}
