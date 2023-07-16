#include"Snake.h"

Snake::Snake()
{
	COORD SnakeHeadPos; //定义蛇的坐标
	int SnakeHeadPos_x = MAP_X / 2;
	SnakeHeadPos.Y = MAP_Y / 2;
	;
	for (SnakeHeadPos.X = SnakeHeadPos_x; SnakeHeadPos.X<SnakeHeadPos_x+3; SnakeHeadPos.X++) //循环生成蛇初始坐标
	{
		this->SnakePos_m.push_back(SnakeHeadPos); //将坐标放入链表
	}
	this->DrawSnakeHead(); //绘制蛇头
	for (list<COORD>::const_iterator it = ++this->SnakePos_m.begin();it!=this->SnakePos_m.end();it++)
	{
		this->DrawSnakeBody(*it); //绘制蛇身
	}
	this->Directin_m = 3; //初始化移动方向
}

void Snake::UpdateSnakePos(bool const & EatFood_n)
{
	COORD NewSnakePos; //定义一个新的蛇坐标
	this->DrawSnakeBody(this->SnakePos_m.front()); //将旧蛇头绘制为蛇身
	switch (Directin_m) //更具移动方向判断
	{
	case 1: //向上移动
	
		NewSnakePos = SnakePos_m.front(); //将原来蛇头坐标赋予新坐标
		NewSnakePos.Y--; //根据移动方向向上移动
		SnakePos_m.push_front(NewSnakePos); //将新坐标加入链表头部
		break;
	
	case 2: //向下移动
		NewSnakePos = SnakePos_m.front();
		NewSnakePos.Y++;
		SnakePos_m.push_front(NewSnakePos);
		break;
	case 3: //向左移动
		NewSnakePos = SnakePos_m.front();
		NewSnakePos.X--;
		SnakePos_m.push_front(NewSnakePos);
		break;
	case 4: //向右移动
		NewSnakePos = SnakePos_m.front();
		NewSnakePos.X++;
		SnakePos_m.push_front(NewSnakePos);
		break;
	default:
		break;
}

	this->DrawSnakeHead(); //根据新的链表头部生成蛇头

	if (!EatFood_n) //根据是否吃到食物决定是否去除蛇尾
	{
		this->DelSnakeBody(this->SnakePos_m.back()); //将蛇尾绘制为空白
		SnakePos_m.pop_back(); //删除蛇尾
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
	for (list<COORD>::iterator it = ++SnakePos_m.begin(); it != SnakePos_m.end(); it++) //因为需要蛇头和蛇身对比，故迭代器为链表头部往后移一位
	{
		if (SnakePos_m.front().X == (*it).X && SnakePos_m.front().Y == (*it).Y) //判断蛇头是否等于蛇身
		{
			return 1; //等于返回1
		}
	}
	return 0; //不等于返回0
}

void Snake::DirectinChange(int const Speed_n)
{
	char inpiut ='0'; //初始化输入，如果没有输入则自动跳过
	    Sleep(Speed_n); //暂停时间
		while (_kbhit()) //判断有无输入
		{
			inpiut = _getch(); //获取输入但不显示
		}
		switch (inpiut) //根据输入判断
		{
		case 'w':
		case'W':
		case 72:
			if (this->Directin_m == 2) //反方向输入无效
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
	return this->SnakePos_m.front(); //返回蛇头信息
}

Snake::~Snake()
{

}