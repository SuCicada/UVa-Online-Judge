/*
�����ܷ��������һֱ�����˲ο�������Ĵ��룬��˵һ��˼·��
**-1��**�����ȶ���������ά���飬һ�����ڲ��������ǳ���Ϊ ԭʼ���飩����һ�����ڽ�����������ݿ������������ǽ����Ϊ ��ʱ���飩���ٽ�����õ����ݿ��ص�һ�����飬�����´β���
**0��**�������ǵ�ÿ��Ԫ�ص���ֵҲ�������εģ������Ҫ����Ԫ�ص�ֵ����֪���������λ�á����ǿ����ã�
�� �� i �� �� j ��Ԫ�� =��i - 1��* ������ + j - 1;֮����Ҫ��һ����Ϊ�ҵ���������Ǵ��±�0��ʼ����ʵ������̫�ã����׻��ң�������һ����1��ʼ�Ͳ���
�������������˼���ȶ���һ������BIG=10000���� i �� �� j ��Ԫ�� = i * BIG +j  �������Ļ� ������������λ�����ˣ��������ֿ��ˡ�����ֻҪ�� Ԫ�� / BIG �� Ԫ�� % BIG ���ܵõ� �к��е���š�
**1��**ɾ�����ȼ�¼Ҫɾ�����У��У���ţ�����ԭʼ�����н���һ�У��У������ݱ��0��Ȼ���ڸ��Ƹ���ʱ����ʱ���жϲ���0�Ŀ�������
**2��**���ƣ���������ǲ��������ϵģ�֮������˵�ҵĲ��õķ�����
�������ȶ���һ��һά���飬����������¼��Ҫ�ӵ��У��У���Ҫ�ӵ��У��У���ž��� ��Ӧ��һά������±��Ԫ�ؼ�Ϊ1��Ȼ���ڿ���ʱ�����������ж�һά����ĸ���Ԫ���ǲ���1������ֹͣԭʼ����Ŀ���������һ�У��У�Ԫ�ض�Ϊ0���У����򿽱�һ�У��У�ԭʼ����
**3��**������ֱ�ӽ���
**4��**�ж����꣺
����һ��ʼ�ķ�������ͨ��ԭʼ���� ����Ǹ�λ���ϵ�ԭʼԪ��ֵ��Ȼ�����α������ĺ�����飬�ҵ��˾������ǰ�����������к��е���ţ�û�ҵ�����GONE��
�����ϵ���˼�ǣ��ִ�����һ����ά�����ô������¼�ı�������				
ans[��Ԫ�ص�][ԭʼλ��] = �����ı���λ�á�����ֵ
�������Ƿ���һ��ԭʼλ�ã��Ϳ���ֱ��ͨ���±����ҵ��ı���λ�á�
�����ַ������кû���ǰ�߷�ʱ��ʡ�ռ䣬���߷ѿռ�ʡʱ��������Ҳ���Բ��ô����µ����飬����ʱ��������¼Ӧ��Ҳ�С������Ļ��Ͳ���ǰ�߷����ѿռ���
*/
#include<iostream>
#include<string>
#include<iomanip>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAX = 100;

int oper_list[MAX][MAX],temp_list[MAX][MAX],ans_list[MAX][MAX];
int cols[MAX];
int rnum,cnum;//����������
void Roper_to_temp(int T=0)
{
    memset(temp_list,0,sizeof(temp_list));
    int in=0;//��¼���ӵ��ڼ�����
    int temp_r=0;
    for(int i=0;i<rnum;i++)
    {
        //cout<<i<<" =?= "<<rnum+in<<"  "<<oper_list[rnum+in][0]<<endl;
        if(T&&cols[i]==1)
        {
            for(int j=0;j<cnum;j++)
                temp_list[temp_r][j]=0;
            temp_r++;
        }
//        if(T&&in<T&&i+1==oper_list[rnum+in][0])//����ǰ����Ҫ���ӵ���
//        {
//            in++;
//            //cout<<in<<"  !! "<<temp_r<<endl;
//            for(int j=0;j<cnum;j++)
//                temp_list[temp_r][j] = 0;
//            temp_r++;
//            i--;
//            continue;
//        }
        if(oper_list[i][0]==-1)//������һ��Ҫɾ��
            continue;
        for(int j=0;j<cnum;j++)
            temp_list[temp_r][j] = oper_list[i][j];
        temp_r++;
    }
}
//void Roper_to_temp(int T=0)
//{
//    int n=0;
//    for(int i=0;i<rnum+T;i++)
//    {
//        if(i==temp_list[rnum+n][0])
//        {
//            n++;
//  `         i++;
//            continue;
//        }
//        for(int j=0;j<cnum;j++)
//            temp_list[i][j] = oper_list[i][j];
//    }
//}
void Coper_to_temp(int T=0)
{
    memset(temp_list,0,sizeof(temp_list));
    int in=0;
    int temp_c=0;
    //cout<<"ttt "<<T<<endl;
    for(int i=0;i<cnum;i++)//ע�� +T
    {
//        cout<<"copy temp "<<temp_c<<endl;
//        cout<<"in "<<in<<"  operlist  "<<oper_list[0][cnum+in]<<endl;
        if(T&&cols[i]==1)
        {
            for(int j=0;j<rnum;j++)
                temp_list[j][temp_c]=0;
            temp_c++;
        }
//        if(T&&in<T&&i+1==oper_list[0][cnum+in])//����ǰ����Ҫ���ӵ���
//        {
//            in++;
//            for(int j=0;j<rnum;j++)
//                temp_list[j][temp_c] = 0;
//            temp_c++;
//            i--;
//            continue;
//        }
        if(oper_list[0][i]==-1)//������һ��Ҫɾ��
            continue;
        for(int j=0;j<rnum;j++)
            temp_list[j][temp_c] = oper_list[j][i];
        temp_c++;
    }
}
void temp_to_oper()
{
    memcpy(oper_list,temp_list,sizeof(temp_list));
//    for(int i=0;i<rnum;i++)
//        for(int j=0;j<cnum;j++)
//            oper_list[i][j] = temp_list[i][j];
}
void dr_oper()
{
    int T;
    cin>>T;//���ӵĴ���
    int oper;//oper[15];
    for(int i=0;i<T;i++)
    {
        cin>>oper;//[i];
        for(int j=0;j<cnum;j++)//ɾ�������е�ֵ��� -1
            oper_list[oper-1][j]= -1;
    }
    Roper_to_temp();
    rnum-=T;//������T
    temp_to_oper();

}
void dc_oper()
{
    int T;
    cin>>T;
    int oper;
    for(int i=0;i<T;i++)
    {
        cin>>oper;
        for(int j=0;j<rnum;j++)//ɾ��������ֵ��� -1
            oper_list[j][oper-1]=-1;
    }

    Coper_to_temp();
    cnum-=T;//������T
    temp_to_oper();

}

