#include<iostream>
#include<string>
#include<string.h>
using namespace std;

string r="A   3  HIL JM O   2TUVWXY501SE Z  8 ";
char *m_c="AHIMOTUVWXY018";

char mir_c(char c)
{
    if(c>='A'&&c<='Z')
    {
        c=r[c-'A'];
    }
    else if(c>='0'&&c<='9')//如果不是else if 那么变成2的S又会变回S
        c=r[c-'0'+26];
    return c;
}
int  main()
{
    string s;
    while(cin>>s)
    {

    int n=s.size();
    int m1=2,m2=3,i;//先判断对称，再判断镜像
    for(i=0;i<n/2;i++)
    {
        if(s[i]!=s[n-i-1]) m1=1;
        if(mir_c(s[i])!=s[n-i-1])
        {
            //cout<<mir_c(s[i])<<" "<<s[n-i-1];
            m2=1;
        }
    }
    if((n%2==1)&&strchr(m_c,s[n/2])==NULL) m2=1;
    //cout<<m1<<" "<<m2<<" ";
    cout<<s;
    switch(m1*=m2)
    {
        case 1:cout<<" -- is not a palindrome."<<endl<<endl;break;
        case 2:cout<<" -- is a regular palindrome."<<endl<<endl;break;
        case 3:cout<<" -- is a mirrored string."<<endl<<endl;break;
        case 6:cout<<" -- is a mirrored palindrome."<<endl<<endl;break;
    }
    }
    return 0;
}
