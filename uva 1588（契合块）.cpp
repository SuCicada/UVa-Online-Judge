//���������bbbbb aa (|a|:ab�ص�
//1.�̿��ڳ�����(bb|aa|b)
//2.�̿�ͷ�ڳ�����⣩���̿�β�ͳ�������β(bbbb|a|a)
//3.����ͷ�ڶ̿�β���⣩������β�ͳ����̿�β(a|a|bbbb)
//��Ҫ���ǵ������������ʱ��̿ռ���ǳ���3
#include<iostream>
#include<cstring>
using namespace std;
const int N = 100;
//int kick1[N+5],kick2[N+5];
int kickdown(string k1,string k2)//��k1����k2
{
        //cout<<k1.size()<<"  "<<k2.size()<<endl;
    for(int i=0;i<k1.size();i++)
    {
        int ii=i,j=0;//i���Ǵ�С�����ϵ���һλ
        //cout<<ii<<" "<<j<<endl;
        while((k1[ii]-'0'+k2[j]-'0')<=3&&(j<k2.size()&&ii<k1.size()))//����ǰλ��ƥ�������for����һλ
        {
            //cout<<"k1 ii "<<ii<<"  "<<k1[ii]<<" | k2 j"<<j<<"  "<<k2[j]<<endl;
            ii++;
            j++;
        }
        if(j==k2.size()||ii==k1.size())//�����������ޣ���ѭ������β�ˣ�
        {
            //cout<<j<<"  i "<<i<<endl;
            return (i+k2.size())>=k1.size()?(i+k2.size()):k1.size();
            //��i+k2.size()��k1�����飩�ĳ��Ȼ��̣���ô���賤�Ⱦ�ֱ����k1������
            /*������ͨ�״���*/
            //space=i+k2.size();
            //if(space<k1.size())
            //    space=k1.size();
            //break;
        }
    }
    return k1.size()+k2.size();//��û�����ϴ���ֻ�ܽӵ�������
}

int main()
{
    string k1,k2;//����Ҫk1>k2
    while(cin>>k1>>k2)
    {
        int space1=0,space2=0;
        space1=kickdown(k1,k2);
        space2=kickdown(k2,k1);
        //cout<<"s1   "<<space1<<"  s2 "<<space2<<endl;
        cout<<(space1<space2?space1:space2)<<endl;
    }
    return 0;
}
//AC at 2018/1/2
