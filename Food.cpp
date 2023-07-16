#include"Food.h"


Food::Food()
{

}

void Food::UpdateFood(list<COORD> const & SnakePos)
{
	while (true)
	{
		srand(time(nullptr)); //根据时间生成随机数种子
		int FoodPos_x_MAX = MAP_X - 1; //食物x轴最大生成坐标
		int FoodPos_y_MAX = MAP_Y - 1; //食物y轴最大生成坐标
		FoodPos_m.X = rand() % FoodPos_x_MAX + 1; //x轴生成随机数
		FoodPos_m.Y = rand() % FoodPos_y_MAX + 1; //y轴生成随机数
		int num = 1; //判断是否生成到蛇上，是则重新生成
		for (list<COORD>::const_iterator it =SnakePos.begin();it!= SnakePos.end(); it++)
		{
			if (FoodPos_m.X==(*it).X&&FoodPos_m.Y==(*it).Y) //判断是否等于蛇位置
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
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),FoodPos_m); //将光标移动到食物位置
	cout << "*";
}

bool Food::EatFood(COORD const &SnakeHeadPos)
{
	return SnakeHeadPos.X==FoodPos_m.X&&SnakeHeadPos.Y==FoodPos_m.Y; //返回食物坐标是否等于蛇头坐标
}



Food::~Food()
{
}
