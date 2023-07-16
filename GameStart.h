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

	//��ʼ����
	void StartHeadline();

	//���Ƶ�ͼ
	void DrawMap();

	//���Ʋ����
	void DrawSidebar();

	//���Ʒ�����ʾ
	void DrawScore();

	//���·���
	void UpdateScore(bool EatFood_n);

	//�ٶȸ���
	int const UpdateSpeed();


	//�Ƿ����߿�
	bool TouchFrame(COORD const& SnakeHead_n);

	//��Ϸ����
	void GameEnd();
private:
	int Speed_m; //�ٶ�
	int Score_m; //����
};
