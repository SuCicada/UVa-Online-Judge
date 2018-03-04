//先算出所有的生成元x的原数y，以s[y]=x的形式将其存起，在求y的解x的时候，直接输出是s[y]即可
//所以为了求最小生成元也就是x，就要从尾到头的循环算y。
#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
int const N = 100000;
int sn[N+5]={0};
int main()
{
    memset(sn,0,sizeof(sn));
    for(int i=N;i>=0;i--)
    {
        int n=i;
        int s=i;
        while(n>0)
        {
            s+=n%10;
            n/=10;
        }
        sn[s]=i;
    }
    //for(int i=0;i<N;i++)
    //    cout<<sn[i]<<"  ";
   // cout<<endl;
    int n,T;
    cin>>T;
    while(T--)
    {
        int i;
        cin>>n;
        cout<<sn[n]<<endl;
    }
    return 0;
}

//Time limit exceeded
//先算出所有的原数y，将其以s[x]=y;的形式存起，然后循环对比：要求的数和s中哪个元素相等，输出此元素的下标即可
//#include<iostream>
//#include<cstdio>
//using namespace std;
//int const N = 100000;
////int main()
//{
//    int sn[N+5]={0};
//    for(int i=1;i<=N;i++)
//    {
//        int n=i;
//        sn[i]=i;
//        while(n>0)
//        {
////            sn[i]+=n%10;
//            n/=10;
//        }
//    }
//    //for(int i=0;i<N;i++)
//    //    cout<<sn[i]<<"  ";
//   // cout<<endl;
////    int n,T;
//    cin>>T;
//    while(T--)
//    {
//        int i;
//        cin>>n;
//        for(i=1;i<=N;i++)
//        {
//            if(n==sn[i])
//            {
//                cout<<i<<endl;
//                break;
//            }
//        }
//        if(i>N)
//            cout<<0<<endl;
//    }
//    return 0;
//}
//AC at  2017/12/7