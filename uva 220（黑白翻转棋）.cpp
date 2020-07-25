#include<iostream>
#include<iomanip>
using namespace std;
char board[10][10];
int yesnum=0;//输出空格的格式
char disk,nodisk;//要走的棋，被翻的棋
//int exceed(int i,int j)//判断越界
//{
//    if(i>=1&&i<=8&&j>=1&&j<=8)
//        return 1;
//    else
//        return 0;
//}
int reverse(int i,int j,int con)//(i,j)上应该是空的
{
    for(int in=-1;in<=1;in++)//八个方位的循环
    {
        for(int jn=-1;jn<=1;jn++)//八个方位的循环用于翻棋子
        {
            if(in==0&&jn==0) continue;//中间的棋不用管它先
//            if(i+in>=1&&i+in<=8&&j+jn>=1&&j+jn<=8&&/*exceed(i+in,j+jn)&&*/
//               board[i+in][j+jn]==nodisk)//可翻  //board[i+in][j+jn]=='-')//有空位能放子
//            {
                //cout<<"board  "<<board[i+in][j+jn]<<endl;
            int n=1;//用于能翻的子的包的界限标志（说不懂，见下面第一个if）
            while((i+in*n>=1&&i+in*n<=8&&j+jn*n>=1&&j+jn*n<=8)&&/*exceed(i-in*n,j-jn*n)*///判断越界
                  board[i+in*n][j+jn*n]==nodisk)//还能继续翻
            {
                n++;
            }
            if(board[i+in*n][j+jn*n]==disk&&n>1)//包住了，就翻这么多
            {
                //cout<<i+in*n<<"_"<<j+jn*n<<"_"<<board[i+in*n][j+jn*n]<<" "<<endl;
                if(con=='L')
                {
                    if(yesnum>0) cout<<" ";
                    cout<<"("<<i<<","<<j<<")";
                    yesnum++;
                    return 0;
                }
                else
                {
                    for(int n2=0;n2<n;n2++)//翻转操作，--n为了不bang掉最后的disk
                    {
                        board[i+in*n2][j+jn*n2]=disk;
                    }
                }
                //break;
            }
            //}
        }
    }
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        for(int i=1;i<=8;i++)//存表
            for(int j=1;j<=8;j++)
                cin>>board[i][j];
        char con;//下一个子，操作
        cin>>disk;
        int Wnum=0,Bnum=0;
        while(cin>>con&&con!='Q')
        {
            if(disk=='W') nodisk = 'B';
            else nodisk = 'W';
            //cout<<"disk "<<disk<<endl;
            if(con=='L')//显示下一步可走子
            {
                yesnum=0;
                for(int i=1;i<=8;i++)//全地图遍历
                {
                    for(int j=1;j<=8;j++)//全地图遍历
                    {
                        if(board[i][j]=='-')//如果可以翻
                        {
                            //cout<<disk<<"  "<<i<<" ij "<<j<<endl;
                            reverse(i,j,'L');
                        }
                    }
                }
                if(!yesnum)
                {
                    cout<<"No legal move.";
                    if(disk=='W') disk='B';
                    else disk = 'W';
                }
                cout<<endl;
            }
            else
            {
                int x;
                cin>>x;
                reverse(x/10,x%10,'M');
                Bnum=Wnum=0;
                for(int i=1;i<=8;i++)
                    for(int j=1;j<=8;j++)
                        if(board[i][j]=='B')
                            Bnum++;
                        else if(board[i][j]=='W')
                            Wnum++;
                cout<<"Black -"<<setw(3)<<Bnum<<" White -"<<setw(3)<<Wnum<<endl;

                if(disk=='W') disk='B';
                else disk = 'W';
            }

        }
        for(int i=1;i<=8;i++)
        {
            for(int j=1;j<=8;j++)
                cout<<board[i][j];
            cout<<endl;
        }
        if(T>=1)
            cout<<endl;
    }
    return 0;
}
//AC at 2018/3/9
