//三种情况：bbbbb aa (|a|:ab重叠
//1.短块在长块里(bb|aa|b)
//2.短块头在长块里（外），短块尾巴超出长块尾(bbbb|a|a)
//3.长块头在短块尾（外），长块尾巴超出短块尾(a|a|bbbb)
//不要忘记第三种情况，有时最短空间就是出自3
#include<iostream>
#include<cstring>
using namespace std;
const int N = 100;
//int kick1[N+5],kick2[N+5];
int kickdown(string k1,string k2)//定k1，移k2
{
        //cout<<k1.size()<<"  "<<k2.size()<<endl;
    for(int i=0;i<k1.size();i++)
    {
        int ii=i,j=0;//i就是大小块契合的那一位
        //cout<<ii<<" "<<j<<endl;
        while((k1[ii]-'0'+k2[j]-'0')<=3&&(j<k2.size()&&ii<k1.size()))//若当前位不匹配则进行for到下一位
        {
            //cout<<"k1 ii "<<ii<<"  "<<k1[ii]<<" | k2 j"<<j<<"  "<<k2[j]<<endl;
            ii++;
            j++;
        }
        if(j==k2.size()||ii==k1.size())//若是寿终正寝（即循环到块尾了）
        {
            //cout<<j<<"  i "<<i<<endl;
            return (i+k2.size())>=k1.size()?(i+k2.size()):k1.size();
            //若i+k2.size()比k1（长块）的长度还短，那么所需长度就直接是k1长度了
            /*下面是通俗代码*/
            //space=i+k2.size();
            //if(space<k1.size())
            //    space=k1.size();
            //break;
        }
    }
    return k1.size()+k2.size();//若没有契合处，只能接到后面了
}

int main()
{
    string k1,k2;//咱们要k1>k2
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
