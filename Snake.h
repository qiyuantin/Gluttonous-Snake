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

	//������λ����Ϣ
	void UpdateSnakePos(bool const& EatFood_n);

	//������ͷ
	void DrawSnakeHead();

	//��������
	void DrawSnakeBody(COORD const& SnakeBody);

	//��������
	void DelSnakeBody(COORD const& SnakeBody);

	//�Ƿ�������
	bool TouchSnakeBody();

	//�ƶ�����仯
	void DirectinChange(int const Speed);

	//�����ͷ��Ϣ
	COORD const& OutputSnakeHead();

	list<COORD>SnakePos_m; //�ߵ�λ��

	~Snake();

private:
	

	int Directin_m; //�ƶ�����
};
