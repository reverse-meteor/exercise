#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <cstring>
#include <vector>
#include <ctime>
#include <conio.h>
#include <algorithm>

using namespace std;
void printf_red(const char* s);
void printf_green(const char* s);
void printf_yellow(const char* s);

int highest_level = 0;
string level_name[4] = { "收发室", "sub走廊", "平等化室", "待定" };
string all_instructs[6] = { "copyfrom","copyto","add","sub","jump","jump if zero" };

class base_task
{
public:
    

    int getNumFromInstruct(string instruct) {
        int size_instruct = instruct.size();
        int num = 0;
        int weishu = 1;
        for (int i = size_instruct - 1; i >= 0; i--) {
            if (instruct[i] < '0' || instruct[i] > '9') break;
            num += (instruct[i]-'0')*weishu;
            weishu *= 10;
        }
        return num;
    }
    bool checkCopyfrom(string instruct) {
        int size_instruct = instruct.size();
        if (size_instruct <= 8) return 0;
        else {
            for (int i = 0; i < 7; i++) {
                if (instruct[i] != all_instructs[0][i]) return 0;
            }
            return 1;
        }
    }
    bool checkCopyto(string instruct) {
        int size_instruct = instruct.size();
        if (size_instruct <= 6) return 0;
        else {
            for (int i = 0; i < 6; i++) {
                if (instruct[i] != all_instructs[1][i]) return 0;
            }
            return 1;
        }
    }
    bool checkAdd(string instruct) {
        int size_instruct=instruct.size();
        if (size_instruct <= 3) return 0;
        else {
            for (int i = 0; i < 3; i++) {
                if (instruct[i] != all_instructs[2][i]) return 0;
            }
            return 1;
        }
    }
    bool checkSub(string instruct) {
        int size_instruct = instruct.size();
        if (size_instruct <= 3) return 0;
        else {
            for (int i = 0; i < 3; i++) {
                if (instruct[i] != all_instructs[3][i]) return 0;
            }
            return 1;
        }
    }
    bool checkJump(string instruct) {
        int size_instruct = instruct.size();
        if (size_instruct <= 4) return 0;
        else {
            for (int i = 0; i < 4; i++) {
                if (instruct[i] != all_instructs[4][i]) return 0;
            }
            return 1;
        }
    }
    bool checkJump_if_zero(string instruct) {
        int size_instruct = instruct.size();
        if (size_instruct <= 12) return 0;
        else {
            for (int i = 0; i < 12; i++) {
                if (instruct[i] != all_instructs[5][i]) return 0;
            }
            return 1;
        }
    }
    
