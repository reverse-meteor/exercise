#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <cstring>
#include <vector>
#include <ctime>

using namespace std;
void printf_red(const char* s);
void printf_green(const char* s);
void printf_yellow(const char* s);

int highest_level = 0;
string level_name[4] = { "收发室", "sub走廊", "平等化室", "待定" };

class base_task
{
public:
    void recordGame()
    {
        ofstream ofs;
        ofs.open("PlayProgress.txt", ios::trunc);
        ofs << highest_level;
        ofs.close();
    }
    virtual void dotask() {}
    int getRecord()
    {
        ifstream ifs;
        ifs.open("PlayProgress.txt", ios::in);
        if (!ifs.is_open())
        {
            cout << "游玩记录文件打开失败" << endl;
        }
        char c;
        c = ifs.get();
        ifs.close();
        return c - 48;
    }
    void updateHighest_level()
    {
        int temp = getRecord();
        if (temp < finish_level)
            highest_level = finish_level;
    }
    bool continueToPlay()
    {
        cout << "您是否要继续游玩下一关?" << endl;
        cout << "继续游玩请输入是,退出游戏请输入否" << endl;
        string continue_choice;
        cin >> continue_choice;
        if (continue_choice == "是")
        {
            system("cls");
            printf_yellow("返回菜单中...\n");
            Sleep(2000);
            system("cls");
            return true;
        }
        else if (continue_choice == "否")
        {
            system("cls");
            printf_yellow("欢迎您下次游玩！\n");
            Sleep(2000);
            return false;
        }
        else
        {
            system("cls");
            printf_red("输入错误！请重新选择！\n");
            Sleep(2000);
            system("cls");
            return continueToPlay();
        }
    }
    void showInOut() {
        
    }
    void showBlock(char num,int x1,int y1)
    {
        gotoxy(x1, y1);
        cout << "+---+" ;
        gotoxy(x1, y1+1);
        cout << "| " << num << " |" ;
        gotoxy(x1, y1+2);
        cout << "+---+" ;
    }
    void showRobot(bool carry,int x1,char carry_num)
    {
        if (carry) {//扛着东西  
            showBlock(carry_num, x1, 10);
        }
        gotoxy(x1, 14);
        cout << "-----" ;
        gotoxy(x1, 15);
        cout << "|@ @|" ;
        gotoxy(x1, 16);
        cout << "  +  " << endl;
        gotoxy(x1, 17);
        cout << "/   \\" << endl;
        gotoxy(x1, 18);
        cout << " | | " << endl;
    }
    void gotoxy(int x, int y) { //光标
        short m = short(x);
        short n = short(y);
        COORD pos = { m, n };
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(hOut, pos);
    }
    virtual ~base_task() {};
    
public:
    int finish_level = 0; // 记录当前关卡方便与highest_level进行比较
};

class task01 : virtual public base_task
{
public:
    void dotask()
    {
        printf_yellow("您当前游玩的关卡是: 收发室");
        Sleep(2000);
        system("cls");
        srand(time(0));
        char num[3];
        num[0] = '0' + rand() % 10;
        num[1] = '0' + rand() % 10;
        num[2] = '0' + rand() % 10;
        vector<char> inbox;
        for (int i = 0; i < 3; i++) {
            inbox.push_back(num[i]);
        }
        vector<char> outbox;
        // 关卡内容
        cout << "欢迎新员工！这是你的第一天" << endl;
        cout << "关卡信息:让机器人取出输入序列(Inbox)上的每个积木放入输出序列(Outbox)中" << endl;
        cout << "可用空地数:0" << endl;
        cout << "可用指令集:inbox,outbox" << endl;
        printScreen(inbox,outbox);
        
        
        // if success
        int n;
        cin >> n;
        printf_green("挑战成功！");
        Sleep(2000);
        finish_level = 1;
        system("cls"); // 判断是否成功，到main函数实现
    }
    void instructInbox(char num) {

    }
    void instructOutbox(char num) {

    }
    
    void printScreen(vector<char> &inbox, vector<char> &outbox) {
        gotoxy(0, 8);
        cout << "Inbox"<<endl<<endl;
        int inbox_size = inbox.size();
        for (int i = 0; i < inbox_size; i++) {
            showBlock(inbox[i], 0, 10 + i * 3);   
        }
        for (int i = inbox_size; i < 3; i++) {
            showBlock('X', 0, 10 + i * 3 );
        }
        showRobot(0, 10, '0');

        gotoxy(34, 8);
        cout << "Outbox";
        int outbox_size = outbox.size();
        for (int i = 0; i < outbox_size; i++) {
            showBlock(outbox[i], 34, 10+i*3);
        }

        for (int i = outbox_size; i < 3; i++) {
            showBlock('X', 34, 10 + i * 3);
        }


        for (int i = 0; i < 20; i++) {
            gotoxy(41, 8 + i);
            cout << '|';
            gotoxy(53, 8 + i);
            cout << '|';
        }
        gotoxy(43, 8);
        cout << "可用代码";
        gotoxy(43,10);
        cout << "Inbox";
        gotoxy(43, 12);
        cout << "Outbox";


        gotoxy(55, 7);
        cout << "你的代码";
        gotoxy(72, 8);
        cout << "运行";
        gotoxy(72, 10);
        cout << "撤回";
        gotoxy(55, 8);
        cout << "=====CODE=====";
        /*gotoxy()*/
    }

};

