#include<iostream>
#include<iomanip>
using namespace std;
char board[10][10];
int yesnum=0;//����ո�ĸ�ʽ
char disk,nodisk;//Ҫ�ߵ��壬��������
//int exceed(int i,int j)//�ж�Խ��
//{
//    if(i>=1&&i<=8&&j>=1&&j<=8)
//        return 1;
//    else
//        return 0;
//}
int reverse(int i,int j,int con)//(i,j)��Ӧ���ǿյ�
{
    for(int in=-1;in<=1;in++)//�˸���λ��ѭ��
    {
        for(int jn=-1;jn<=1;jn++)//�˸���λ��ѭ�����ڷ�����
        {
            if(in==0&&jn==0) continue;//�м���岻�ù�����
//            if(i+in>=1&&i+in<=8&&j+jn>=1&&j+jn<=8&&/*exceed(i+in,j+jn)&&*/
//               board[i+in][j+jn]==nodisk)//�ɷ�  //board[i+in][j+jn]=='-')//�п�λ�ܷ���
//            {
                //cout<<"board  "<<board[i+in][j+jn]<<endl;
            int n=1;//�����ܷ����ӵİ��Ľ��ޱ�־��˵�������������һ��if��
            while((i+in*n>=1&&i+in*n<=8&&j+jn*n>=1&&j+jn*n<=8)&&/*exceed(i-in*n,j-jn*n)*///�ж�Խ��
                  board[i+in*n][j+jn*n]==nodisk)//���ܼ�����
            {
                n++;
            }
            if(board[i+in*n][j+jn*n]==disk&&n>1)//��ס�ˣ��ͷ���ô��
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
                    for(int n2=0;n2<n;n2++)//��ת������--nΪ�˲�bang������disk
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
        for(int i=1;i<=8;i++)//���
            for(int j=1;j<=8;j++)
                cin>>board[i][j];
        char con;//��һ���ӣ�����
        cin>>disk;
        int Wnum=0,Bnum=0;
        while(cin>>con&&con!='Q')
        {
            if(disk=='W') nodisk = 'B';
            else nodisk = 'W';
            //cout<<"disk "<<disk<<endl;
            if(con=='L')//��ʾ��һ��������
            {
                yesnum=0;
                for(int i=1;i<=8;i++)//ȫ��ͼ����
                {
                    for(int j=1;j<=8;j++)//ȫ��ͼ����
                    {
                        if(board[i][j]=='-')//������Է�
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
