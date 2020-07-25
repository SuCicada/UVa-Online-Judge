/*
这道题很繁琐，最后一直过不了参考了例题的代码，简单说一下思路。
**-1、**我们先定义两个二维数组，一个用于操作（我们称其为 原始数组），另一个用于将操作完的数据拷贝过来（我们将其称为 临时数组），再将整理好的数据考回第一个数组，用于下次操作
**0、**而且我们的每个元素的数值也是有蹊跷的，最好是要看着元素的值就能知道它起初的位置。我们可以用，
① 第 i 行 第 j 列元素 =（i - 1）* 总列数 + j - 1;之所以要减一是因为我的数组计数是从下标0开始，其实这样不太好，容易混乱，像书上一样从1开始就不错
②书上是这个意思：先定义一个大数BIG=10000；第 i 行 第 j 列元素 = i * BIG +j  ；这样的话 行数就是在万位以上了，和列数分开了。我们只要用 元素 / BIG 和 元素 % BIG 就能得到 行和列的序号。
**1、**删除：先记录要删除的行（列）序号，再在原始数组中将这一行（列）的数据变成0，然后在复制给临时数组时，判断不是0的拷贝即可
**2、**复制：这个方法是采用了书上的，之后我再说我的不好的方法。
我们事先定义一个一维数组，用这个数组记录下要加的行（列），要加的行（列）序号就在 对应的一维数组的下标的元素记为1，然后在拷贝时，我们依次判断一维数组的各个元素是不是1，是则停止原始数组的拷贝，加入一行（列）元素都为0的行，否则拷贝一行（列）原始数组
**3、**交换：直接交换
**4、**判断坐标：
①我一开始的方法是先通过原始坐标 算出那个位置上的原始元素值，然后依次遍历更改后的数组，找到了就输出当前所遍历到的行和列的序号，没找到就是GONE了
②书上的意思是：又创建了一个二维数组用此数组记录改变的情况：				
ans[此元素的][原始位置] = 代表“改变后的位置”的数值
所以我们分析一个原始位置，就可以直接通过下标来找到改变后的位置。
这两种方法各有好坏，前者费时节省空间，后者费空间省时；不过你也可以不用创建新的数组，用临时数组来记录应该也行。这样的话就不比前者方法费空间了
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
int rnum,cnum;//行数，列数
void Roper_to_temp(int T=0)
{
    memset(temp_list,0,sizeof(temp_list));
    int in=0;//记录增加到第几个了
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
//        if(T&&in<T&&i+1==oper_list[rnum+in][0])//若当前行是要增加的行
//        {
//            in++;
//            //cout<<in<<"  !! "<<temp_r<<endl;
//            for(int j=0;j<cnum;j++)
//                temp_list[temp_r][j] = 0;
//            temp_r++;
//            i--;
//            continue;
//        }
        if(oper_list[i][0]==-1)//代表这一行要删掉
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
    for(int i=0;i<cnum;i++)//注意 +T
    {
//        cout<<"copy temp "<<temp_c<<endl;
//        cout<<"in "<<in<<"  operlist  "<<oper_list[0][cnum+in]<<endl;
        if(T&&cols[i]==1)
        {
            for(int j=0;j<rnum;j++)
                temp_list[j][temp_c]=0;
            temp_c++;
        }
//        if(T&&in<T&&i+1==oper_list[0][cnum+in])//若当前列是要增加的行
//        {
//            in++;
//            for(int j=0;j<rnum;j++)
//                temp_list[j][temp_c] = 0;
//            temp_c++;
//            i--;
//            continue;
//        }
        if(oper_list[0][i]==-1)//代表这一列要删掉
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
    cin>>T;//增加的次数
    int oper;//oper[15];
    for(int i=0;i<T;i++)
    {
        cin>>oper;//[i];
        for(int j=0;j<cnum;j++)//删除的行中的值变成 -1
            oper_list[oper-1][j]= -1;
    }
    Roper_to_temp();
    rnum-=T;//行数少T
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
        for(int j=0;j<rnum;j++)//删除的列中值变成 -1
            oper_list[j][oper-1]=-1;
    }

    Coper_to_temp();
    cnum-=T;//列数少T
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
        //oper_list[rnum+i][0]=oper;//最后加一行，第一个元素值是要加的行号
    }


    Roper_to_temp(T);
    rnum+=T;//行数多T
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
    cnum+=T;//列数多T
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
void visit(int Cn)//遍历的方法
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
void visit2()//数组按址索迹
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

        int Cn=cnum;//用于遍历时留存的列数
        for(int i=0;i<rnum;i++)
            for(int j=0;j<cnum;j++)
                oper_list[i][j]=(i+1)*BIG+j+1;//i*cnum+j+1;//从1开始依次给值

//        for(int i=0;i<rnum;i++)
//        {
//            for(int j=0;j<cnum;j++)
//                cout<<setw(3)<<oper_list[i][j];
//            cout<<endl;
//        }

        int T_DI;//操作数
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
        for(int i=1;i<=rnum;i++)//打表，记录元素先后位置
            for(int j=1;j<=cnum;j++)
                ans_list[oper_list[i-1][j-1]/BIG][oper_list[i-1][j-1]%BIG]=(i)*BIG+j;
				//ans[此元素的][原始位置] = 代表’改变后的位置‘的 数值
        if(T>1)
            cout<<endl;
        cout<<"Spreadsheet #"<<T++<<endl;
        int T_xy;
        cin>>T_xy;
        while(T_xy--)
            visit2();
            //visit(Cn);//认祖归宗
    }
    return 0;
}
//AC at 2018/2/16
