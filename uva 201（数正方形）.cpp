/*
˼·��
�ȿ���������ݣ�
H�������**����**�ĵ���**��**����һ����
V�������**����**�ĵ���**��**����һ����
1����������������ά�����¼������ĵ�����꣬һ��H��ˮƽ����һ��V����ֱ���������ұߵĵ�ͼ�Ϊ1��
2��д����������������Ϊ���ҵķ���ı߳���
3��Ȼ��ӵ�һ���㿪ʼ�������ж����������Ϊ���϶���������Σ����������ǲ��Ǵ��ڣ�����־�����ߵĵ��ֵ�ǲ���1��
4�����ڴ���1�ı߳���˵�����ǿ������ж�ʱ�ø�ѭ����ÿ��ѭ���жϵ��Ǳ߳��е�һ���֣�һ����λ���ȣ��ı��ǲ��Ǵ��ڡ����ɡ�
5�����忴����ɡ�
*/
#include<iostream>
#include<cstring>
using namespace std;
int hor[10][10],ver[10][10];
    int N;
int square(int sq_n)
{
    //cout<<sq_n<<"sq_n"<<endl;
    int sqnum=0,iff=0;
    for(int x=1;x<=N-sq_n;x++)
    {
        for(int y=1;y<=N-sq_n;y++)
        {
            //cout<<hor[x][y]<<"  "<<ver[x][y]<<endl;
            for(int i=0;i<sq_n;i++)//�жϴ���1�߳�������
                if(hor[x][y+i]&&hor[x+sq_n][y+i]&&
                    ver[x+i][y]&&ver[x+i][y+sq_n])
                    iff=1;//�ɷ���

                else
                {
                    iff=0;//���ɷ���
                    break;
                }
            if(iff)
                sqnum++;//����ĸ���
        }
    }
    return sqnum;
}
int main()
{
    int T,TN=1;
    while(cin>>N>>T)
    {
        if(TN>1)
            cout<<endl<<"**********************************"<<endl<<endl;
        cout<<"Problem #"<<TN++<<endl<<endl;

        memset(hor,0,sizeof(hor));
        memset(ver,0,sizeof(ver));
        while(T--)//��¼�����Ϣ
        {
            char hv;
            int x,y;
            cin>>hv>>x>>y;
            if(hv=='H')
                hor[x][y]=1;
            else
                ver[y][x]=1;//ע��ver���Ƿ���
        }

        int num;
        int ifn=0;
        for(int i=1;i<=N;i++)
        {
            num = square(i);
            if(num)
            {
                cout<<num<<" square (s) of size "<<i<<endl;
                ifn++;
            }
        }
        if(!ifn)
            cout<<"No completed squares can be found."<<endl;
    }
    return 0;
}
//AC at 2018/3/4
