//˼·ûʲô�ѵģ�ͨ���ж�ָ����ַ���ʲô�����滻�ո������������ҵ�Ԫ�ء�
//��Ҫ���߼������׳������о���һЩ���׺��ӵ�С���塣
//Ҫע��Ķ�д����ע����
#include<iostream>
#include<cstdio>
using namespace std;
void dis(char puzz[5][5])//Ϊ���ڲ���ʱ����ۿ�����д�˺���
{
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<4;j++)
            cout<<puzz[i][j]<<" ";//ע��ÿ�����һ���ַ������пո�
        cout<<puzz[i][4];
        cout<<endl;
    }

}
int main()
{
    char puzz[5][5];
    char mov;
    int N=1;//����
    int si,sj;//�ո�����
    while(gets(puzz[0])&&puzz[0][0]!='Z')//�Ƚ��յ�һ�У��Ա���ж�Z
    {
        //cout<<puzz[0][0]<<endl;
        int iff=1;//0ΪԽ����������
//        gets(puzz[0]);
//        if(puzz[0][0]=='Z')//�жϿ���д������
//            break;
        for(int i=0;i<5;i++)
        {
            if(i>0)
                gets(puzz[i]);
            //scanf("%[^\n]",puzz[i]);
            for(int j=0;j<5;j++)
            {
                //cout<<puzz[i][j];
                if(puzz[i][j]==' ')
                {
                    si=i;
                    sj=j;
                }
            }
            //cout<<endl;
        }
        //dis(puzz);cout<<si<<"  "<<sj<<endl;
        while((mov=getchar())!='0')
        {
            switch(mov)
            {
                case 'L':
                    if(sj-1<0){iff=0;break;}
                    puzz[si][sj]=puzz[si][sj-1];//���ƶ�λ����ո񼴿ɣ����ؽ��ƶ�λ���ɿո�
                    sj--;
                    break;
                case 'R':
                    if(sj+1>4){iff=0;break;}
                    puzz[si][sj]=puzz[si][sj+1];
                    sj++;
                    break;
                case 'A':
                    if(si-1<0){iff=0;break;}
            //cout<<"___A"<<endl;
                    puzz[si][sj]=puzz[si-1][sj];
                    si--;
                    break;
                case 'B':
                    if(si+1>4){iff=0;break;}
                    puzz[si][sj]=puzz[si+1][sj];
                    si++;
                    break;
            }
            //if(iff==0) break;
        }
        if(N!=1)//�����Ȼ�������������Ե�һ�����ǰ�����п���
            cout<<endl;
        printf("Puzzle #%d:\n",N++);
        if(iff==0)
        {
            cout<<"This puzzle has no final configuration."<<endl;
        }
        else
        {
            puzz[si][sj]=' ';
            dis(puzz);
        }
        getchar();//����0��Ļ��з�
        //cout<<"end"<<endl;
    }
    return 0;
}
//AC at 2017/12/14

