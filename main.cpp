#include <iostream>
#include <Windows.h>
#include<conio.h>
#include<list>


#include"GameStart.h"
#include"Food.h"
#include"Snake.h"

using namespace std;



int main()
{
	GameStart gamestart; 

	gamestart.StartHeadline();

	while (true) //��һ����Ϸ��Ҫ��ѭ��
	{
		
	Food food;

	Snake snake;

	gamestart.DrawMap(); 

	gamestart.DrawSidebar();

	gamestart.DrawScore();

	food.UpdateFood(snake.SnakePos_m);

	food.DrawFood();

	while (true) //һ����Ϸ����Ҫ��ѭ��
	{

	snake.DirectinChange(gamestart.UpdateSpeed());

	bool EatFood_n = food.EatFood(snake.OutputSnakeHead());

	snake.UpdateSnakePos(EatFood_n);

	gamestart.UpdateScore(EatFood_n);


	if (EatFood_n) //�ж��Ƿ�Ե�ʳ��Ե�����������
	{
		food.UpdateFood(snake.SnakePos_m);
		food.DrawFood();
	}
	 
	gamestart.DrawScore();

	if (gamestart.TouchFrame(snake.OutputSnakeHead()) || snake.TouchSnakeBody()) //�ж��Ƿ����߿������������Ϸ����
	{
		gamestart.GameEnd();
		system("cls");
		break;
	}

	}

	}

}
