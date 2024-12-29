#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std;
string all_instructs[6] = {"copyfrom", "copyto", "add", "sub", "jump", "jumpifzero"};
class base_task
{
public:
    virtual void dotask() {}
    int getNumFromInstruct(string instruct)
    {
        int size_instruct = instruct.size();
        int num = 0;
        int weishu = 1;
        int i = size_instruct - 1;
        for (; i >= 0; i--)
        {
            if (instruct[i] < '0' || instruct[i] > '9')
                break;
            num += (instruct[i] - '0') * weishu;
            weishu *= 10;
        }
        for (; i >= 0; i--) {
            if (instruct[i] >= '0' && instruct[i] <= '9') {
                num = -1;
                break;
            }
        }
        return num;
    }
    bool checkCopyfrom(string instruct)
    {
        int size_instruct = instruct.size();
        if (size_instruct <= 8)
            return 0;
        else
        {
            for (int i = 0; i < 7; i++)
            {
                if (instruct[i] != all_instructs[0][i])
                    return 0;
            }
            return 1;
        }
    }
    bool checkCopyto(string instruct)
    {
        int size_instruct = instruct.size();
        if (size_instruct <= 6)
            return 0;
        else
        {
            for (int i = 0; i < 6; i++)
            {
                if (instruct[i] != all_instructs[1][i])
                    return 0;
            }
            return 1;
        }
    }
    bool checkAdd(string instruct)
    {
        int size_instruct = instruct.size();
        if (size_instruct <= 3)
            return 0;
        else
        {
            for (int i = 0; i < 3; i++)
            {
                if (instruct[i] != all_instructs[2][i])
                    return 0;
            }
            return 1;
        }
    }
    bool checkSub(string instruct)
    {
        int size_instruct = instruct.size();
        if (size_instruct <= 3)
            return 0;
        else
        {
            for (int i = 0; i < 3; i++)
            {
                if (instruct[i] != all_instructs[3][i])
                    return 0;
            }
            return 1;
        }
    }
    bool checkJump(string instruct)
    {
        int size_instruct = instruct.size();
        if (size_instruct <= 4)
            return 0;
        else
        {
            for (int i = 0; i < 4; i++)
            {
                if (instruct[i] != all_instructs[4][i])
                    return 0;
            }
            for(int i=4;i<instruct.size();i++){
                if((instruct[i]<'0'||instruct[i]>'9')&&(instruct[i]!=' ')){
                    return 0;
                }
            }
            return 1;
        }
    }
    bool checkJump_if_zero(string instruct)
    {
        int size_instruct = instruct.size();
        if (size_instruct <= 10)
            return 0;
        else
        {
            for (int i = 0; i < 10; i++)
            {
                if (instruct[i] != all_instructs[5][i])
                    return 0;
            }
            return 1;
        }
    }
 
    void getInstructs(int n, vector<string> &instructs)
    { // vector容器存储用户输入的指令集
        string input;
        getline(cin, input); // getline()函数实现每次读取用户换行前的内容，即每条指令
        for (int i = 1; i <= n; i++)
        {
            getline(cin, input);
            instructs.push_back(input);
        }
    }
 
    int instructInbox(int onhand, vector<int> &inbox)
    {                      
        onhand = inbox[0]; // onhand变量记录机器人搬的东西
        inbox.erase(inbox.begin());
        return onhand;
    }
    int instructOutbox(int onhand, vector<int> &outbox)
    { // outbox操作
        outbox.push_back(onhand);
        onhand = -1000;
        return onhand;
    }
    int instructCopyfrom(bool carry, int on_hand, int num, int space[])
    {
        on_hand = space[num];
        carry = 1;
        return on_hand;
    }
    int instructCopyto(bool carry, int on_hand, int num, int space[])
    {
        space[num] = on_hand;
        return on_hand;
    }
    int instructAdd(bool carry, int on_hand, int num, int space[])
    {
        on_hand += space[num];
        return on_hand;
    }
    int instructSub(bool carry, int on_hand, int num, int space[])
    {
        on_hand -= space[num];
        return on_hand;
    }
 
