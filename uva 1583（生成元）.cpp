//��������е�����Ԫx��ԭ��y����s[y]=x����ʽ�����������y�Ľ�x��ʱ��ֱ�������s[y]����
//����Ϊ������С����ԪҲ����x����Ҫ��β��ͷ��ѭ����y��
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
//��������е�ԭ��y��������s[x]=y;����ʽ����Ȼ��ѭ���Աȣ�Ҫ�������s���ĸ�Ԫ����ȣ������Ԫ�ص��±꼴��
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