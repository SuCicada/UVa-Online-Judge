//1������ֻ��Ҫ�ֱ��¼�����ִ�����ֵĸ�����ĸ��������
//2��Ȼ���С�����Ӵ�С����
//3��֮����бȽϣ���������ִ���Ӧ����ô���ǵ���ĸ��������ͬ�±��Ԫ��ֵ��������ĸ��������ҲӦ����ͬ��
#include<iostream>
#include<string>
using namespace std;
void ssqrt(int *str)
{
    //cout<<str<<endl;
    for(int i=0;i<26;i++)
        for(int j=i+1;j<26;j++)
            if(str[i]>str[j])
            {
                int temp=str[i];
                str[i]=str[j];
                str[j]=temp;
            }
   //cout<<str<<endl;
}
int main()
{
    string str,guess;//����������ִ�
    while(cin>>str>>guess)
    {
        int cha1[26]={0},cha2[26]={0};//�ֱ��¼�����ִ���ĸ�����ĸ������

        for(int i=0;i<str.size();i++)//��¼str�������ĸ����
        {
            cha1[str[i]-'A']++;
            cha2[guess[i]-'A']++;
        }
        ssqrt(cha1);//�Ը�����ĸ������
        ssqrt(cha2);
//        for(int i=0;i<26;i++)
//        cout<<cha1[i];
//        cout<<endl;
//        for(int i=0;i<26;i++)
//        cout<<cha2[i];
//        cout<<endl;


        int iff=1;

//        cout<<"str    "<<str<<endl;
//        cout<<"guess  "<<guess<<endl;

        for(int i=1;i<26;i++)//�Ƚ���������ĸ����
        {
            if(cha1[i]!=cha2[i])
            {
                iff=0;
                cout<<"NO"<<endl;
                break;
            }
        }
        if(iff==1)
            cout<<"YES"<<endl;
    }
    return 0;
}
//AC at 2018/2/5