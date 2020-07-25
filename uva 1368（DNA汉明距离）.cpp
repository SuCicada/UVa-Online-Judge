//能解出来就是好的，有时候略微繁琐一些是在所难免的。
//It's not necessary to tack such a toxic attitude around that it's slightly difficult.（不必对其仿佛洪水猛兽。）
#include<iostream>
#include<string.h>
using namespace std;
const int M=50,N=1000;
char dna[M+5][N+5];
int acgt[4][N+5];
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int m,n;
        cin>>m>>n;
        int hamming=0;
        memset(acgt,0,sizeof(acgt));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>dna[i][j];
                switch(dna[i][j])
                {
                    case 'A':acgt[0][j]++;break;//注意字典序
                    case 'C':acgt[1][j]++;break;
                    case 'G':acgt[2][j]++;break;
                    case 'T':acgt[3][j]++;break;
                }
            }
        }
        for(int j=0;j<n;j++)
        {
            int maxx=acgt[0][j],nn=0;
            for(int j2=1;j2<4;j2++)
            {
                if(maxx<acgt[j2][j])
                {
                   maxx=acgt[j2][j];
                   nn=j2;
                }
            }
            switch(nn)
            {
                case 0:cout<<'A';break;
                case 1:cout<<'C';break;
                case 2:cout<<'G';break;
                case 3:cout<<'T';break;
            }
            hamming+=(m-acgt[nn][j]);//行数-最大字符数量=单列汉明
        }
        cout<<endl<<hamming<<endl;
    }
    return 0;
}
//AC at 2017/12/22
