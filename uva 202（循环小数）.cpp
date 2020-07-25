/*
思路：从手算的除法公式下手，每一次的被除数都是 上一个被除数 – 上一位商*除数，而我们只要找到从哪里开始的被除数和之前的某一个被除数一样，那么从这一位便开始循环；如果不懂，看下面的例子：2/3

  0.6 6  //
3|2.0    //一开始不够除，补零
  1.8    //28 = 4（商）* 7（除数）
    2 0  //20 = (30（被除数）- 4（商）* 7（除数）)*10
         //开始循环
         //同时我们发现 这里的被除数20 和第二行的被除数20 一样，  
1
2
3
4
5
6
如果还不懂，亲自写一下除法运算，真的可以秒懂。

*/
#include<iostream>
#include<cstring>
using namespace std;
int const N = 3000;
int divident[N+5];//被除数
int result[N+5];//得数
int circle(int nd,int n1)
{
    for(int i=0;i<nd;i++)
    {
        if(n1==divident[i])//发现循环
        {
            return i;//返回 循环体的头部位置,
        }
    }
    return -1;
}
int main()
{
    int a,b;
    while(cin>>a>>b)
    {
        int n1=a;//被除数
        int nc=-1;
        int nd=1,nr=0;//因为result第一位是整数位，所以为了输出对上 nd=1
        memset(divident,0,sizeof(divident));
        memset(result,0,sizeof(result));
        do
        {
            result[nr++]=n1/b;//cout<<n1/b;
            //cout<<n1<<" n1  "<<result[nr-1]<<endl;
            //if(nc==1)
                //result//cout<<".";
            n1 = (n1-n1/b*b);
            n1*=10;
            divident[nd++]=n1;//将每一阶段的被除数存下
            //cout<<n1<<" "<<result[nr-1]<<endl;
            if(n1==0)//若能整除
            {
                result[nr++]=0;
                nc=nd-1;
                nd++;
                break;
            }
         }while((nc=circle(nd-1,n1))==-1);//&&nr<=50);//nc---(nd-1)循环
//         if(nr>50)
//            nc=1;
         //cout<<nc<<"  "<<result[nc]<<"  "<<nd-1<<"  "<<divident[nd-1]<<endl;
        cout<<a<<"/"<<b<<" = ";
        cout<<result[0]<<".";
        for(int i=1;i<nc;i++)
            cout<<result[i];
        cout<<"(";
        for(int i=nc;i<nd-1&&i<=50;i++)
            cout<<result[i];
        if(nr>50)
            cout<<"...";
        cout<<")"<<endl;
       // cout<<nd<<"  "<<nc<<endl;
        cout<<"   "<<nd-nc-1//(nr<=50?nd-nc-1:99)要求算具体的
            <<" = number of digits in repeating cycle"<<endl<<endl;
    }
    return 0;
}
//AC at 2017/12/30
/*
    42
7|3.0
  2 8   //n1/b*b
    20 //n1-n1/b*b , n1*=10
    14
     60


4|1.0
    80
    80
     0
*/

