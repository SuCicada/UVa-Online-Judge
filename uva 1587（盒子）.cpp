#include<iostream>
using namespace std;
int main()
{
    int a[2];//每组的两条边
    while(cin>>a[0]>>a[1])
    {
        int s[3]={0},n[3]={0};//边长，边数目
        int ns6=6;
        int same=0;
        while(ns6--)//六个面
        {
            if(ns6<5)
                cin>>a[0]>>a[1];
            if(a[0]==a[1])
                same++;//输入的正方形的个数
            for(int j=0;j<2;j++)
                for(int i=0;i<3;i++)
                {
                    if(s[i]==a[j])//如果长度和i边一样，则第i边出现的个数+1
                    {
                        n[i]++;
                        break;
                    }
                    else if(s[i]==0)//存入新边
                    {
                        s[i]=a[j];
                        n[i]++;
                        break;
                    }
                }
        }
//        for(int i=0;i<3;i++)
//            cout<<"s "<<i<<" "<<s[i]<<" |n "<<i<<"  = "<<n[i]<<" same "<<same<<endl;
        if((n[0]==4&&n[1]==4&&n[2]==4&&same==0)||
           ((n[0]==4||n[0]==8)&&n[2]==0&&same==2)||//8并不一定是在n[0]
           (n[0]==12&&same==6))
           cout<<"POSSIBLE"<<endl;
        else
            cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}
//AC at 2017/12/31
