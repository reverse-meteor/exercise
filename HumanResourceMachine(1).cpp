#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <iomanip>
using namespace std;
string level_name[4] = {"收发室", "sub走廊", "平等化室", "自由关卡"}; // 存储关卡名字，第四关到时候改一下

int checkPlayProgress();  // 检查历史最高游玩层数（打算之后每次刷新层数，就把那个文件覆盖掉，输入新的值）
int chooseYourLevel(int); // 判断玩家选择层数是否合法
void printLevelName(int); // 输出关卡名字，以其是否可以选择

int continueToPlay();//每一关结束后判断一次

void task1();
void task2();
void task3();
void task4();

void printf_red(const char *s);
void printf_green(const char *s);
void printf_yellow(const char *s);

int main()
{
    printf_yellow("Human Resource Machine\n");
    std::cout<<"\n======================================================\n\n";
    int continue_to_play = 1;
    while(continue_to_play==1){
        int highest_level = checkPlayProgress();
        int now_level = chooseYourLevel(highest_level);
        continue_to_play=0;
        while(continue_to_play==0){
            
        // std::cout<<now_level;//调试代码用的
            if (now_level == 0){
            task1();
            continue_to_play=continueToPlay();
            }
            else if (now_level == 1){
                task2();
                continue_to_play=continueToPlay();
            }
            
            else if (now_level == 2){
                task3();
                continue_to_play=continueToPlay();
            }
            
            else if (now_level == 3){
                task4();
                continue_to_play=continueToPlay();
            }
            if(now_level!=3) now_level++;
        }
    }
    
}

int checkPlayProgress()
{

    using namespace std;
    ifstream fin;
    int highest_level;
    fin.open("PlayProgress.txt"); // 打开记录最高关卡的文件，从而实现重启程序仍然可以有曾经的记录
    if (!fin)
    {
        cout << "未找到您曾经的游玩记录，请从第一关重新开始\n";
        return 0;
    } // 如果打开文件失败（网上说可能会有各种原因，我暂时还不知道）
    else
    {
        fin >> highest_level; // 从该文件开头读起的第一个int，如果文件为空，结果为0
        return highest_level;
    }
}

int chooseYourLevel(int highest_level)
{
    using namespace std;
    cout << "请选择您想要挑战的关卡\n";
    printLevelName(highest_level);
    cout << "注：只需要关卡对应的阿拉伯数字(1,2,3......)\n";
    int choosing_level;
    cin >> choosing_level;
    while ((choosing_level != 1 && choosing_level != 2 && choosing_level != 3 && choosing_level != 4) || (choosing_level - 1 > highest_level))
    {
        if ((choosing_level != 1 && choosing_level != 2 && choosing_level != 3 && choosing_level != 4))
        {
            printf_red( "关卡信息输入有误，请重新输入\n");
        }
        else
        {
            printf_red( "您暂且无法选择对应关卡,请重新输入\n");
        }
        cin >> choosing_level;
    }
    return choosing_level;
}

void printLevelName(int level)
{
    using namespace std;
    for (int i = 0; i < 4; i++)
    {
        cout << "关卡" << i+1 << right << setw(20)<< level_name[i]; // 这里对齐是按所占字节对齐，中文占了两个字节，但是显示没占到两格的宽度，所以最后结果没有对齐
        if (i <= level)
            printf_green("  您可以选择\n"); // 感觉这个可以优化一下
        else
            printf_red("  您不可以选择\n");
    }
    return;
}

int continueToPlay(){
    int continue_play=0;
    using namespace std;
    cout << "请选择操作：\n"<< "下一关   输入0\n"<< "回到目录 输入1\n"<< "结束游戏 输入2\n";
    cin >> continue_play;
    while(continue_play!=0&&continue_play!=1&&continue_play!=2){
        printf_red("请输入正确的操作：\n");
        printf("下一关   输入0\n回到目录 输入1\n结束游戏 输入2\n");
        cin >> continue_play;
    }
    if(continue_play==2){
        cout<<"您确定结束游戏吗？\n"<<"是   or   否";
        string yes_no;
        cin>>yes_no;
        while(yes_no!="是"&&yes_no!="否"){
            cout<<"请输入正确的操作：\n"<<"是   or   否";
            string yes_no;
            cin>>yes_no;
        }
        if(yes_no=="是") return continue_play;
        else continue_play=continueToPlay();
    }
    return continue_play;
}

void task1(){

}
void task2(){

}
void task3(){

}
void task4(){

}

void printf_red(const char *s)
{
    printf("\033[0m\033[1;31m%s\033[0m", s);
}

void printf_green(const char *s)
{
    printf("\033[0m\033[1;32m%s\033[0m", s);
}

void printf_yellow(const char *s)
{
    printf("\033[0m\033[1;33m%s\033[0m", s);
}
