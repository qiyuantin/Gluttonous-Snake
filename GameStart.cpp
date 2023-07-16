#include"GameStart.h"

GameStart::GameStart() 
{
    this->Score_m = 0; //初始化分数
    this->UpdateSpeed(); //初始化速度
}

void GameStart::StartHeadline()
{
    string GameStart_n= "任意键开始游戏";  //输出文本
    HANDLE outputHandle = GetStdHandle(STD_OUTPUT_HANDLE); //获取句柄
    CONSOLE_SCREEN_BUFFER_INFO info; //获取缓冲区
    GetConsoleScreenBufferInfo(outputHandle, &info); //坐标信息
    COORD position = { (info.dwSize.X - GameStart_n.length() )/2 , info.dwSize.Y/2};//获取文本开始位置信息
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position); //定位到文本开始位置
    cout << GameStart_n<<endl;//输出文本
    int num = _getch();//获取一个字符以判断是否按键
    system("cls"); //刷屏
}

void GameStart::DrawMap()
{
    COORD MapPos_n; //定义一个坐标
    for (int x = 0; x <= MAP_X; x++) //循环x轴，生成边框
    {
        MapPos_n.X = x; //获取x轴坐标
        MapPos_n.Y = 0; //将y轴坐标更改为0
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), MapPos_n); //将光标移动到边框位置
        cout << "#"; 
        MapPos_n.Y = MAP_Y; //将y轴改为边框最大值
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), MapPos_n); //将光标移动到边框位置
        cout << "#";
    }
    for (int y = 1; y < MAP_Y; y++) //循环y轴，生成边框，y初始为1不与上一个循环重复，<同理
    {
        MapPos_n.Y = y; //获取y轴坐标
        MapPos_n.X = 0; //将x轴更改为0
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), MapPos_n); //将光标移动到边框位置
        cout << "#";
        MapPos_n.X = MAP_X; //将x轴更改为最大值
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), MapPos_n); //将光标移动到边框位置
        cout << "#";
    }
}

void GameStart::DrawSidebar()
{
    COORD SidebarPos_n; //定义一个坐标
    SidebarPos_n.X = MAP_X + 3; //x轴为地图最大值加3
    SidebarPos_n.Y = 4; //y每次加4（更好方法是用地图y轴最大值除以侧边栏选项数量，然后每次加这些，但懒）
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), SidebarPos_n); 
    cout << "分数：";
    SidebarPos_n.X = MAP_X + 3;
    SidebarPos_n.Y = 8; 
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), SidebarPos_n);
    cout << "w或上方向键向上移动";
    SidebarPos_n.X = MAP_X + 3;
    SidebarPos_n.Y = 12;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), SidebarPos_n);
    cout << "s或下方向键向下移动";
    SidebarPos_n.X = MAP_X + 3;
    SidebarPos_n.Y = 16;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), SidebarPos_n);
    cout << "a或左方向键向左移动";
    SidebarPos_n.X = MAP_X + 3;
    SidebarPos_n.Y = 20;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), SidebarPos_n);
    cout << "d或右方向键向右移动";
    SidebarPos_n.X = MAP_X + 3;
    SidebarPos_n.Y = 24;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), SidebarPos_n);
    cout << "无法向反方向移动";
}

void GameStart::DrawScore()
{
    COORD ScorePos_n;
    ScorePos_n.X = MAP_X + 9; 
    ScorePos_n.Y = 4;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), ScorePos_n);
    cout <<Score_m; //显示分数
}

void GameStart::UpdateScore(bool EatFood_n)
{
    if (EatFood_n) //判断是否吃到食物
    {
        ++Score_m; //吃到则分数自增
    }
}

int const GameStart::UpdateSpeed()
{

        this->Speed_m = max(50, 200 - Score_m);
    return this->Speed_m;
}

bool GameStart::TouchFrame(COORD const& SnakeHead_n)
{
        return SnakeHead_n.X == 0 || SnakeHead_n.X == MAP_X || SnakeHead_n.Y == 0 || SnakeHead_n.Y == MAP_Y; //判断蛇头是否与边框重叠，是则返回1
}

void GameStart::GameEnd()
{
    system("cls"); //刷屏
    string GameEnd_n = "游戏结束！";
    string ScoreName = "最终得分：";
    HANDLE outputHandle = GetStdHandle(STD_OUTPUT_HANDLE); //获取句柄
    CONSOLE_SCREEN_BUFFER_INFO info; //获取缓冲区
    GetConsoleScreenBufferInfo(outputHandle, &info); //坐标信息
    COORD GameEndPos = { (info.dwSize.X -GameEnd_n.length()) / 2 , (info.dwSize.Y / 2)-5 };//获取文本开始位置信息
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), GameEndPos); //定位到文本开始位置
    cout << GameEnd_n ;//输出文本
    COORD ScoreNamePos = { (info.dwSize.X - ScoreName.length()) / 2 , (info.dwSize.Y / 2) };
    cout << ScoreName << this->Score_m;
    COORD Postion = { info.dwSize.X / 2 - 5,info.dwSize.Y / 2 + 5 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Postion);
    cout << "1.继续游戏";
    Postion.X += 10;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Postion);
    cout << "2.退出游戏"<<endl;
    
    int num ;
    cin >> num;
    if (num==2)
    {
        exit(0); //结束程序
    }

}