    void recordGame()     //记录游戏记录
    {
        ofstream ofs;
        ofs.open("PlayProgress.txt", ios::trunc);//trunc模式打开游戏记录文件，清除原来的记录
        ofs << highest_level;//写入现在游玩的最高关卡
        ofs.close();
    }
    virtual void dotask() {}
    int getRecord()//读取游戏记录文件，得到之前游玩的最高关卡
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
    void updateHighest_level()//更新当前的最高游玩记录
    {
        int temp = getRecord();//temp变量记录之前游玩的最高关卡
        if (temp < finish_level)//和现在完成的关卡进行比较，对最高游玩记录进行更新
            highest_level = finish_level;
        if (highest_level > 4)
            highest_level = 4;
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
            return continueToPlay();//输入错误，重新执行当前函数
        }
    }
    void showBlock(int num, int x1, int y1)//实现在指定位置显示积木块的功能
    {
        gotoxy(x1, y1);
        cout << "+---+";
        gotoxy(x1, y1 + 1);
        if (num >=0&&num<=9) cout << "| " << num << " |";
        else if ((num>=10&&num<=99)||(num<0&&num>-10)) cout << "| " << num << "|";
        else cout << "|" << num << "|";
        gotoxy(x1, y1 + 2);
        cout << "+---+";
    }
    void showXBlock(char x, int x1, int y1)//实现在指定位置显示积木块的功能
    {
        gotoxy(x1, y1);
        cout << "+---+";
        gotoxy(x1, y1 + 1);
        cout << "| " << x << " |";
        gotoxy(x1, y1 + 2);
        cout << "+---+";
    }
    void showRobot(bool carry, int x1, int carry_num)//
    {
        if (x1 > 6) {
            for (int i = 10; i <= 18; i++) {
                gotoxy(x1 - 1, i);
                //gotoxy(x1 , i);
                cout << ' ';
            }
        }
        if (x1 < 29) {
            for (int i = 10; i <= 18; i++) {
                gotoxy(x1+5 , i);
                //gotoxy(x1+4 , i);
                cout << ' ';
            }
        }
        //用空格覆盖机器人，消除机器人行走拖尾

        if (carry) {//扛着东西  
            showBlock(carry_num, x1, 10);
            gotoxy(x1, 13);
            cout << "@   @";
        }

        gotoxy(x1, 14);
        cout << "-----";
        gotoxy(x1, 15);
        cout << "|@ @|";
        gotoxy(x1, 16);
        cout << "  +  " ;
        gotoxy(x1, 17);
        cout << "/   \\" ;
        gotoxy(x1, 18);
        cout << " | | " ;
    }
    void gotoxy(int x, int y) { //更改光标位置，实现在指定位置输出的功能
        short m = short(x);
        short n = short(y);
        COORD pos = { m, n };
        HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(hOut, pos);
    }
    void getInstructs(int n, vector<string>& instructs) {//vector容器存储用户输入的指令集
        string input;
        getline(cin, input);//getline()函数实现每次读取用户换行前的内容，即每条指令
        for (int i = 1; i <= n; i++) {
            gotoxy(61, 9 + i);
            cout << i << ' ';
            getline(cin, input);
            instructs.push_back(input);
        }
    }
    void printInbox(vector<int>& inbox) {//打印inbox
        gotoxy(0, 8);
        cout << "Inbox" << endl << endl;
        int inbox_size = min(6,inbox.size());
        for (int i = 0; i < inbox_size; i++) {
            showBlock(inbox[i], 0, 10 + i * 3);
        }
        for (int i = inbox_size; i < 6; i++) {//这里inbox数量可以改变
            showXBlock('X', 0, 10 + i * 3);
        }

    }
    void printOutbox(vector<int>& outbox) {//打印outbox
        gotoxy(34, 8);
        cout << "Outbox";
        int outbox_size = outbox.size() ;
        if (outbox_size <= 6) {
            for (int i = 0; i < outbox_size; i++) {
                showBlock(outbox[outbox_size - 1 - i], 34, 10 + i * 3);

            }

            for (int i = outbox_size; i < 6; i++) {//这里outbox数量可以改变
                showXBlock('X', 34, 10 + i * 3);
            }
        }
        else {
            int j = 0;
            for (int i = outbox_size - 6; i < outbox_size; i++) {
                showBlock(outbox[2*outbox_size - 7 - i], 34, 10 + j * 3);
                j++;
            }
        }
        
    }
    void fromSpacexToSpacey(bool carry, int Spacex, int Spacey, int carry_num) {//机器人从空地x移动到空地y的上方
        if (Spacex > Spacey) {
            for (int i = 10 + Spacex * 4; i >= 10 + Spacey * 4; i--) {
                showRobot(carry, i, carry_num);
                Sleep(200);
            }
        }
        else if (Spacex < Spacey) {
            for (int i = 10 + Spacex * 4; i <= 10 + Spacey * 4; i++) {
                showRobot(carry, i, carry_num);
                Sleep(200);
            }
        }

    }
    int instructInbox(int onhand, vector<int>& inbox) {//inbox操作

        Sleep(200);
        for (int i = 9; i >= 6; i--) {
            showRobot(0, i, 0);
            Sleep(200);
        }
        onhand = inbox[0];  //onhand变量记录机器人搬的东西
        inbox.erase(inbox.begin());

        showRobot(1, 6, onhand);
        for (int i = 0; i < 5; i++) {//去除箱子所在位置的内容
            gotoxy(0, 8 + i);
            cout << "     ";
        }

        Sleep(200);
        printInbox(inbox);
        Sleep(200);

        for (int i = 6; i <= 10; i++) {
            showRobot(1, i, onhand);
            Sleep(200);
        }
        return onhand;
    }
    int instructOutbox(int onhand, vector<int>& outbox) {//outbox操作
        Sleep(200);
        for (int i = 11; i <= 29; i++) {
            showRobot(1, i, onhand);
            Sleep(200);
        }
        outbox.push_back(onhand);
        onhand = -1000;
        showRobot(0, 29, 0);
        printOutbox(outbox);
        for (int i = 0; i < 6; i++) {//去除箱子所在位置的内容
            gotoxy(29, 8 + i);
            cout << "     ";
        }
        Sleep(200);

        for (int i = 28; i >= 10; i--) {
            showRobot(0, i, 0);
            Sleep(200);
        }
        return onhand;
    }
    int instructCopyfrom(bool carry,int on_hand, int num,int space[]) {
        fromSpacexToSpacey(carry, 0, num, on_hand);
        on_hand = space[num];
        Sleep(250);
        carry = 1;
        showRobot(1, 10 + num * 4, on_hand);
        fromSpacexToSpacey(carry, num, 0, on_hand);
        return on_hand;
    }
    int instructCopyto(bool carry, int on_hand, int num, int space[]) {
        fromSpacexToSpacey(carry, 0, num, on_hand);
        space[num] = on_hand;
        Sleep(250);
        gotoxy(11+num*4, 21);
        cout<<"   ";
        gotoxy(11 + num * 4, 21);
        cout << space[num];
        fromSpacexToSpacey(carry, num, 0, on_hand);
        return on_hand;
    }
    int instructAdd(bool carry,int on_hand,int num, int space[]) {
        fromSpacexToSpacey(carry, 0, num, on_hand);
        on_hand += space[num];
        Sleep(250);
        showRobot(1, 10+num*4, on_hand);
        fromSpacexToSpacey(carry, num, 0, on_hand);
        return on_hand;
    }
    int instructSub(bool carry, int on_hand, int num, int space[]) {
        fromSpacexToSpacey(carry, 0, num, on_hand);
        on_hand -= space[num];
        Sleep(250);
        showRobot(1, 10 + num * 4, on_hand);
        fromSpacexToSpacey(carry, num, 0, on_hand);
        return on_hand;
    }

    void printScreen(vector<int>& inbox, vector<int>& outbox) {//打印游戏界面
        printInbox(inbox);

        showRobot(0, 10, 0);

        printOutbox(outbox);


        for (int i = 0; i < 20; i++) {
            gotoxy(41, 8 + i);
            cout << '|';
            gotoxy(57, 8 + i);
            cout << '|';
        }

        gotoxy(43, 8);
        cout << "可用代码";//后续关卡如需要打印新的可用代码需要自行在子类中补充打印，格式参照这里即可
        gotoxy(43, 10);
        cout << "inbox";
        gotoxy(43, 12);
        cout << "outbox";

        for (int i = 1; i < 10; i++) {
            gotoxy(79, 8 + i);
            cout << '|';
            gotoxy(100, 8 + i);
            cout << '|';
        }
        gotoxy(79, 8);
        cout << "+--------------------+";
        gotoxy(80, 9);
        cout << "帮助：";
        gotoxy(80, 10);
        cout << "第0行输入一个数字n";
        gotoxy(80, 11);
        cout << "表示指令总数为n";
        gotoxy(80, 12);
        cout << "接下来n行输入n条指令";
        gotoxy(80, 13);
        cout << "请以小写字母输入";
        gotoxy(80, 14);
        cout << "--------------------";
        gotoxy(80, 15);
        cout << "游戏结果:";
        gotoxy(79, 18);
        cout << "+--------------------+";

        gotoxy(59, 7);
        cout << "你的代码:";
        gotoxy(59, 8);
        cout << "=====CODE=====";
        gotoxy(61, 9);
        cout << "0 ";
        /*gotoxy()*/
    }
    void printSpace(int x) {//打印空地
        for (int i = 0; i < x; i++) {
            showXBlock(' ', 10 + i * 4, 20);
            gotoxy(10 + i * 4 + 2, 23);
            cout << i;
        }
    }
    virtual ~base_task() {};

