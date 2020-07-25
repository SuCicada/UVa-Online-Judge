#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s,a;
    while(cin>>s>>a)
    {
        int sn=0;
        for(int i=0;i<a.size()&&sn<s.size();i++)
        {
            if(a[i]==s[sn])
            {
                sn++;
                //cout<<sn<<"!!"<<endl;
            }
        }
        if(sn==s.size())
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
//AC at 2017/12/30