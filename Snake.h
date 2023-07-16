#pragma once
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<list>
#include<chrono>

#include"MapSize.h"

using namespace std;

class Snake
{
public:
	Snake();

	//更新蛇位置信息
	void UpdateSnakePos(bool const& EatFood_n);

	//绘制蛇头
	void DrawSnakeHead();

	//绘制蛇身
	void DrawSnakeBody(COORD const& SnakeBody);

	//消除蛇身
	void DelSnakeBody(COORD const& SnakeBody);

	//是否触碰蛇身
	bool TouchSnakeBody();

	//移动方向变化
	void DirectinChange(int const Speed);

	//输出蛇头信息
	COORD const& OutputSnakeHead();

	list<COORD>SnakePos_m; //蛇的位置

	~Snake();

private:
	

	int Directin_m; //移动方向
};