public:
    int finish_level = 0; // 记录当前关卡方便与highest_level进行比较
};

class task01 : virtual public base_task
{
public:
    int doInstructs(int n, vector<string>& instructs, vector<int>& inbox, vector<int>& outbox) {//操作执行
        int on_hand = 1000;
        bool carry = 0;
        for (int i = 1; i <= n; i++) {
            gotoxy(59, 9 + i);
            cout << "->";
            if (instructs[i - 1] == "inbox") {
                if (inbox.size() == 0) return i;//防止访问越界
                on_hand = instructInbox(on_hand, inbox);
                carry = 1;
            }
            else if (instructs[i - 1] == "outbox") {
                if (carry==0) return i;
                else {
                    on_hand = instructOutbox(on_hand, outbox);
                    carry = 0;
                }
            }
            else {
                return i;
            }
            gotoxy(59, 9 + i);
            cout << "  ";
        }
        return 0;
    }
    void dotask()
    {
        printf_yellow("您当前游玩的关卡是: 收发室");
        Sleep(2000);
    next_1:
        system("cls");
        srand(time(0));
        int num[3];
        num[0] = rand() % 40;
        num[1] = rand() % 40;
        num[2] = rand() % 40;
        vector<int> inbox;
        for (int i = 0; i < 3; i++) {
            inbox.push_back(num[i]);
        }
        vector<int> outbox;
        vector<string> instructs;
        Sleep(100);
        // 关卡内容
        cout << "欢迎新员工！这是你的第一天" << endl;
        cout << "关卡信息:让机器人取出输入序列(Inbox)上的每个积木放入输出序列(Outbox)中" << endl;
        cout << "可用空地数:0" << endl;
        cout << "可用指令集:inbox,outbox" << endl;
        printScreen(inbox, outbox);

        int n;
        scanf("%d",&n);
        getInstructs(n, instructs);
        int error_on = doInstructs(n, instructs, inbox, outbox);

        if (error_on != 0 || outbox.size() != 3) {//编译错误，程序没跑完或者outbox中数不为3个
            gotoxy(89, 15);
            if (error_on != 0) {//编译错误，程序没跑完
                printf_red("Error");
                gotoxy(80, 16);
                cout << "on line" << error_on;
            }
            else if (outbox.size() < 3) printf_red("Fail");//outbox中数不为3个,结果一定错误
            gotoxy(80, 17);
            cout << "按下\"Enter\"重新开始";
            bool waitForEnter = 1;
            while (waitForEnter) {
                if (_kbhit()) {
                    char ch = _getch();
                    if (ch == '\r') {
                        waitForEnter = 0;
                    }
                }
            }
            //delete p;
            goto next_1;
        }

        for (int i = 0; i < 3; i++) {//outbox有3个数时
            if (outbox[i] != num[i]) {
                gotoxy(89, 15);
                printf_red("Fail");
                gotoxy(80, 17);
                cout << "按下\"Enter\"重新开始";
                bool waitForEnter = 1;
                while (waitForEnter) {
                    if (_kbhit()) {
                        char ch = _getch();
                        if (ch == '\r') {
                            waitForEnter = 0;
                        }
                    }
                }
                //delete p;
                goto next_1;
            }
        }
        // if success
        gotoxy(89, 15);
        printf_green("Success");
        Sleep(2000);
        finish_level = 1;
        system("cls"); 
    }
};

