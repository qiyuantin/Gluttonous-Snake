#pragma once
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<ctime>
#include<cstdlib>
#include<list>

#include"MapSize.h"

using namespace std;

class Food
{
public:
	Food();

	//更新食物位置
	void UpdateFood(list<COORD> const& SnakePos);

	//绘制食物
	void DrawFood();

	//判断是否吃到食物
	bool EatFood(COORD const& SnakeHeadPos);


	~Food();

private:
	COORD FoodPos_m; //食物位置
};