class task02 : virtual public base_task
{
public:
    void dotask()
    {
        printf_yellow("您当前游玩的关卡是: sub走廊");
        Sleep(2000);
        system("cls");

        // 关卡内容

        // if success

        printf_green("挑战成功！");
        finish_level = 2;
        Sleep(2000);
        system("cls");
    }
};

class task03 : virtual public base_task
{
public:
    void dotask()
    {
        printf_yellow("您当前游玩的关卡是: 平等化室");
        Sleep(2000);
        system("cls");

        // 关卡内容

        // if success

        printf_green("挑战成功！");
        Sleep(2000);
        finish_level = 3;
        system("cls");
    }
};

class task04 : virtual public base_task
{
public:
    void dotask()
    {
        printf_yellow("您当前游玩的关卡是: 待定");
        Sleep(2000);
        system("cls");

        // 关卡内容

        // if success

        printf_green("挑战成功！");
        Sleep(2000);
        finish_level = 4;
        system("cls");
    }
};

void showMenu()
{
    if (highest_level != 0)
    {
        cout << "您当前游玩的最高纪录为:第" << highest_level << "关" << endl;
    }
    else
    {
        cout << "未找到您的游玩记录,请从第一关开始游玩" << endl;
    }
    cout << "请选择您想要挑战的关卡" << endl;
    printf_green("+-----+-----+-----+-----+\n");
    printf_green("|  ");
    if (0 <= highest_level) printf_yellow("1  ");
    else printf_red("1  ");
    printf_green("|  ");
    if (1 <= highest_level) printf_yellow("2  ");
    else printf_red("2  ");
    printf_green("|  ");
    if (2 <= highest_level) printf_yellow("3  ");
    else printf_red("3  ");
    printf_green("|  ");
    if (3 <= highest_level) printf_yellow("4  ");
    else printf_red("4  ");
    printf_green("|  ");
    printf_green("\n+-----+-----+-----+-----+\n");
}

int chooseLevel()
{
    int chosen_level;
    cin >> chosen_level;
    if (chosen_level > (highest_level + 1))
    {
        system("cls");
        printf_red("您必须先通关先前的关卡!\n");
        Sleep(2000);
        system("cls");
        return -1;
    }
    else
    {
        system("cls");
        printf_green("正在进入关卡中...\n");
        Sleep(2000);
        system("cls");
        return chosen_level;
    }
}

int main()
{
    fstream fs;
    fs.open("PlayProgress.txt", ios::in);
    if (fs.get() == -1)
    {
        highest_level = fs.get() + 1;
        fs.close();
    }
    else
    {
        fs.close();
        ifstream rfs;
        rfs.open("PlayProgress.txt", ios::in);
        highest_level = rfs.get() - 47;
        rfs.close();
    }
    printf_yellow("Human Resource Machine\n");
    cout << "\n======================================================\n\n";
    bool is_continue = true;
    while (is_continue)
    {
    a:
        showMenu();
        int user_choice = chooseLevel(); // user_choice==chosen_level
        if (user_choice != -1)
        {
            switch (user_choice)
            {
            case 1:
            {
                base_task* base01 = new task01;
                base01->recordGame();
                base01->dotask();
                base01->updateHighest_level();
                is_continue = base01->continueToPlay();
                if (base01 != NULL)
                {
                    delete base01;
                    base01 = NULL;
                }
                break;
            }
            case 2:
            {
                base_task* base02 = new task02;
                base02->recordGame();
                base02->dotask();
                base02->updateHighest_level();
                is_continue = base02->continueToPlay();
                if (base02 != NULL)
                {
                    delete base02;
                    base02 = NULL;
                }
                break;
            }
            case 3:
            {
                base_task* base03 = new task03;
                base03->recordGame();
                base03->dotask();
                base03->updateHighest_level();
                is_continue = base03->continueToPlay();
                if (base03 != NULL)
                {
                    delete base03;
                    base03 = NULL;
                }
                break;
            }
            case 4:
            {
                base_task* base04 = new task04;
                base04->recordGame();
                base04->dotask();
                base04->updateHighest_level();
                is_continue = base04->continueToPlay();
                if (base04 != NULL)
                {
                    delete base04;
                    base04 = NULL;
                }
                break;
            }
            default:
            {
                printf_red("输入错误,请输入正确的关卡编号！\n");
                Sleep(2000);
                system("cls");
                goto a;
                break;
            }
            }
        }
    }
    return 0;
}

void printf_red(const char* s)
{
    printf("\033[0m\033[1;31m%s\033[0m", s);
}

void printf_green(const char* s)
{
    printf("\033[0m\033[1;32m%s\033[0m", s);
}

void printf_yellow(const char* s)
{
    printf("\033[0m\033[1;33m%s\033[0m", s);
}
