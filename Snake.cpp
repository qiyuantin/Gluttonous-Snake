#include"Snake.h"

Snake::Snake()
{
	COORD SnakeHeadPos; //�����ߵ�����
	int SnakeHeadPos_x = MAP_X / 2;
	SnakeHeadPos.Y = MAP_Y / 2;
	;
	for (SnakeHeadPos.X = SnakeHeadPos_x; SnakeHeadPos.X<SnakeHeadPos_x+3; SnakeHeadPos.X++) //ѭ�������߳�ʼ����
	{
		this->SnakePos_m.push_back(SnakeHeadPos); //�������������
	}
	this->DrawSnakeHead(); //������ͷ
	for (list<COORD>::const_iterator it = ++this->SnakePos_m.begin();it!=this->SnakePos_m.end();it++)
	{
		this->DrawSnakeBody(*it); //��������
	}
	this->Directin_m = 3; //��ʼ���ƶ�����
}

void Snake::UpdateSnakePos(bool const & EatFood_n)
{
	COORD NewSnakePos; //����һ���µ�������
	this->DrawSnakeBody(this->SnakePos_m.front()); //������ͷ����Ϊ����
	switch (Directin_m) //�����ƶ������ж�
	{
	case 1: //�����ƶ�
	
		NewSnakePos = SnakePos_m.front(); //��ԭ����ͷ���긳��������
		NewSnakePos.Y--; //�����ƶ����������ƶ�
		SnakePos_m.push_front(NewSnakePos); //���������������ͷ��
		break;
	
	case 2: //�����ƶ�
		NewSnakePos = SnakePos_m.front();
		NewSnakePos.Y++;
		SnakePos_m.push_front(NewSnakePos);
		break;
	case 3: //�����ƶ�
		NewSnakePos = SnakePos_m.front();
		NewSnakePos.X--;
		SnakePos_m.push_front(NewSnakePos);
		break;
	case 4: //�����ƶ�
		NewSnakePos = SnakePos_m.front();
		NewSnakePos.X++;
		SnakePos_m.push_front(NewSnakePos);
		break;
	default:
		break;
}

	this->DrawSnakeHead(); //�����µ�����ͷ��������ͷ

	if (!EatFood_n) //�����Ƿ�Ե�ʳ������Ƿ�ȥ����β
	{
		this->DelSnakeBody(this->SnakePos_m.back()); //����β����Ϊ�հ�
		SnakePos_m.pop_back(); //ɾ����β
	}

}

void Snake::DrawSnakeHead()
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), SnakePos_m.front());
	cout << "<";
}

void Snake::DrawSnakeBody(COORD const & SnakeBody)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), SnakeBody);
	cout << "=";
}

void Snake::DelSnakeBody(COORD const& SnakeBody)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), SnakeBody);
	cout << " ";
}

bool Snake::TouchSnakeBody()
{
	for (list<COORD>::iterator it = ++SnakePos_m.begin(); it != SnakePos_m.end(); it++) //��Ϊ��Ҫ��ͷ������Աȣ��ʵ�����Ϊ����ͷ��������һλ
	{
		if (SnakePos_m.front().X == (*it).X && SnakePos_m.front().Y == (*it).Y) //�ж���ͷ�Ƿ��������
		{
			return 1; //���ڷ���1
		}
	}
	return 0; //�����ڷ���0
}

void Snake::DirectinChange(int const Speed_n)
{
	char inpiut ='0'; //��ʼ�����룬���û���������Զ�����
	    Sleep(Speed_n); //��ͣʱ��
		while (_kbhit()) //�ж���������
		{
			inpiut = _getch(); //��ȡ���뵫����ʾ
		}
		switch (inpiut) //���������ж�
		{
		case 'w':
		case'W':
		case 72:
			if (this->Directin_m == 2) //������������Ч
			{
				break;
			}
			this->Directin_m = 1;
			break;
		case's':
		case'S':
		case 80:
			if (this->Directin_m == 1)
			{
				break;
			}
			this->Directin_m = 2;
			break;
		case'a':
		case'A':
		case 75:
			if (this->Directin_m == 4)
			{
				break;
			}
			this->Directin_m = 3;
			break;
		case'd':
		case'D':
		case 77:
			if (this->Directin_m == 3)
			{
				break;
			}
			this->Directin_m = 4;
			break;
		default:
			break;
		}

	}



COORD const& Snake::OutputSnakeHead()
{
	return this->SnakePos_m.front(); //������ͷ��Ϣ
}

Snake::~Snake()
{

}