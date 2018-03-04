#include<iostream>
#include<iomanip>
using namespace std;

int dole[25];
    int n,a,b;

int cycle(int j)//int n,int ab)
{
    //int j=0;
    for(int i=0;i<a;i++)
    {
        do
        {
            j++;
        if(j==n)
            j=0;
            continue;
        }
        while(dole[j]==0);
        //j++;
    }
    return j;
}
int cycle2(int j)//int n,int b)
{
    //int j=n-1;
    for(int i=0;i<b;i++)
    {
        do
        {
            j--;
        if(j<0)
            j=n-1;
            continue;
        }
        while(dole[j]==0);
    }
    //cout<<"j  "<<j<<endl;
    return j;
}
int main()
{
    while(cin>>n>>a>>b&&(n!=0||a!=0||b!=0))
    {
        int num=n;//num是还存在的人
        for(int i=0;i<n;i++)
            dole[i]=i+1;

        int tempa=-1,tempb=n;//
        while(num)
        {
            tempa = cycle(tempa);//这里用引用更方便
            tempb = cycle2(tempb);
            //cout<<tempa<<" aaa  "<<tempb<<endl;
            cout<<setw(3)<<dole[tempa];
            if(tempa != tempb)
            {
                cout<<setw(3)<<dole[tempb];
                num-=2;
            }
            else
                num--;
            dole[tempa]=dole[tempb]=0;
            if(num)
                cout<<",";
            else
                cout<<endl;
            //for(int i=0;i<n;i++)cout<<dole[i];cout<<endl;
        }
    }
    return  0;
}
//AC at 2018/2/5
