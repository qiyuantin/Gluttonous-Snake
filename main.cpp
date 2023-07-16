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

	while (true) //新一局游戏需要的循环
	{
		
	Food food;

	Snake snake;

	gamestart.DrawMap(); 

	gamestart.DrawSidebar();

	gamestart.DrawScore();

	food.UpdateFood(snake.SnakePos_m);

	food.DrawFood();

	while (true) //一局游戏内需要的循环
	{

	snake.DirectinChange(gamestart.UpdateSpeed());

	bool EatFood_n = food.EatFood(snake.OutputSnakeHead());

	snake.UpdateSnakePos(EatFood_n);

	gamestart.UpdateScore(EatFood_n);


	if (EatFood_n) //判断是否吃到食物，吃到则重新生成
	{
		food.UpdateFood(snake.SnakePos_m);
		food.DrawFood();
	}
	 
	gamestart.DrawScore();

	if (gamestart.TouchFrame(snake.OutputSnakeHead()) || snake.TouchSnakeBody()) //判断是否触碰边框或蛇身。是则游戏结束
	{
		gamestart.GameEnd();
		system("cls");
		break;
	}

	}

	}

}
