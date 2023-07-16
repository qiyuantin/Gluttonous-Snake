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

	//����ʳ��λ��
	void UpdateFood(list<COORD> const& SnakePos);

	//����ʳ��
	void DrawFood();

	//�ж��Ƿ�Ե�ʳ��
	bool EatFood(COORD const& SnakeHeadPos);


	~Food();

private:
	COORD FoodPos_m; //ʳ��λ��
};

