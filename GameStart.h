#pragma once
#include<iostream>
#include<conio.h>
#include<Windows.h>

#include"MapSize.h"

using namespace std;

class GameStart
{
public:

	GameStart();

	//开始标题
	void StartHeadline();

	//绘制地图
	void DrawMap();

	//绘制侧边栏
	void DrawSidebar();

	//绘制分数显示
	void DrawScore();

	//更新分数
	void UpdateScore(bool EatFood_n);

	//速度更新
	int const UpdateSpeed();


	//是否触碰边框
	bool TouchFrame(COORD const& SnakeHead_n);

	//游戏结束
	void GameEnd();
private:
	int Speed_m; //速度
	int Score_m; //分数
};
