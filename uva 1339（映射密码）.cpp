//1、我们只需要分别记录两个字串里出现的各个字母的数量，
//2、然后从小到大或从大到小排序，
//3、之后进行比较，如果两个字串对应，那么他们的字母数量表相同下标的元素值（代表字母的数量）也应该相同。
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
    string str,guess;//输入的两个字串
    while(cin>>str>>guess)
    {
        int cha1[26]={0},cha2[26]={0};//分别记录两个字串里的各个字母的数量

        for(int i=0;i<str.size();i++)//记录str里各个字母数量
        {
            cha1[str[i]-'A']++;
            cha2[guess[i]-'A']++;
        }
        ssqrt(cha1);//对各个字母量排序
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

        for(int i=1;i<26;i++)//比较排序后的字母量串
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