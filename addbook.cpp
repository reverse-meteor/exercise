#include <iostream>
#include <string>
using namespace std;
#define max 1000
struct person
{
    string name;
    int sex;
    int age;
    string phone;
    string email;
};
struct addbook
{
    struct person arr[max];
    int size;
};
void showMenu()
{
    cout << "1.添加联系人" << endl;
    cout << "2.显示联系人" << endl;
    cout << "3.删除联系人" << endl;
    cout << "4.查找联系人" << endl;
    cout << "5.修改联系人" << endl;
    cout << "6.清空联系人" << endl;
    cout << "0.退出通讯录" << endl;
}
void addperson(struct addbook *abs)
{
    if (abs->size == max)
    {
        cout << "电话本已满,无法添加人数" << endl;
    }
    cout << "请输入添加联系人的姓名" << endl;
    cin >> abs->arr[abs->size].name;
    cout << "请输入添加联系人的性别(1为男,2为女)" << endl;
    cin >> abs->arr[abs->size].sex;
    while (1)
    {
        if (abs->arr[abs->size].sex == 0 || abs->arr[abs->size].sex == 1)
        {
            break;
        }
        else
        {
            cout << "输入有误，请重新输入" << endl;
        }
    }
    cout << "请输入添加联系人的年龄" << endl;
    cin >> abs->arr[abs->size].age;
    cout << "请输入添加联系人的电话号码" << endl;
    cin >> abs->arr[abs->size].phone;
    cout << "请输入添加联系人的邮箱号" << endl;
    cin >> abs->arr[abs->size].email;
    cout << "添加成功！" << endl;
    abs->size++;
    system("pause");
    system("cls");
}
void showperson(struct addbook *abs)
{
    if (abs->size == 0)
    {
        cout << "通讯录为空" << endl;
    }
    else
    {
        for (int i = 0; i < abs->size; i++)
        {
            cout << "姓名:" << abs->arr[i].name << endl;
            if (abs->arr[i].sex == 1)
            {
                cout << "男" << endl;
            }
            else
            {
                cout << "女" << endl;
            }
            cout << "年龄:" << abs->arr[i].age << endl;
            cout << "电话号码:" << abs->arr[i].phone << endl;
            cout << "邮箱地址:" << abs->arr[i].email << endl;
        }
    }
    system("pause");
    system("cls");
}
int findperson(struct addbook *abs)
{
    string name;
    cout << "请输入操作对象联系人的名字" << endl;
    cin >> name;
    for (int i = 0; i < max; i++)
    {
        if (abs->arr[i].name == name)
        {
            return i;
        }
        else
        {
            cout << "通讯录中不存在该对象" << endl;
            return -1;
        }
    }
}
int main()
{
    struct addbook abs;
    abs.size = 0;
    while (1)
    {
        showMenu();
        int select = 0;
        cin >> select;
        switch (select)
        {
        case 1:
            addperson(&abs);
            break;
        case 2:
            showperson(&abs);
            break;
        case 3:
        {
            int flag = findperson(&abs);
            if (flag != -1)
            {
                for (int i = flag; i < max; i++)
                {
                    if (i != 999)
                    {
                        abs.arr[i] = abs.arr[i + 1];
                    }
                    if (i == 999)
                        break;
                }
                abs.size--;
                cout << "删除成功" << endl;
                system("pause");
                system("cls");
            }
            break;
        }

        case 4:
        {
            int flag = findperson(&abs);
            if (flag != -1)
            {
                cout << "姓名:" << abs.arr[flag].name << endl;
                if (abs.arr[flag].sex == 1)
                {
                    cout << "男" << endl;
                }
                else
                {
                    cout << "女" << endl;
                }
                cout << "年龄:" << abs.arr[flag].age << endl;
                cout << "电话号码:" << abs.arr[flag].phone << endl;
                cout << "邮箱地址:" << abs.arr[flag].email << endl;
            }
            system("pause");
            system("cls");
            break;
        }
        case 5:
        {
            int flag = findperson(&abs);
            if (flag != -1)
            {
                cout << "请输入修改的姓名" << endl;
                cin >> abs.arr[flag].name;
                cout << "请输入修改的性别（1为男，2为女）" << endl;
                cin >> abs.arr[flag].sex;
                cout << "请输入修改的年龄" << endl;
                cin >> abs.arr[flag].age;
                cout << "请输入修改的电话号码" << endl;
                cin >> abs.arr[flag].phone;
                cout << "请输入修改的邮箱地址" << endl;
                cin >> abs.arr[flag].email;
                cout << "修改成功！" << endl;
            }
            system("pause");
            system("cls");
            break;
        }
        case 6:
        {
            abs.size = 0;
            cout << "清空成功！" << endl;
            system("pause");
            system("cls");
            break;
        }
        case 0:
            cout << "欢迎下次使用" << endl;
            return 0;
            break;
        default:
            break;
        }
    }

    system("pause");
    return 0;
}