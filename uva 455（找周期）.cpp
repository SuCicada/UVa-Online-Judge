//���ҵ��͵�һ��Ԫ����ȵ���һ��Ԫ�أ�Ȼ���һ��Ԫ��λ���ҵ���Ԫ��λ�����������
//һֱ����������һֱһ��������Ϊ�ҵ���Ԫ��λ��
//����ababcababc��
//1.s[0]���ҵ��˺�s[1]���,Ȼ�������
//2.s[0+1]��s[1+1]�ȣ���ȡ�
//3.s[0+1+1]�ٺ�s[1+1+1],���ȣ�����
//4.s[0]�ٺ�s[2],s[3],s[4]�ȡ�����
#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
const int N = 80;
char s[N+5];
int cir(int i)
{
    int n=strlen(s);
    if(n%i!=0)//��ֹaba��abca���2��3������3��4�����
        return 0;
    for(int j=i;j<strlen(s);j++)//˳�αȽ�ǰ���ִ���ȷ�
    {
        if(s[j-i]!=s[j])
        {
            return 0;
        }
    }
    return i;
}
int main ()
{
    int tt;
    scanf("%d",&tt);
    while(tt--)
    {
        scanf("\n%s",s);
        int T=0;//����
        int i,n=strlen(s);
        for(i=1;i<n;i++)
        {
            if(s[0]==s[i])
            {
                if((T=cir(i))==i)
                {
                    break;
                }
            }
        }
        cout<<i<<endl;
        if(tt!=0)
            cout<<endl;
    }
    return 0;
}
//AC at 2017/12/11

