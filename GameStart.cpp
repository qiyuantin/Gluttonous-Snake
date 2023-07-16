#include"GameStart.h"

GameStart::GameStart() 
{
    this->Score_m = 0; //��ʼ������
    this->UpdateSpeed(); //��ʼ���ٶ�
}

void GameStart::StartHeadline()
{
    string GameStart_n= "�������ʼ��Ϸ";  //����ı�
    HANDLE outputHandle = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ���
    CONSOLE_SCREEN_BUFFER_INFO info; //��ȡ������
    GetConsoleScreenBufferInfo(outputHandle, &info); //������Ϣ
    COORD position = { (info.dwSize.X - GameStart_n.length() )/2 , info.dwSize.Y/2};//��ȡ�ı���ʼλ����Ϣ
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position); //��λ���ı���ʼλ��
    cout << GameStart_n<<endl;//����ı�
    int num = _getch();//��ȡһ���ַ����ж��Ƿ񰴼�
    system("cls"); //ˢ��
}

void GameStart::DrawMap()
{
    COORD MapPos_n; //����һ������
    for (int x = 0; x <= MAP_X; x++) //ѭ��x�ᣬ���ɱ߿�
    {
        MapPos_n.X = x; //��ȡx������
        MapPos_n.Y = 0; //��y���������Ϊ0
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), MapPos_n); //������ƶ����߿�λ��
        cout << "#"; 
        MapPos_n.Y = MAP_Y; //��y���Ϊ�߿����ֵ
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), MapPos_n); //������ƶ����߿�λ��
        cout << "#";
    }
    for (int y = 1; y < MAP_Y; y++) //ѭ��y�ᣬ���ɱ߿�y��ʼΪ1������һ��ѭ���ظ���<ͬ��
    {
        MapPos_n.Y = y; //��ȡy������
        MapPos_n.X = 0; //��x�����Ϊ0
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), MapPos_n); //������ƶ����߿�λ��
        cout << "#";
        MapPos_n.X = MAP_X; //��x�����Ϊ���ֵ
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), MapPos_n); //������ƶ����߿�λ��
        cout << "#";
    }
}

void GameStart::DrawSidebar()
{
    COORD SidebarPos_n; //����һ������
    SidebarPos_n.X = MAP_X + 3; //x��Ϊ��ͼ���ֵ��3
    SidebarPos_n.Y = 4; //yÿ�μ�4�����÷������õ�ͼy�����ֵ���Բ����ѡ��������Ȼ��ÿ�μ���Щ��������
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), SidebarPos_n); 
    cout << "������";
    SidebarPos_n.X = MAP_X + 3;
    SidebarPos_n.Y = 8; 
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), SidebarPos_n);
    cout << "w���Ϸ���������ƶ�";
    SidebarPos_n.X = MAP_X + 3;
    SidebarPos_n.Y = 12;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), SidebarPos_n);
    cout << "s���·���������ƶ�";
    SidebarPos_n.X = MAP_X + 3;
    SidebarPos_n.Y = 16;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), SidebarPos_n);
    cout << "a������������ƶ�";
    SidebarPos_n.X = MAP_X + 3;
    SidebarPos_n.Y = 20;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), SidebarPos_n);
    cout << "d���ҷ���������ƶ�";
    SidebarPos_n.X = MAP_X + 3;
    SidebarPos_n.Y = 24;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), SidebarPos_n);
    cout << "�޷��򷴷����ƶ�";
}

void GameStart::DrawScore()
{
    COORD ScorePos_n;
    ScorePos_n.X = MAP_X + 9; 
    ScorePos_n.Y = 4;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), ScorePos_n);
    cout <<Score_m; //��ʾ����
}

void GameStart::UpdateScore(bool EatFood_n)
{
    if (EatFood_n) //�ж��Ƿ�Ե�ʳ��
    {
        ++Score_m; //�Ե����������
    }
}

int const GameStart::UpdateSpeed()
{

        this->Speed_m = max(50, 200 - Score_m);
    return this->Speed_m;
}

bool GameStart::TouchFrame(COORD const& SnakeHead_n)
{
        return SnakeHead_n.X == 0 || SnakeHead_n.X == MAP_X || SnakeHead_n.Y == 0 || SnakeHead_n.Y == MAP_Y; //�ж���ͷ�Ƿ���߿��ص������򷵻�1
}

void GameStart::GameEnd()
{
    system("cls"); //ˢ��
    string GameEnd_n = "��Ϸ������";
    string ScoreName = "���յ÷֣�";
    HANDLE outputHandle = GetStdHandle(STD_OUTPUT_HANDLE); //��ȡ���
    CONSOLE_SCREEN_BUFFER_INFO info; //��ȡ������
    GetConsoleScreenBufferInfo(outputHandle, &info); //������Ϣ
    COORD GameEndPos = { (info.dwSize.X -GameEnd_n.length()) / 2 , (info.dwSize.Y / 2)-5 };//��ȡ�ı���ʼλ����Ϣ
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), GameEndPos); //��λ���ı���ʼλ��
    cout << GameEnd_n ;//����ı�
    COORD ScoreNamePos = { (info.dwSize.X - ScoreName.length()) / 2 , (info.dwSize.Y / 2) };
    cout << ScoreName << this->Score_m;
    COORD Postion = { info.dwSize.X / 2 - 5,info.dwSize.Y / 2 + 5 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Postion);
    cout << "1.������Ϸ";
    Postion.X += 10;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Postion);
    cout << "2.�˳���Ϸ"<<endl;
    
    int num ;
    cin >> num;
    if (num==2)
    {
        exit(0); //��������
    }

}