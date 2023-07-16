#include"Food.h"


Food::Food()
{

}

void Food::UpdateFood(list<COORD> const & SnakePos)
{
	while (true)
	{
		srand(time(nullptr)); //����ʱ���������������
		int FoodPos_x_MAX = MAP_X - 1; //ʳ��x�������������
		int FoodPos_y_MAX = MAP_Y - 1; //ʳ��y�������������
		FoodPos_m.X = rand() % FoodPos_x_MAX + 1; //x�����������
		FoodPos_m.Y = rand() % FoodPos_y_MAX + 1; //y�����������
		int num = 1; //�ж��Ƿ����ɵ����ϣ�������������
		for (list<COORD>::const_iterator it =SnakePos.begin();it!= SnakePos.end(); it++)
		{
			if (FoodPos_m.X==(*it).X&&FoodPos_m.Y==(*it).Y) //�ж��Ƿ������λ��
			{
				num = 0;
				break;
			}
		}
		if (num==1)
		{
			return;
		}
	}
	
}

void Food::DrawFood()
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),FoodPos_m); //������ƶ���ʳ��λ��
	cout << "*";
}

bool Food::EatFood(COORD const &SnakeHeadPos)
{
	return SnakeHeadPos.X==FoodPos_m.X&&SnakeHeadPos.Y==FoodPos_m.Y; //����ʳ�������Ƿ������ͷ����
}



Food::~Food()
{
}
