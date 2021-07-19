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
	InitTank(&Tank, 10, 10, 上);
	InitTank(&TankA, 25, 25, 上);
	InitTank(&TankB, 13, 13, 上);
	InitTank(&TankC, 17, 17, 上);
	InitTank(&TankD, 30, 30, 上);

	DrawMap();
	while (true)
	{
		int dir = GetKeyInput();


		if (dir == 'w') MoveTank(&Tank, 上);
		if (dir == 's') MoveTank(&Tank, 下);
		if (dir == 'a') MoveTank(&Tank, 左);
		if (dir == 'd') MoveTank(&Tank, 右);
		if (dir == 'j') CreatBull(&Tank);
		if (dir == '5') MoveTank(&TankA, 上);
		if (dir == '2') MoveTank(&TankA, 下);
		if (dir == '1') MoveTank(&TankA, 左);
		if (dir == '3') MoveTank(&TankA, 右);
		if (dir == ' ') CreatBull(&TankA);

		/*switch (dir)
		{
		case 'w':MoveTank(&Tank, 上); break;
		case 's':MoveTank(&Tank, 下); break;
		case 'a':MoveTank(&Tank, 左); break;
		case 'd':MoveTank(&Tank, 右); break;
		case '5':MoveTank(&TankA, 上); break;
		case '2':MoveTank(&TankA, 下); break;
		case '1':MoveTank(&TankA, 左); break;
		case '3':MoveTank(&TankA, 右); break;
		default:			   
			break;
		}*/
		MoveBulls();
		AITank();
	}

}

// 创建一颗子弹，并将子弹添加到子弹数组中
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


//移动所有的子弹
void MoveBulls() {
	for (int i = 0; i < BULLET_MAX; i++)
	{
		if (Bull[i].alive == true)
		{
			MoveBull(&Bull[i]);
		}
	}
}

//随机坦克创建
void AITank() {


	MoveTank(&TankB, rand() % 4);
	CreatBull(&TankB);
	MoveTank(&TankC, rand() % 4);
	CreatBull(&TankC);
	MoveTank(&TankD, rand() % 4);
	Sleep(50);
	CreatBull(&TankD);

}
