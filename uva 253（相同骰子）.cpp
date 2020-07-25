#include<iostream>
#include<string>
using namespace std;
/*
  1
3 2 4 5         1在顶上
  6

  2
3 6 4 1         2在顶上
  5

  3
5 6 2 1			3在顶上
  4

  4
2 6 5 1			4在顶上
  3

  5
4 6 3 1			5在顶上
  2

  6
3 5 4 2			6在顶上
  1


*/
string s1,s2;//记录两个骰子的字符串
int str_equal(string a,char s1,char s2,char s3,char s4,char s5,char s6)//比较两个字串相等吗
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
int exc(string a,char s1,char s2,char s3,char s4,char s5,char s6)//中间四个面的四种情况
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
        //以上注释是一种输入方法，以下是另一种

        s1=s2="0000000";
        s1[1]=c;
        for(int i=2;i<=6;i++)  //因为s1[1]已经在while中输入了
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