    int doInstructs_2_3(int n, vector<string> &instructs, vector<int> &inbox, vector<int> &outbox, int space[])
    { // 操作执行
        int on_hand = 1000;
        bool carry = 0;
        for (int i = 1; i <= n; i++)
        { // copyfrom,copyto,add,sub,jump,jump if zero
            if (instructs[i - 1] == "inbox")
            {
                if (inbox.size() == 0)
                    return 0;
                // 程序结束
                on_hand = instructInbox(on_hand, inbox);
                carry = 1;
            }
            else if (instructs[i - 1] == "outbox")
            {
                if (carry == 0)
                    return i;
                else
                {
                    on_hand = instructOutbox(on_hand, outbox);
                    carry = 0;
                }
            }
            else if (checkCopyfrom(instructs[i - 1]))
            {
                int num = getNumFromInstruct(instructs[i - 1]);
                if (num<0||num >= 3 || space[num] == -1000)
                    return i; //-1000表示它是空的
                else
                {
                    // on_hand放到编号为num的空地上
                    on_hand = instructCopyfrom(carry, on_hand, num, space);
                    carry = 1;
                }
            }
            else if (checkCopyto(instructs[i - 1]))
            {
                int num = getNumFromInstruct(instructs[i - 1]);
                if (num<0||num >= 3)
                    return i;
                else if (carry == 0)
                    return i;
                else
                {
                    // on_hand放到编号为num的空地上
                    on_hand = instructCopyto(carry, on_hand, num, space);
                    carry = 1;
                }
            }
            else if (checkAdd(instructs[i - 1]))
            {
                int num = getNumFromInstruct(instructs[i - 1]);
                if (num<0||num >= 3 || carry == 0 || space[num] == -1000)
                    return i;
                else
                {
                    // on_hand加上编号为num的空地上的数
                    on_hand = instructAdd(carry, on_hand, num, space);
                    carry = 1;
                }
            }
            else if (checkSub(instructs[i - 1]))
            {
                int num = getNumFromInstruct(instructs[i - 1]);
                if (num<0||num >= 3 || carry == 0 || space[num] == -1000)
                    return i;
                else if (carry == 0)
                    return i;
                else
                {
                    // on_hand减去编号为num的空地上的数
                    on_hand = instructSub(carry, on_hand, num, space);
                    carry = 1;
                }
            }
            else if (checkJump_if_zero(instructs[i - 1]))
            {
                int num = getNumFromInstruct(instructs[i - 1]);
                if (num > n || num <= 0 || carry == 0)
                    return i;
                else
                {
                    if (on_hand == 0)
                        i = num - 1;
                }
            }
            else if (checkJump(instructs[i - 1]))
            {
                int num = getNumFromInstruct(instructs[i - 1]);
                if (num > n || num <= 0)
                    return i;
                else
                    i = num - 1;
            }
            else
                return i;
        }
        return 0;
    }
    virtual ~base_task() {};
};
 
class task01 : virtual public base_task
{
public:
    int doInstructs(int n, vector<string> &instructs, vector<int> &inbox, vector<int> &outbox)
    { // 操作执行
        int on_hand = 1000;
        bool carry = 0;
        for (int i = 1; i <= n; i++)
        { // copyfrom,copyto,add,sub,jump,jump if zero
            if (instructs[i - 1] == "inbox")
            {
                if (inbox.size() == 0)
                    return 0; // 程序结束
                on_hand = instructInbox(on_hand, inbox);
                carry = 1;
            }
            else if (instructs[i - 1] == "outbox")
            {
                if (carry == 0)
                    return i;
                else
                {
                    on_hand = instructOutbox(on_hand, outbox);
                    carry = 0;
                }
            }
            else
            {
                return i;
            }
        }
        return 0;
    }
    void dotask()
    {
        int num[2]={1,2};
        vector<int> inbox;
        int space[1]={-1000};
        for (int i = 0; i < 2; i++)
        {
            inbox.push_back(num[i]);
        }
        vector<int> outbox;
        vector<string> instructs;
        string n_string;
        int n = 0;
 
        cin >> n;
        getInstructs(n, instructs);
        // 以上这部分均为输入
        int error_on = doInstructs(n, instructs, inbox, outbox);
 
        if (error_on != 0 || outbox.size() != 2)
        { // 编译错误，程序没跑完或者outbox中数不为2个
            if (error_on != 0)
            { // 编译错误，程序没跑完
                cout << "Error " << "on instruction " << error_on;
                return ;
            }
            else if (outbox.size() != 2){
                cout << "Fail";
                return ; // outbox中数不为2个,结果一定错误
            }
            for (int i = 0; i < 2; i++)
            { // outbox有2个数时
                if (outbox[i] != num[i])
                {
                    cout << "Fail";
                    return ;
                }
            }
            // if success
            
        }
        cout << "Success";
    }
};
 
