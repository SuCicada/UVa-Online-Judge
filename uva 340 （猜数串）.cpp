//�Ƚ�ԭ��������������,�Ƚ�λ��һ�����ҳ�,�ٶ�λ�÷�-1(δƥ��)����������Ԫ�غ�ԭ������λ�Ա�.
//���бȽϹ���λ�ϵ�Ԫ�ض��滻Ϊ-1,��ֹ����ƥ�䡣
#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
void output(int *a);
int input(int *a,int n)
{
    int iff=0;
    int i;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]==0)
            iff++;
    }
    a[i+1]='\0';
    if(iff==n)
        return 0;
    return 1;
}
void cop(int *coped,int *copee,int n)
{
    for(int i=0;i<n;i++)
    {
        copee[i]=coped[i];
    }
}
//void output(int a[])
//{
//    //cout<<"!"<<sizeof(a)<<endl;//֮������4������Ϊaֻ��һ��ָ��
//    for(int i=0;a[i]!='\0';i++)
//        cout<<a[i]<<" ";
//    cout<<'\n';
//}
void guess(int *s,int *a,int n)
{
    int r=0,b=0;
    int *bb=new int[n];
    cop(s,bb,n);
    for(int j=0;j<n;j++)
    {
        if(a[j]==bb[j])
        {
            a[j]=bb[j]=-1;
            r++;
        }
    }
    for(int j=0;j<n;j++)
    {
        if(a[j]==-1)
            continue;
        for(int i=0;i<n;i++)
        {
            //cout<<"!!"<<i<<endl;
            if(a[j]==bb[i])
            {
                a[j]=bb[i]=-1;
    //output(bb);
   // output(a);
                b++;
                break;
            }
        }
    }
    printf("    (%d,%d)\n",r,b);
    delete []bb;
}
int main()
{
    int n,gn=1;
    int ori[1005]={0};
    int gus[1005]={0};
    while(scanf("%d",&n)==1&&n!=0)
    {
        cout<<"Game "<<gn++<<":"<<endl;
        input(ori,n);
        //cout<<"!"<<sizeof(ori)<<endl;
        //output(ori);
        while(input(gus,n)==1)
        {
            //output(gus);
            guess(ori,gus,n);
        }
    }
    return 0;
}