void ir_oper()
{
    memset(cols,0,sizeof(cols));
    int T;
    cin>>T;
    int oper;
    for(int i=0;i<T;i++)
    {
        cin>>oper;
        cols[oper-1]=1;
        //oper_list[rnum+i][0]=oper;//����һ�У���һ��Ԫ��ֵ��Ҫ�ӵ��к�
    }


    Roper_to_temp(T);
    rnum+=T;//������T
    temp_to_oper();
}
void ic_oper()
{
    memset(cols,0,sizeof(cols));
    int T;
    cin>>T;
    int oper;
    for(int i=0;i<T;i++)
    {
        cin>>oper;
        cols[oper-1]=1;
        //oper_list[0][cnum+i]=oper;
        //cout<<"oper  "<<cnum+i<<" "<<oper_list[0][cnum+i]<<endl;
    }

    Coper_to_temp(T);
    cnum+=T;//������T
    temp_to_oper();



}
void exc_oper()
{
    int r1,c1,r2,c2;
    cin>>r1>>c1>>r2>>c2;
    int temp = oper_list[r1-1][c1-1];
    oper_list[r1-1][c1-1] = oper_list[r2-1][c2-1];
    oper_list[r2-1][c2-1] = temp;
}
void visit(int Cn)//�����ķ���
{
    int x,y;
    int iff=0;
    cin>>x>>y;
    //cout<<"!!"<<(x-1)*Rn+y<<endl;
    for(int i=0;i<rnum;i++)
        for(int j=0;j<cnum;j++)
        {
            if(oper_list[i][j]==(x-1)*Cn+y)
            {
                iff=1;
                printf("Cell data in (%d,%d) moved to (%d,%d)\n",x,y,i+1,j+1);
                return;
            }
        }
    if(iff==0)
    {
        printf("Cell data in (%d,%d) GONE\n",x,y);
    }

}


const int BIG = 10000;
void visit2()//���鰴ַ����
{
    int x,y;
    cin>>x>>y;
    printf("Cell data in (%d,%d) ",x,y);
    if(ans_list[x][y]==0)
        cout<<"GONE"<<endl;
    else
        printf("moved to (%d,%d)\n",ans_list[x][y]/BIG,ans_list[x][y]%BIG);
}
int main()
{
    int T=1;
    while(cin>>rnum>>cnum&&rnum!=0&&cnum!=0)
    {

        memset(oper_list,0,sizeof(oper_list));
//        if(rnum==0&&cnum==0)
//            break;

        int Cn=cnum;//���ڱ���ʱ���������
        for(int i=0;i<rnum;i++)
            for(int j=0;j<cnum;j++)
                oper_list[i][j]=(i+1)*BIG+j+1;//i*cnum+j+1;//��1��ʼ���θ�ֵ

//        for(int i=0;i<rnum;i++)
//        {
//            for(int j=0;j<cnum;j++)
//                cout<<setw(3)<<oper_list[i][j];
//            cout<<endl;
//        }

        int T_DI;//������
        cin>>T_DI;
        while(T_DI--)
        {
            string DIRC;//char DIRC[4];
            //int DI_num;
            cin>>DIRC;
            if(DIRC=="DR")
                dr_oper();
            else if(DIRC=="DC")
                dc_oper();
            else if(DIRC=="IR")
                ir_oper();
            else if(DIRC=="IC")
                ic_oper();
            else if(DIRC=="EX")
                exc_oper();

//        cout<<endl<<rnum<<" * "<<cnum<<endl;
//        for(int i=0;i<rnum;i++)
//        {
//            for(int j=0;j<cnum;j++)
//                cout<<setw(3)<<oper_list[i][j];
//            cout<<endl;
//        }
        }

        memset(ans_list,0,sizeof(ans_list));
        for(int i=1;i<=rnum;i++)//�����¼Ԫ���Ⱥ�λ��
            for(int j=1;j<=cnum;j++)
                ans_list[oper_list[i-1][j-1]/BIG][oper_list[i-1][j-1]%BIG]=(i)*BIG+j;
				//ans[��Ԫ�ص�][ԭʼλ��] = �����ı���λ�á��� ��ֵ
        if(T>1)
            cout<<endl;
        cout<<"Spreadsheet #"<<T++<<endl;
        int T_xy;
        cin>>T_xy;
        while(T_xy--)
            visit2();
            //visit(Cn);//�������
    }
    return 0;
}
//AC at 2018/2/16
