#include<iostream>
using namespace std;
int main()
{
    int a[2];//ÿ���������
    while(cin>>a[0]>>a[1])
    {
        int s[3]={0},n[3]={0};//�߳�������Ŀ
        int ns6=6;
        int same=0;
        while(ns6--)//������
        {
            if(ns6<5)
                cin>>a[0]>>a[1];
            if(a[0]==a[1])
                same++;//����������εĸ���
            for(int j=0;j<2;j++)
                for(int i=0;i<3;i++)
                {
                    if(s[i]==a[j])//������Ⱥ�i��һ�������i�߳��ֵĸ���+1
                    {
                        n[i]++;
                        break;
                    }
                    else if(s[i]==0)//�����±�
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
           ((n[0]==4||n[0]==8)&&n[2]==0&&same==2)||//8����һ������n[0]
           (n[0]==12&&same==6))
           cout<<"POSSIBLE"<<endl;
        else
            cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}
//AC at 2017/12/31
