#include<iostream>
#include<vector>
#include<string>
using namespace std;

int n;
const int MAX=25;
vector<int>pile[MAX];
void find_a(int a,int&p,int&h)//传递a的地址
{
    for(p=0;p<n;p++)
        for(h=0;h<pile[p].size();h++)
            if(a==pile[p][h])
                return;
}

void clear_a(int p,int h)//h上的元素归原位
{
    for(int i=h+1;i<pile[p].size();i++)
    {
        int a=pile[p][h];
        pile[a].push_back(a);
    }
    pile[p].resize(h+1);
}
void onto(int p,int h,int p2)//p的h及其以上的元素放到p2上
{
    for(int i=h;i<pile[p].size();i++)
        pile[p2].push_back(pile[p][i]);
    pile[p].resize(h);
}
void dis()
{
    for(int i=0;i<n;i++)
    {
        cout<<i<<":";
        for(int j=0;j<pile[i].size();j++)
            cout<<pile[i][j]<<" ";
        cout<<endl;
    }
}
int main()
{
    int a,b;
    string s1,s2;
    cin>>n;
    for(int i=0;i<n;i++)
        pile[i].push_back(i);
    while(cin>>s1&&s1!="quit")
    {
        //cin>>a>>s2>>b;
        int pa,ha,pb,hb;
        find_a(a,pa,ha);
        find_a(b,pb,hb);
    //cout<<pa<<"  "<<ha<<"  "<<pb<<"  "<<hb<<endl;
        if(pa==pb) continue;
        if(s2=="onto") clear_a(pb,hb);
        if(s1=="move") clear_a(pa,ha);
        onto(pa,ha,pb);
    }
        dis();
    return 0;
}
