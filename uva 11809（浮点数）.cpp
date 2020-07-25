//1.  我们只要算：m*2^(2^n-1)=f *10^t    (m是浮点数位，n是阶码位数，求f和t；)
//2.  而f=10^log10(f)：即左边=10^t1=10^(t+log10(f));
//3.  t1=log10(m*2^(2^n-1))=log10(m)+(2^n-1) *log10(2)
//4.  t=(int)t1;     f=10^(t1-t);
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
double flo[10][30];
int expstr[10][30];
int main()
{
    int twoe;
    double twom;
    double temp;
    for(int i=0;i<10;i++)
    {
        twom=1-pow(2,-i-1);
        for(int j=0;j<30;j++)
        {
            twoe = pow(2,j+1)-1;
            temp = log10(twom)+twoe*log10(2);
            expstr[i][j]=temp;
            flo[i][j]=pow(10,(temp-expstr[i][j]));
        }
    }
    while(1)
    {
        double flo1;
        int exp1;
        char str[25]={0};//存输入的浮点数字符串
        int iff=0;

        //输入浮点数
        char c;
        for(int i=0;(c=getchar())!='e';i++)
        {
            str[i]=c;//scanf("%c",&str[i]);
        }
        sscanf(str,"%lf",&flo1);
        scanf("%d",&exp1);

        if(flo1==0&&exp1==0)//结束标志
            break;


        //从表中找最接近的小数
        //cout<<flo1<<"  "<<exp1<<endl;
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<30;j++)
            {
                //cout<<flo[i][j]<<"  "<<expstr[i][j]<<endl;
                if(abs(flo[i][j]-flo1)<10e-6&&
                   exp1==expstr[i][j])
                {
                    cout<<i;
                    cout<<" "<<j+1<<endl;
                    iff=1;
                    break;
                }
            }
             if(iff==1)break;
        }
    }
    return 0;
}
//AC at 2018/2/1
