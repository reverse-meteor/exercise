#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cctype> // 包含toupper函数

using namespace std;
// struct student
// {
//     string name;
//     int age;
//     int score;
// };
// int a1 = 0, a2 = 0;
// void modify()
// {
//     a1 = 10;
// }
// int max2(int number)
// {
//     if (a1 <=number)
//     {
//         a2=a1;
//         a1 = number;
//     }
//     else
//     {
//         if(a2<number)
//         {
//             a2=number;
//         }
//     }
//     return a2;
// }

int main()
{
    // struct student s;
    // s.name="zhangsan";

    // int a,b;
    // cout<<"请输入一个三位数"<<endl;
    // cin>>a;
    // cout<<"请输入一个一位数"<<endl;
    // cin>>b;
    // int mid=a/10%10;
    // if(mid==b)
    // {
    //     cout<<"yes"<<endl;
    // }
    // else{
    //     cout<<"no"<<endl;
    // }

    // cout<<"请输入六个整数"<<endl;
    // int arr[6];
    // int len=sizeof(arr)/sizeof(int);
    // for(int i=0;i<len;i++)
    // {
    //     cin>>arr[i];
    // }
    // float sum=0.0;
    // int count=0;
    // for(int i=0;i<len;i++)
    // {
    //     if(arr[i]%2==1&&arr[i]%3==0)
    //     {
    //         sum=sum+arr[i];
    //         count++;
    //     }
    // }
    // cout<<"所有满足条件的数的总和是"<<sum<<endl;
    // if(sum!=0)
    // {
    //     double avg=sum/count;
    //     printf("所有满足条件的数的平均数是%.4lf\n",avg);
    // }
    // else
    // {
    //     double a=0.0000;
    //     printf("%.4lf\n",a);
    // }

    // int arr[4];
    // int len=sizeof(arr)/sizeof(int);
    // cout<<"请输入四个整数："<<endl;
    // for(int i=0;i<len;i++)
    // {
    //     cin>>arr[i];
    // }
    // for(int j=0;j<(len-1);j++)
    // {
    //     for(int i=0;i<(len-1);i++)
    //    {
    //     int temp=arr[i];
    //     if(arr[i]>arr[i+1])
    //     {
    //         arr[i]=arr[i+1];
    //         arr[i+1]=temp;
    //     }
    //    }
    // }
    // for(int i=0;i<len;i++)
    // {
    //     cout<<arr[i]<<' ';
    // }

    // int year;
    // cout<<"请输入一个1000年以后的年份"<<endl;
    // cin>>year;
    // if(year%4==0)
    // {
    //     if((year%100==0)&&(year/100%4!=0))
    //     {
    //         cout<<"no"<<endl;
    //     }
    //     else
    //     {
    //         cout<<"yes"<<endl;
    //     }
    // }
    // else
    // {
    //     cout<<"no"<<endl;
    // }

    // int a;
    // cin>>a;
    // if(a>0)
    // cout <<"POS:";
    // cout<<"123x";
    // if(a==0)
    // cout<<"ZERO:0";
    // else
    // cout<<"NEG:-1-2-3-x";

    // int M, N, K;
    // cin >> M >> N >> K;
    // for (int i = M; i < N; i++)
    // {
    //     if ((i - M) % K == 0 && (i - M) != 0)
    //     {
    //         cout << endl;
    //         printf("%c", i);
    //     }
    //     else
    //     {
    //         printf("%c", i);
    //     }
    // }
    //  A：我不是罪犯
    //  B：A、C中有一个是罪犯
    //  C：A和B说了假话
    //  D：C和F说了假话
    //  E：其他五个人中，只有A和D说了真话
    //  F：我是罪犯
    // char cri='A';

    // for(int i=1;i<=6;i++)
    // {
    //     int sum=(cri!='A')+(cri=='A'||cri=='C')+((cri=='A')&&!(cri=='A'||cri=='C'))+(cri=='F')+(!((cri=='A')&&!(cri=='A'||cri=='C'))&&!(cri=='F'))+((cri!='A')&&(!((cri=='A')&&!(cri=='A'||cri=='C'))&&!(cri=='F'))&&!(cri=='A'||cri=='C')&&!((cri=='A')&&!(cri=='A'||cri=='C'))&&!((cri=='F')));
    //     if(sum==3)
    //     {
    //         cout<<cri<<endl;
    //     }
    //     cri++;
    // }

    // int num;
    // cin >> num;
    // int arr[num] = {0};
    // for (int i = 0; i < num; i++)
    // {
    //     cin >> arr[i];
    // }
    // int workload = 0;
    // for (int i = 0; i < num; i++)
    // {
    //     if (arr[i] % 2 == 1)
    //     {
    //         int temp = arr[i];

    //         arr[i] %= 3;
    //         cout << arr[i] << ' ';
    //         if (arr[i] - temp >= 0)
    //         {
    //             workload += (arr[i] - temp);
    //         }
    //         else
    //         {
    //             workload += (temp - arr[i]);
    //         }
    //     }
    //     else
    //     {
    //         cout << arr[i] << ' ';
    //     }
    // }
    // cout << endl
    //      << workload;

    // int a=2;
    // if(!(a>1)||!(a<3))
    // cout<<"B";
    // else
    // cout<<"A";

    // for(int i=0;i<4;i++);
    // cout<<"ABC";

    // char c='c';
    // int d='d';
    // cout<<sizeof(c)<<' '<<sizeof(d);

    // int a, b, c, d;
    // cin >> a >> b >> c >> d;
    // if (a + b + c + d >= 51)
    // {
    //     cout << "Rabbit lose";
    // }
    // else
    // {
    //     cout << "Rabbit wins";
    // }

    // int T;
    // cin >> T;
    // int n, k;
    // int arr[T][n];
    // for (int i = 0; i < T; i++)
    // {
    //     cin >> n >> k;
    //     for (int j = 0; j < n; j++)
    //     {
    //         cin >> arr[i][j];
    //     }
    // }
    // for (int i = 0; i < T; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         int temp1 = arr[i][j];
    //         for (int k = j + 1; k < n; k++)
    //         {
    //             int temp2 = arr[i][k];
    //             if ((temp1 * temp2) % 154 == 0 || (temp1 * temp2) % 147 == 0)
    //             {
    //                 for (int p = 0; p < n; p++)
    //                 {
    //                     arr[i][p] *= 2;
    //                 }
    //             }
    //         }
    //     }
    //     int sum=0;
    //     for(int j=0;j<n;j++)
    //     {
    //         sum+=arr[i][j];
    //     }
    //     if(sum>=k)
    //     {
    //         cout<<"YES"<<endl;
    //     }
    //     else
    //     {
    //         cout<<"NO"<<endl;
    //     }
    // }

    // int a,b,c;
    // cin>>a>>b>>c;
    // cout<<b;

    // char ch;
    // cin>>ch;
    // for(int i=1;i<=3;i++)
    // {
    //     for(int j=2;j>=i;j--)
    //     {
    //         cout<<' ';
    //     }
    //     for(int k=1;k<=(2*i-1);k++)
    //     {
    //         cout<<ch;
    //     }
    //     for(int j=2;j>=1;j--)
    //     {
    //         cout<<' ';
    //     }
    //     cout<<endl;
    // }

    // int a,b,c,d,e;
    // cin>>a>>b>>c>>d>>e;
    // int arr[5]={a,b,c,d,e};
    // int len=sizeof(arr)/sizeof(int);
    // int eat=0;
    // for(int i=0;i<len;i++)
    // {
    //     eat+=(arr[i]%3);
    //     arr[i]/=3;
    //     if(i==0)
    //     {
    //         arr[1]+=arr[i];
    //         arr[4]+=arr[i];
    //     }
    //     else if(i==4)
    //     {
    //         arr[3]+=arr[i];
    //         arr[0]+=arr[i];
    //     }
    //     else
    //     {
    //         arr[i-1]+=arr[i];
    //         arr[i+1]+=arr[i];
    //     }
    // }
    // for(int i=0;i<len;i++)
    // {
    //     cout<<arr[i]<<' ';
    // }
    // cout<<endl<<eat;

    // cout<<"123"<<endl;
    // system("pause");
    // cout<<"123"<<endl;
    // int n;
    // cin >> n;

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int k = 1; k <= (n - i); k++)
    //     {
    //         cout << " ";
    //     }

    //     for (int j = 1; j <= (2 * i - 1); j++)
    //     {
    //         cout << "*";
    //     }
    //     cout << endl;
    // }
    // for (int i = 1; i <= (n - 1); i++)
    // {
    //     for (int k = 1; k <= i; k++)
    //     {
    //         cout << " ";
    //     }
    //     for (int j = 1; j <= (2 * (n - i) - 1); j++)
    //     {
    //         cout << "*";
    //     }
    //     cout << endl;
    // }

    // int a,b;
    // cin>>a>>b;
    // for(int i=1;i<=b;i++)
    // cout<<"*";
    // for(int i=1;i<=(a-2);i++)
    // {
    //     cout<<endl<<"*";
    //     for(int j=1;j<=(b-2);j++)
    //     {
    //         cout<<" ";
    //     }
    //     cout<<"*";
    // }
    // cout<<endl;
    // for(int i=1;i<=b;i++)
    // cout<<"*";

    // int res = 0;
    // int n;
    // cin >> n;
    // for(int i = 0;i < n;i++) {
    //     int num;
    //     cin >> num;
    //     res = max2(num);
    // }
    // cout << res << endl;

    // int n;
    // cin >> n;
    // int arr[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }
    // int sum = 0;
    // int count = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     if ((arr[i] < 1000) && ((arr[i] % 3 == 0) || (arr[i] % 5 == 0)))
    //     {
    //         int flag = 0;
    //         for (int j = 0; j < i; j++)
    //         {
    //             if (arr[j] != -1)
    //             {
    //                 continue;
    //             }
    //             if (arr[j] == -1)
    //             {
    //                 flag++;
    //             }
    //         }
    //         if (flag == 0)
    //         {
    //             if (count != 10)
    //             {
    //                 sum += arr[i];
    //                 count++;
    //             }
    //         }
    //     }
    // }
    // cout << sum << endl;

    // int x,y;
    // cin>>x>>y;
    // int res=(y-x)%2==0?(y-x)/2:(y-x)/2+1;
    // cout<<res;

    // int n = 0;
    // string strArr[11];
    // while (cin >> strArr[++n])
    //     ;
    // --n;
    // for (int i = n; i >= 1; i--)
    // {
    //     if (strArr[i][0] >= 'a' && strArr[i][0] <= 'z')
    //     {
    //         for (int j = 0; j < (int)strArr[i].size(); j++)
    //         {
    //             strArr[i][j] -= ('a' - 'A');
    //         }
    //     }
    //     else if (strArr[i][0] >= 'A' && strArr[i][0] <= 'Z')
    //     {
    //         for (int j = 0; j < (int)strArr[i].size(); j++)
    //         {
    //             strArr[i][j] -= ('A' - 'a');
    //         }
    //     }
    //     else if (strArr[i][0] >= '0' && strArr[i][0] <= '9')
    //     {
    //         for (int j = 0; j < ((int)strArr[i].size() / 2); j++)
    //         {
    //             char temp = strArr[i][j];
    //             strArr[i][j] = strArr[i][((int)strArr[i].size() - 1)];
    //             strArr[i][((int)strArr[i].size() - 1)] = temp;
    //         }
    //     }
    // }
    // for (int i = n; i >= 1; i--)
    // {
    //     cout << strArr[i];
    //     if (i != 1)
    //         cout << " ";
    // }

    // int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // for (int i = 0; i < (9 / 2); i++)
    // {
    //     int temp = arr[i];
    //     arr[i] = arr[8 - i];
    //     arr[8 - i] = temp;
    // }
    // for (int i = 0; i < 9; i++)
    // {
    //     cout << arr[i];
    // }

    
    

    return 0;
}
