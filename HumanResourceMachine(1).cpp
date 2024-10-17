#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;
void printf_red(const char* s);
void printf_green(const char* s);
void printf_yellow(const char* s);

int highest_level=0;
string level_name[4] = { "收发室", "sub走廊", "平等化室", "待定" };

class base_task
{
public:
    void recordGame()
    {
        ofstream ofs;
        ofs.open("D:\\code_store\\PlayProgress.txt", ios::trunc);
        ofs << highest_level;
        ofs.close();
    }
    virtual void dotask() {}
    int getRecord()
    {
        ifstream ifs;
        ifs.open("D:\\code_store\\PlayProgress.txt", ios::in);
        if (!ifs.is_open())
        {
            cout << "游玩记录文件打开失败" << endl;
        }
        char c;
        c=ifs.get();
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
        if (continue_choice == "否")
        {
            system("cls");
            printf_yellow("欢迎您下次游玩！\n");
            Sleep(2000);
            return false;
        }
    }
    void showBlock(int num)
    {
        cout<<"+---+"<<endl;
        cout<<"| "<<num<<" |"<<endl;
        cout<<"+---+"<<endl;
    }
    void showRobot()
    {
        cout<<"-----"<<endl;
        cout<<"|@ @|"<<endl;
        cout<<"  +  "<<endl;
        cout<<"/   \\"<<endl;
        cout<<" | | "<<endl; 
    }
    virtual ~base_task() {};

public:
    int finish_level=0; // 记录当前关卡方便与highest_level进行比较
};

class task01 : virtual public base_task
{
public:
    void dotask()
    {
        printf_yellow("您当前游玩的关卡是: 收发室"); 
        Sleep(2000);
        system("cls");

        // 关卡内容

        cout<<"关卡信息:让机器人取出输入序列上的每个积木放入输出序列中"<<endl;
        cout<<"可用空地数:0"<<endl;
        cout<<"可用指令集:Inbox,Outbox"<<endl;

        // if success
        printf_green("挑战成功！");
        Sleep(2000);
        finish_level = 1;
        system("cls"); // 判断是否成功，到main函数实现
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
    for (int i = 0; i < 4; i++)
    {
        cout << "关卡" << i + 1 << "     " << level_name[i] << endl;
    }
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
    printf_yellow("Human Resource Machine\n");
    cout << "\n======================================================\n\n";
    bool is_continue=true;
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