class task02 : virtual public base_task
{
public:
    void dotask()
    {
        int num[8]={3,9,5,1,-2,-2,9,-9};
        vector<int> inbox;
        for (int i = 0; i < 8; i++)
        {
            inbox.push_back(num[i]);
        }
        vector<int> outbox;
        vector<string> instructs;
        string n_string;
        int n = 0;
 
        int space[3] = {-1000, -1000, -1000};
 
        // 关卡内容
        cin >> n;
        getInstructs(n, instructs);
 
        // if success
 
        int error_on = doInstructs_2_3(n, instructs, inbox, outbox, space);
 
        if (error_on != 0 || outbox.size() != 8)
        { // 编译错误，程序没跑完或者outbox中数不为8个
            if (error_on != 0)
            { // 编译错误，程序没跑完
                cout << "Error on instruction " << error_on;
                return ;
            }
            else if (outbox.size() != 8){
                cout << "Fail"; 
                return ;
            }// outbox中数不为8个,结果一定错误
        }
 
        for (int i = 0; i < 8; i++)
        { // outbox有8个数时
            if (i % 2 == 0)
            { // 第0，2，4，6个数，为num[i]-num[i+1]
                if (outbox[i] != num[i] - num[i + 1])
                {
                    cout << "Fail";
                    return ;
                }
            }
            else
            { // 第1，3，5，7个数，为num[i]-num[i-1]
                if (outbox[i] != num[i] - num[i - 1])
                {
                    cout << "Fail";
                    return ;
                }
            }
        }
        // if success
        cout << "Success";
    }
};
 
class task03 : virtual public base_task
{
public:
    void dotask()
    {
        int equal_total = 2;
 
        int num[8]={6,2,7,7,-9,3,-3,-3};
        int answer[2]={7,-3};
 
        vector<int> inbox;
        for (int i = 0; i < 8; i++)
        {
            inbox.push_back(num[i]);
        }
        vector<int> outbox;
        vector<string> instructs;
        string n_string;
        int n = 0;
 
        int space[3] = {-1000, -1000, -1000};
 
        cin >> n;
        getInstructs(n, instructs);
        // if success
 
        int error_on = doInstructs_2_3(n, instructs, inbox, outbox, space);
 
        if (error_on != 0 || outbox.size() != equal_total)
        { // 编译错误，程序没跑完或者outbox中数不为相等的数的个数
            if (error_on != 0)
            { // 编译错误，程序没跑完
                cout << "Error on instruction " << error_on;
                return ;
            }
            else if (outbox.size() != equal_total){
                cout << "Fail"; 
                return ;
            }// outbox中数不为相等的数的个数,结果一定错误
        }
 
        for (int i = 0; i < equal_total; i++)
        { // outbox有equal_total个数时
            if (outbox[i] != answer[i])
            {
                cout << "Fail";
                return ;
            }
        }
 
        // 关卡内容
 
        // if success
        cout << "Success";
    }
};
int main()
{
    int user_choice;
    cin >> user_choice;
    switch (user_choice)
    {
    case 1:
    {
        base_task *base01 = new task01;
        base01->dotask();
        if (base01 != NULL)
        {
            delete base01;
            base01 = NULL;
        }
        break;
    }
    case 2:
    {
        base_task *base02 = new task02;
        base02->dotask();
        if (base02 != NULL)
        {
            delete base02;
            base02 = NULL;
        }
        break;
    }
    case 3:
    {
        base_task *base03 = new task03;
        base03->dotask();
 
        if (base03 != NULL)
        {
            delete base03;
            base03 = NULL;
        }
        break;
    }
    }
}
