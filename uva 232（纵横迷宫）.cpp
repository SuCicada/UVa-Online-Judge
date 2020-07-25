//以汉字书写顺序，先左到右，在上到下依次边遍历，边输出，
//凡是输出的格子以@代替，之所以不用*代替是为了统计起始格的个数。
//本题因为说了行列的范围，所以直接用char型的二维数组即可。
//而我没注意以为是任意行列的数组，所以用了动态内存分配生成二维数组。（代码数多在这了）
//其他注意点在代码里注释了。
#include<iostream>
#include<iomanip>
using namespace std;

int hang,lie;
//测试有显示函数
//void dis(char **puzz)
//{
//    for(int i=0;i<hang;i++)
//    {
//        for(int j=0;j<lie;j++)
//            cout<<puzz[i][j];
//        cout<<endl;
//    }
//}
char** creat()
{
    char **puzz;
    puzz=new char*[hang];
    for(int i=0;i<hang;i++)
        puzz[i]=new char[lie];
    return puzz;
}

void print(char **puzz,char AD)
{
    int i,j,pi,pj,*pij;//p系列是为打印一组字符的
    if(AD=='A')
    {
        cout<<"Across";
        pij=&pj;
    }
    if(AD=='D')
    {
        cout<<"Down";
        pij=&pi;
    }
    int qsg=0;
    for(i=0;i<hang;i++)
        for(j=0;j<lie;j++)
        {
            //cout<<i<<"  "<<j<<"  "<<puzz[i][j]<<"  ????"<<endl;
            if(puzz[i][j]=='*')//把*当作起始格就不好了
                continue;
            bool iff=false;
            if(j==0||i==0)//找起始格
            {
                iff=true;
                qsg++;
            }
            else if(puzz[i][j-1]=='*'||puzz[i-1][j]=='*')//为了防止j-1和i-1小于0的情况
            {
                iff=true;
                qsg++;
            }
            if(iff)
            {
                if(puzz[i][j]=='@')//虽然此元素也在起始格，但是因为已经被走过了，所以不允许其捣乱
                        continue;//不能break
                cout<<endl//开始一组才换行，防止多余空行
                    <<setw(3)//注意是3格的右对齐
                    <<qsg<<".";
                pi=i;
                pj=j;
                while(puzz[pi][pj]!='*')//输出across的字符
                {
                    cout<<puzz[pi][pj];
                    puzz[pi][pj]='@';
                    (*pij)++;
                    if(!(pj<lie&&pi<hang))//一旦下标越界，就会出错
                        break;
//                    if(AD=='A')
//                        j++;
//                    if(AD=='D')
//                        i++;
                }
            }
            //if(pj<lie&&pi<hang)//还有更好的办法吗//yes
                //cout<<endl;
        }
    cout<<endl;
}


int main()
{
    int num=1;
    while(cin>>hang&&hang!=0)
    {
        cin>>lie;
        if(num>1)
            cout<<endl;
        cout<<"puzzle #"<<num++<<":"<<endl;
        char **puzz;
        puzz=creat();//必须把指针传回来
        for(int i=0;i<hang;i++)//原始迷宫
            for(int j=0;j<lie;j++)
            {
                //puzz[i][j]='o';
                cin>>puzz[i][j];
            }
        //dis(puzz);
        char **puzz2;
        puzz2=creat();
        for(int i=0;i<hang;i++)//克隆的迷宫
            for(int j=0;j<lie;j++)
                puzz2[i][j]=puzz[i][j];
        print(puzz,'A');
        //cout<<endl;
        print(puzz2,'D');
        //    cout<<endl;
      //  dis(puzz2);
    }
    return 0;
}
//AC at 2017/12/18
