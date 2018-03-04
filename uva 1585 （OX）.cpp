#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int T;
    cin>>T;
    getchar();
    while(T--)
    {
        int sum=0;
        int o=1;
        int c;
        while((c=getchar())!='\n')
        {
            if(c=='O')
            {
                sum+=o;
                o++;
            }
            if(c=='X')
            {
                o=1;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
//AC at 2017/12/9
