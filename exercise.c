#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>
void swap(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
void getMaxAndMin(int arr[], int len, int *p1, int *p2)
{
    *p1 = arr[0];
    *p2 = arr[0];
    for (int i = 0; i < len; i++)
    {
        if (arr[i] > *p1)
        {
            *p1 = arr[i];
        }
        if (arr[i] < *p2)
        {
            *p2 = arr[i];
        }
    }
}
int getRemainders(int num1, int num2, int *p1)
{
    if (num2 != 0)
    {
        *p1 = num1 % num2;
        return 1;
    }
    return 0;
}
int plus(int num1, int num2)
{
    return num1 + num2;
}
int subtract(int num1, int num2)
{
    return num1 - num2;
}
int multiply(int num1, int num2)
{
    return num1 * num2;
}
int divide(int num1, int num2)
{
    return num1 / num2;
}
struct girlfriend
{
    char name[100];
    int age;
    char gender;
    double height;
};
typedef struct
{
    char name[100];
    int atk;
    int des;
    int bld;
} AM;
// typedef struct student
// {
//     char name[100];
//     int age;
// }S;
// void method(S*p)
// {
//     printf("please input student name\n");
//     scanf("%s",&(*p).name);
//     printf("please input student age\n");
//     scanf("%d",&(*p).age);
// }
typedef struct message
{
    char phone[12];
    char email[100];
} M;
typedef struct student
{
    char gender;
    char name[100];
    int age;
    double height;
    M msg;
} S;
void permutation(int *p1, int *p2, int *p3)
{
    int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int len = sizeof(arr) / sizeof(int);
    srand(time(NULL));
    int num1 = 123;
    int num2 = 456;
    int num3 = 789;
    while (1)
    {
        if (num2 != (2 * num1) || num3 != (3 * num1))
        {
            num1 = 0;
            num2 = 0;
            num3 = 0;
            for (int i = 0; i < len; i++)
            {
                int a = rand() % 9;
                int temp = arr[i];
                arr[i] = arr[a];
                arr[a] = temp;
            }
            for (int j = 0; j < 3; j++)
            {
                int temp = arr[j];
                num1 = num1 * 10 + temp;
            }
            for (int j = 3; j < 6; j++)
            {
                int temp = arr[j];
                num2 = num2 * 10 + temp;
            }
            for (int j = 6; j < 9; j++)
            {
                int temp = arr[j];
                num3 = num3 * 10 + temp;
            }
        }
        else
        {
            *p1 = num1;
            *p2 = num2;
            *p3 = num3;
            break;
        }
    }
}

int main()
{
    // printf("please type two numbers\n");
    // int min,max;
    // scanf("%d %d",&min,&max);
    // int sum=0;
    // for(int i=min;i<=max;i++)
    // {
    //     if(i%6==0&&i%8==0)
    //     {
    //     sum++;
    //     }
    // }
    // printf("%d\n",sum);

    // int n=64;
    // while(n%2==0)
    // {
    //     n=n/2;
    // }
    // printf("%d\n",n);
    // if(n==1)
    // {
    //     printf("yes");
    // }
    // else
    // {
    //     printf("no");
    // }

    // double width=0.1;
    // double height=8844430;
    // int sum=0;
    // while(width<=height)
    // {
    //     width=width*2;
    //     sum++;
    // }
    // printf("%d\n",sum);

    // int num=123;
    // int rev=0;
    // while(num!=0)
    // {
    // int temp=num%10;
    // num=num/10;
    // rev=rev*10+temp;
    // }
    // printf("%d\n",rev);

    // int x=99;
    // int i=1;
    // while(i*i<=x)
    // {
    //     i++;
    // }
    // printf("%d\n",i-1);

    // int num=121;
    // int org=num;
    // int rev=0;
    // while(num!=0)
    // {
    //     int temp=num%10;
    //     num=num/10;
    //     rev=rev*10+temp;
    // }
    // printf("%d\n",rev);
    // if(rev==org)
    // {
    //     printf("yes");
    // }
    // else
    // {
    //     printf("no");
    // }

    // for(int i=0;i<=4;i++)
    // {
    //     for(int j=0;j<=(4-i);j++)
    //     {
    //         printf("*");
    //     }
    //     printf("\n");
    // }

    // for(int i=1;i<=9;i++)
    // {
    //     for(int j=1;j<=i;j++)
    //     {
    //         printf("%d*%d=%d\t",j,i,i*j);
    //     }
    //     printf("\n");
    // }

    // int n=100;
    // int count=0;
    // for(int i=1;i<=n;i++)
    // {
    //     int temp=0;
    //     for(int j=1;j<=i;j++)
    //     {
    //         if(i%j==0)
    //         {
    //             temp++;
    //         }
    //     }
    //     if(temp==2)
    //     {
    //         count++;
    //     }
    // }
    // printf("%d\n",count);

    // long long sum=0;
    // for(int i=1;i<=10;i++)
    // {
    //     int temp=1;
    //     for(int j=1;j<=i;j++)
    //     {
    //         temp=temp*i;
    //     }
    //     sum=sum+temp;
    //     printf("%lld\n",sum);
    // }
    // printf("%lld\n",sum);

    // for (int i = 1; i <= 1000; i++)
    // {
    //     int sum = 0;
    //     int org = i;
    //     while (org != 0)
    //     {
    //         int temp = org % 10;
    //         sum = sum + temp;
    //         org = org / 10;
    //     }
    //     if (sum == 15)
    //     {
    //         printf("%d\n", i);
    //     }
    // }

    // int a,b,c;
    // int sum=a+b+c;
    // double avg=sum/3.0;
    // printf("%.3lf\n",avg);

    // int sum=0;
    // for(int i=1;i<=100;i++)
    // {
    //     sum=sum+i;
    // }
    // printf("%d\n",sum);

    // int n=18;
    // int sum=n*95;
    // if(sum>=300)
    // {
    //     sum=sum*0.85;
    // }
    // printf("%d\n",sum);

    // for(int i=100;i<=999;i++)
    // {
    //     int a=i%10;
    //     int b=i/10%10;
    //     int c=i/100%10;
    //     if(i==a*a*a+b*b*b+c*c*c)
    //     {
    //         printf("%d\n",i);
    //     }
    // }

    // for(int i=10;i<=101;i++)
    // {
    //     int a=2;
    //     int b=1;
    //     int c=3;
    //     if(i==101)
    //     {
    //         printf("No answer");
    //         break;
    //     }
    //     if(i%3==a&&i%5==b&&i%7==c)
    //     {
    //         printf("%d\n",i);
    //         break;
    //     }
    // }

    // double i;
    // for(i=0;i!=10;i+=0.1)
    // printf("%.lf\n",i);

    // int arr[5]={33,2,44,55,22};
    // printf("%d\n",sizeof(arr));
    // int len=sizeof(arr)/sizeof(int);
    // int max=0;
    // for(int i=0;i<len;i++)
    // {
    //     if(arr[i]>max)
    //     {
    //         max=arr[i];
    //     }
    // }
    // printf("%d\n",max);

    // srand(time(NULL));
    // int arr[10];
    // for(int i=0;i<10;i++)
    // {
    //     int temp=rand()%100+1;
    //     if(i==0)
    //     {
    //         arr[i]=temp;
    //     }
    //     else
    //     {
    //         for(int j=0;j<i;j++)
    //         {
    //             if(arr[j]==temp)
    //             {
    //                 continue;
    //             }
    //             else
    //             {
    //                 arr[i]=temp;
    //             }
    //         }
    //     }
    // }
    // int sum=0;
    // for(int i=0;i<10;i++)
    // {
    //     sum=sum+arr[i];
    // }
    // printf("%d\n",sum);
    // double avg=sum/10.0;
    // printf("%.2lf\n",avg);
    // int count=0;
    // for(int i=0;i<10;i++)
    // {
    //     if(arr[i]<avg)
    //     {
    //         count++;
    //     }
    // }
    // printf("%d\n",count);

    // int arr[5]={1,2,3,4,5};
    // int len=sizeof(arr)/sizeof(int);
    // for(int i=0;i<len;i++)
    // {
    //     printf("%d\n",arr[i]);
    // }
    // for(int i=0;i<len;i++)
    // {
    //     int temp=arr[i];
    //     arr[i]=arr[len-1-i];
    //     arr[len-1-i]=temp;
    //     if(i==(len-1)/2)
    //     {
    //         break;
    //     }
    // }
    // for(int i=0;i<len;i++)
    // {
    //     printf("%d\n",arr[i]);
    // }

    // int arr[5]={1,2,3,4,5};
    // int len=sizeof(arr)/sizeof(int);
    // srand(time(NULL));
    // for(int i=0;i<len;i++)
    // {
    //     int r1=rand()%len;
    //     int temp=arr[i];
    //     arr[i]=arr[r1];
    //     arr[r1]=temp;
    // }
    // for(int i=0;i<len;i++)
    // {
    //     printf("%d\n",arr[i]);
    // }

    // int a=10;
    // int b=20;
    // swap(&a,&b);
    // printf("%d,%d",a,b);

    // int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // int len = sizeof(arr) / sizeof(int);
    // int max, min;
    // getMaxAndMin(arr, len, &max, &min);
    // printf("%d,%d", max, min);

    // int res;
    // int num1=187;
    // int num2=0;
    // int flag=getRemainders(num1,num2,&res);
    // if(flag==1)
    // {
    //     printf("%d\n",res);
    // }
    // else
    // {
    //     printf("no answer");
    // }

    // int arr[5]={10,20,30,40,50};
    // int len=sizeof(arr)/sizeof(int);
    // int*p=arr;
    // for(int i=0;i<len;i++)
    // {
    //     printf("%d\n",*p);
    //     p++;
    // }

    // int arr[3][5]=
    // {
    //     {1,2,3,4,5},
    //     {11,22,33,44,55},
    //     {111,222,333,444,555}
    // };
    // for(int i=0;i<3;i++)
    // {
    //     for(int j=0;j<5;j++)
    //     {
    //         printf("%d\n",arr[i][j]);
    //     }
    // }

    // int arr1[3]={1,2,3};
    // int arr2[5]={1,2,3,4,5};
    // int arr3[7]={1,2,3,4,5,6,7};
    // int*arr[3]={arr1,arr2,arr3};
    // int len1=sizeof(arr1)/sizeof(int);
    // int len2=sizeof(arr2)/sizeof(int);
    // int len3=sizeof(arr3)/sizeof(int);
    // int lenArr[3]={len1,len2,len3};
    // for(int i=0;i<3;i++)
    // {
    //     int len=sizeof(arr[i])/sizeof(int);
    //     for(int j=0;j<lenArr[i];j++)
    //     {
    //         printf("%d\n",arr[i][j]);
    //     }
    //     printf("\n");
    // }

    // int arr[2][5]={
    //     {1,2,3,4,5},
    //     {11,22,33,44,55}
    // };
    // int(*p)[5]=arr;
    // for(int i=0;i<2;i++)
    // {
    //     for(int j=0;j<5;j++)
    //     {
    //         printf("%d\n",*(*p+j));
    //     }
    //     printf("\n");
    //     p++;
    // }

    // int arr1[5]={1,2,3,4,5};
    // int arr2[5]={11,22,33,44,55};
    // int arr3[5]={111,222,333,444,555};
    // int*arr[3]={arr1,arr2,arr3};
    // int**p=arr;
    // for(int i=0;i<3;i++)
    // {
    //     for(int j=0;j<5;j++)
    //     {
    //         printf("%d\n",*(*p+j));
    //     }
    //     printf("\n");
    //     p++;
    // }

    // int(*arr[4])(int num1,int num2)={plus,subtract,multiply,divide};
    // int num1=123;
    // int num2=12;
    // int choice=2;
    // int res=(arr[choice-1])(num1,num2);
    // printf("%d\n",res);

    // char str[]="Evolution";
    // char*p=str;
    // while(1)
    // {
    //     char c=*p;
    //     if(c=='\0')
    //     {
    //         break;
    //     }
    //     printf("%c",*p);
    //     p++;
    // }

    // char strArr[5][100]={
    //     "zhangsan",
    //     "lisi",
    //     "wangwu",
    //     "zhaoliu",
    //     "qianqi"
    // };
    // for(int i=0;i<5;i++)
    // {
    //     char*str=strArr[i];
    //     printf("%s\n",str);
    // }

    // char str1[100]="你妈";
    // char str2[100]="死了";
    // strcat(str1,str2);
    // printf("%s\n",str1);

    // strlen  strcat strcpy strcmp strlwr strupr
    //  char str[100]="hello world";
    //  _strupr(str);
    //  printf("%s\n",str);
    //  strlwr(str);
    //  printf("%s\n",str);

    // for(int i=0;i<3;i++)
    // {
    //     printf("please input your name\n");
    //     char name[100];
    //     scanf("%s",name);
    //     printf("please input your password\n");
    //     char password[100];
    //     scanf("%s",password);
    //     char rightName[100]="cjm24";
    //     char rightPassword[100]="Xg06211314";
    //     if(strcmp(name,rightName)==0&&strcmp(password,rightPassword)==0)
    //     {
    //         printf("LockIn Success!\n");
    //         break;
    //     }
    //     else
    //     {
    //         printf("LockIn Failed!,%d times left.\n",2-i);
    //         if(i==2)
    //         {
    //             printf("you have no chances!\n");
    //             break;
    //         }
    //     }
    // }

    // char balabala[100]="Hello World!1314！";
    // int bigcount=0;
    // int smallcount=0;
    // int numcount=0;
    // for(int i=0;i<strlen(balabala);i++)
    // {
    //     char c=balabala[i];
    //     if(c>='a'&&c<='z')
    //     {
    //         smallcount++;
    //     }
    //     else if (c>='A'&&c<='Z')
    //     {
    //         bigcount++;
    //     }
    //     else if(c>='0'&&c<='9')
    //     {
    //         numcount++;
    //     }
    // }
    // printf("%d\n%d\n%d",smallcount,bigcount,numcount);

    // struct girlfriend gf1;
    // strcpy(gf1.name,"lxy");
    // gf1.age=18;
    // gf1.gender='F';
    // gf1.height=1.77;

    // AM taro={"泰罗",100,100,100};
    // AM rem={"雷欧",80,80,80};
    // AM eddie={"艾迪",120,120,120};
    // AM arr[3]={taro,rem,eddie};
    // for(int i=0;i<3;i++)
    // {
    //     printf("奥特曼的名字是%s，攻击力是%d,防御力是%d,血量是%d\n",arr[i].name,arr[i].atk,arr[i].des,arr[i].bld);
    // }

    // S stu;
    // strcpy(stu.name,"zhangsan");
    // stu.age=18;
    // printf("before exchange:%s,%d\n",stu.name,stu.age);
    // method(&stu);
    // printf("after exchange:%s,%d\n",stu.name,stu.age);

    // S stu;
    // strcpy(stu.name,"zhangsan");
    // stu.age=18;
    // stu.gender='M';
    // stu.height=1.85;
    // strcpy(stu.msg.phone,"13709583016");
    // strcpy(stu.msg.email,"3769718631@qq.com");
    // printf("name%s\n,age%d\n,gender%c\n,height%.2lf\n,phone%s\n,email%s\n",stu.name,stu.age,stu.gender,stu.height,stu.msg.phone,stu.msg.email);

    // srand(time(NULL));
    // for(int i=0;i<10;i++)
    // {
    //     printf("%d\n",rand());
    // }

    // 习题2-3 倒三角形
    // int n;
    // printf("please input a number\n");
    // scanf("%d", &n);
    // for (int i = n; i >= 1; i--)
    // {
    //     for (int k = 0; k < (n-i); k++)
    //     {
    //         printf(" ");
    //     }
    //     for (int j = 1; j <= (2 * i - 1); j++)
    //     {
    //         printf("*");
    //     }
    //     for (int k = 0; k < (n-i); k++)
    //     {
    //         printf(" ");
    //     }
    //     printf("\n");
    // }

    // 习题2-4 子序列的和
    // double sum = 0.0;
    // long long n, m;
    // printf("请输入两个正整数\n");
    // scanf("%d %d", &n, &m);
    // for (long long i = n; i <= m; i++)
    // {
    //     double temp = (double)1 / (i * i);
    //     sum += temp;
    // }
    // printf("%.5lf\n", sum);

    // 习题2-5 分数化小数
    // double a,b;
    // int c;
    // scanf("%lf%lf%d",&a,&b,&c);
    // double res=a/b;
    // printf("%.*f",c,res);

    // 习题2-6 排列
    // int arr1[100];
    // int arr2[100];
    // int arr3[100];
    // int *p1 = arr1;
    // int *p2 = arr2;
    // int *p3 = arr3;
    // for (int i = 0;; i++)
    // {
    // a:
    //     permutation((p1 + i), (p2 + i), (p3 + i));
    //     if (i >= 1 && arr1[i] == arr1[i - 1])
    //     {
    //         goto a;
    //     }
    //     printf("%d %d %d\n", arr1[i], arr2[i], arr3[i]);
    // }

    // 打乱数组
    //  for(int i=0;i<len;i++)
    //  {
    //      printf("%d\n",arr[i]);
    //  }

    // 开灯问题
    // int n = 7;
    // int arr[n] = {0, 0, 0, 0, 0, 0, 0};
    // int k = 3;
    // for (int i = 1; i <= k; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         if ((j + 1) % i == 0)
    //         {
    //             arr[j]++;
    //         }
    //     }
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", arr[i]);
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     if (arr[i] % 2 == 1)
    //     {
    //         printf("%d ", i + 1);
    //     }
    // }

    int T;
    scanf("%d", &T);
    int arr[T];
    for (int i = 0; i < T; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < T; i++)
    {
        double sum1 = 0.0, sum2 = 0.0;
        double res = 0.0;
        double temp = 0.0;
        for (int j = 0; j < arr[i]; j++)
        {
            sum2 += 1.0 / ((2.0 * temp + 1.0) * (2.0 * temp + 1.0));
            if (j % 2 == 0)
                sum1 += 1.0 / (2.0 * temp + 1.0);
            else
                sum1 -= 1.0 / (2.0 * temp + 1.0);
            temp++;
        }
        double temp1 = 4.0 * sum1;
        double temp2 = sqrt(8.0 * sum2);
        printf("%lf\n%lf\n", temp1, temp2);
        if (temp1 >= temp2)
            res += (temp1 - temp2);
        else
            res += (temp2 - temp1);
        printf("%.6lf\n", res);
    }

    return 0;
}
