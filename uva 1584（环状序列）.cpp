#include<iostream>
#include<string>
#include<cstdio>
#include<string.h>
using namespace std;
int const N = 100;
//比较从be1,和从be2开始的字串哪一个更小
int com(char *s,int be1,int be2)
{
    int sl=strlen(s);
    for(int i=0;i<sl;i++)
    {
        //cout<<endl<<(be1+i)%N<<endl;
    //cout<<s[(be1+i)%N]<<"_"<<s[(be2+i)%N]<<endl;
        if(s[(be1+i)%sl]>s[(be2+i)%sl])
            return be2;
        if(s[(be1+i)%sl]<s[(be2+i)%sl])
            return be1;
    }
    return be1;
}
    char s[N+5];
int main()
{
//    char acgt[4]="ACGT";
    int T=1;
    cin>>T;
    while(T--)
    {
        scanf("%s",s);
        int j=0;
        int be1=0,be2;

        for(int i=0;i<strlen(s);i++)//找最小的首字符给be1
        {
            if(s[i]<s[be1])
            {
                be1=i;
            }
        }
        //cout<<be1<<endl;
        for(int i=0;i<strlen(s);i++)
        {
            if(s[i]==s[be1])//在最小的首字符中 找最小的字串
            {
                if(com(s,be1,i)==i)
                   be1=i;
//                cout<<be1;
//                for(int i=0;i<strlen(s);i++)
//                    cout<<s[(com(s,be1,i)+i)%N];
            }
        }
        for(int i=0;i<strlen(s);i++)
            cout<<s[(be1+i)%strlen(s)];
        cout<<endl;
    }
    return 0;
}
AC at 2017/12/9