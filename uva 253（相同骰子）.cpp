#include<iostream>
#include<string>
using namespace std;
/*
  1
3 2 4 5         1�ڶ���
  6

  2
3 6 4 1         2�ڶ���
  5

  3
5 6 2 1			3�ڶ���
  4

  4
2 6 5 1			4�ڶ���
  3

  5
4 6 3 1			5�ڶ���
  2

  6
3 5 4 2			6�ڶ���
  1


*/
string s1,s2;//��¼�������ӵ��ַ���
int str_equal(string a,char s1,char s2,char s3,char s4,char s5,char s6)//�Ƚ������ִ������
{
    string b="0000000";
    b[1]=s1;
    b[2]=s2;
    b[3]=s3;
    b[4]=s4;
    b[5]=s5;
    b[6]=s6;
    //cout<<b.substr(1)<<endl;
    if(a==b)
        return 1;
    return 0;
}
int exc(string a,char s1,char s2,char s3,char s4,char s5,char s6)//�м��ĸ�����������
{
    if(str_equal(a,s1,s2,s3,s4,s5,s6)) return 1;
    if(str_equal(a,s1,s3,s5,s2,s4,s6)) return 1;
    if(str_equal(a,s1,s5,s4,s3,s2,s6)) return 1;
    if(str_equal(a,s1,s4,s2,s5,s3,s6)) return 1;
    return 0;
}
int main()
{
    char c;
    while(cin>>c)
    {
//        cin>>s1;
//        s2=s1.substr(5);
//        s1.assign(s1,0,6);
//        cout<<s1<<" "<<s2<<endl;
        //����ע����һ�����뷽������������һ��

        s1=s2="0000000";
        s1[1]=c;
        for(int i=2;i<=6;i++)  //��Ϊs1[1]�Ѿ���while��������
            cin>>s1[i];
        for(int i=1;i<=6;i++)
            cin>>s2[i];
        //cout<<s1.substr(1)<<"  "<<s2<<endl;

        if(exc(s1,s2[1],s2[2],s2[3],s2[4],s2[5],s2[6])){cout<<"TRUE"<<endl;continue;}
        if(exc(s1,s2[2],s2[6],s2[3],s2[4],s2[1],s2[5])){cout<<"TRUE"<<endl;continue;}
        if(exc(s1,s2[3],s2[6],s2[5],s2[2],s2[1],s2[4])){cout<<"TRUE"<<endl;continue;}
        if(exc(s1,s2[4],s2[6],s2[2],s2[5],s2[1],s2[3])){cout<<"TRUE"<<endl;continue;}
        if(exc(s1,s2[5],s2[6],s2[4],s2[3],s2[1],s2[2])){cout<<"TRUE"<<endl;continue;}
        if(exc(s1,s2[6],s2[5],s2[3],s2[4],s2[2],s2[1])){cout<<"TRUE"<<endl;continue;}

        cout<<"FALSE"<<endl;

    }
    return 0;
}
//AC at 2018/4/20
