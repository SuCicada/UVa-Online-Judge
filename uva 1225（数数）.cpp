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
        int num[10]={0};
        int N;
        cin>>N;
        getchar();
        while(N--)
        {
            int ni=N+1;
            while(ni)
            {
                num[ni%10]++;
                ni/=10;
            }
        }
        for(int i=0;i<9;i++)
            cout<<num[i]<<" ";
        cout<<num[9]<<endl;
    }
    return 0;
}
//AC at 2017/12/10