class task02 : virtual public base_task
{
public:
    int doInstructs(int n, vector<string>& instructs, vector<int>& inbox, vector<int>& outbox,int space[]) {//操作执行
        int on_hand = 1000;
        bool carry = 0;
        for (int i = 1; i <= n; i++) {//copyfrom,copyto,add,sub,jump,jump if zero
            gotoxy(59, 9 + i);
            cout << "->";
            if (instructs[i - 1] == "inbox") {
                if (inbox.size() == 0) return i;//防止访问越界
                if (carry == 1) {
                    for (int i = 0; i < 4; i++) {
                        gotoxy(10, 10 + i);
                        cout << "     ";
                    }
                }
                on_hand = instructInbox(on_hand, inbox);
                carry = 1;

            }
            else if (instructs[i - 1] == "outbox") {
                if (carry==0) return i;
                else {
                    on_hand = instructOutbox(on_hand, outbox);
                    carry = 0;
                }
            }
            else if (checkCopyfrom(instructs[i - 1])) {
                int num = getNumFromInstruct(instructs[i - 1]);
                if (num >= 3||space[num]==-1000) return i;//-1000表示它是空的
                else {
                    //on_hand放到编号为num的空地上
                    on_hand=instructCopyfrom(carry, on_hand, num, space);
                    carry = 1;
                }
            }
            else if (checkCopyto(instructs[i - 1])) {
                int num = getNumFromInstruct(instructs[i - 1]);
                if (num >= 3) return i;
                else if (carry == 0) return i;
                else {
                    //on_hand放到编号为num的空地上
                    on_hand=instructCopyto(carry, on_hand, num, space);
                    carry = 1;
                }
            }
            else if (checkAdd(instructs[i - 1] )) {
                int num = getNumFromInstruct(instructs[i - 1]);
                if (num >= 3 || carry == 0|| space[num] == -1000) return i;
                else {
                    //on_hand加上编号为num的空地上的数
                    on_hand = instructAdd(carry, on_hand, num, space);
                    carry = 1;
                }
            }
            else if (checkSub(instructs[i - 1])) {
                int num = getNumFromInstruct(instructs[i - 1]);
                if (num >= 3 || carry == 0 || space[num] == -1000) return i;
                else if (carry == 0) return i;
                else {
                    //on_hand减去编号为num的空地上的数
                    on_hand = instructSub(carry, on_hand, num, space);
                    carry = 1;
                }
            }
            
            else if (checkJump(instructs[i - 1])) {
                int num = getNumFromInstruct(instructs[i - 1]);
                if (num >= n || num <= 0) return i;
                else {
                    if (outbox.size() < 8) {
                        gotoxy(59, 9 + i);
                        cout << "  ";
                        i = num - 1;
                    }
                    else i = n;
                }
            }
            else if (checkJump_if_zero(instructs[i - 1])) {
                int num = getNumFromInstruct(instructs[i - 1]);
                if (num >= n || num <= 0) return i;
                else {
                    if (outbox.size() <= 8 && on_hand == 0) {
                        gotoxy(59, 9 + i);
                        cout << "  ";
                        i = num - 1;
                    }
                    else if (outbox.size() < 8 );
                    else i = n;
                }
            }
            else {
                return i;
            }
            gotoxy(59, 9 + i);
            cout << "  ";
        }
        return 0;
    }
    void dotask()
    {
        printf_yellow("您当前游玩的关卡是: sub走廊");
        Sleep(2000);
    next_2:
        system("cls");
        srand(time(0));
        int num[8];
        for (int i = 0; i < 8; i++) {
            num[i] = rand() % 40-20;
        }
        vector<int> inbox;
        for (int i = 0; i < 8; i++) {
            inbox.push_back(num[i]);
        }
        vector<int> outbox;
        vector<string> instructs;
        int space[3] = { -1000,-1000,-1000 };
        Sleep(100);
        // 关卡内容
        cout << "这是你的第二天" << endl;
        cout << "关卡信息:对于inbox中的两个东西" << endl
            << "先把第1个减去第2个，并把结果放在outbox内" << endl
            << "然后，把第2个减去第1个，再把结果放在outbox内，重复";
        cout << "可用空地数:3" << endl;
        cout << "可用指令集:inbox,outbox,copyfrom,copyto,add,sub,jump,jump if zero" << endl;
        cout << "请在copyfrom,copyto,add,sub,jump,jump if zero后加上一个数字";
        printSpace(3);
        for (int i = 0; i < 6; i++) {
            gotoxy(43, 14 + i * 2);
            cout << all_instructs[i];
        }//打印新的可用代码

        printScreen(inbox, outbox);
        
        // 关卡内容
        int n;
        scanf("%d", &n);
        getInstructs(n, instructs);
        // if success

        int error_on = doInstructs(n, instructs, inbox, outbox, space);

        if (error_on != 0 || outbox.size() != 8) {//编译错误，程序没跑完或者outbox中数不为8个
            gotoxy(89, 15);
            if (error_on != 0) {//编译错误，程序没跑完
                printf_red("Error");
                gotoxy(80, 16);
                cout << "on line" << error_on;
            }
            else if (outbox.size() < 8) printf_red("Fail");//outbox中数不为8个,结果一定错误
            gotoxy(80, 17);
            cout << "按下\"Enter\"重新开始";
            bool waitForEnter = 1;
            while (waitForEnter) {
                if (_kbhit()) {
                    char ch = _getch();
                    if (ch == '\r') {
                        waitForEnter = 0;
                    }
                }
            }
            goto next_2;
        }

        for (int i = 0; i < 8; i++) {//outbox有8个数时
            if (i % 2 == 0) {//第0，2，4，6个数，为num[i]-num[i+1]
                if (outbox[i] != num[i]-num[i+1]) {
                    gotoxy(89, 15);
                    printf_red("Fail");
                    gotoxy(80, 17);
                    cout << "按下\"Enter\"重新开始";
                    bool waitForEnter = 1;
                    while (waitForEnter) {
                        if (_kbhit()) {
                            char ch = _getch();
                            if (ch == '\r') {
                                waitForEnter = 0;
                            }
                        }
                    }
                    goto next_2;
                }
            }
            else {//第1，3，5，7个数，为num[i]-num[i-1]
                if (outbox[i] != num[i] - num[i-1]) {
                    gotoxy(89, 15);
                    printf_red("Fail");
                    gotoxy(80, 17);
                    cout << "按下\"Enter\"重新开始";
                    bool waitForEnter = 1;
                    while (waitForEnter) {
                        if (_kbhit()) {
                            char ch = _getch();
                            if (ch == '\r') {
                                waitForEnter = 0;
                            }
                        }
                    }
                    goto next_2;
                }
            }            
        }
        // if success
        gotoxy(89, 15);
        printf_green("Success");
        Sleep(2000);
        finish_level = 1;
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
        highest_level = rfs.get() - 48;
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
                base01->recordGame();
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
                base02->dotask();
                base02->updateHighest_level();
                base02->recordGame();
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
                base03->dotask();
                base03->updateHighest_level();
                base03->recordGame();
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
                base04->dotask();
                base04->updateHighest_level();
                base04->recordGame();
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
