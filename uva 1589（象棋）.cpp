/*
ע�⣺ 
����ĵ�һ�е�һ��Ϊ���ӵ��������������Ǻڽ���λ�á����������Ǻ������ͺ�λ�á�

˼·�� 
1���ڽ��������߷������������ҡ�����ֻҪ�ж� �Ƿ��������߷��к���Ķ�����· �����жϽ��Ƿ񱻽��� �� 
2�����ж��Ƿ�ǰ�ĺڽ����ӵ�λ���Ƿ��������ǰ�Ľ�����û�г����Ź��� 
3�����ڳ���˧�Ľ��������ǿ���һ���жϣ��ȴӽ���λ�ÿ�ʼ��������һ��·��������ӣ�1��4����10��4�����Ĺ��� 
��1�����·����������˧����ô���ǽ����ˡ� 
��2�����Ƿǳ�˧���ӣ��ͼ�����һ������������c_iff������¼Ŀǰ�ǳ�˧������������ 
��3�������ڣ��ж���ǰ�Ƿ���һ���ӣ�c_iff��ֵ�ǲ���һ�������ǣ����� �� 
��4��������ν���˳�δӺڽ���ʼ�ֱ���һ�У���һ�У���һ�У���һ�б��������ϵ��ӡ�����һ��ѭ������������룬���ǽ���Ӧ�ĸ�ѭ��������д��һ��ѭ�������� if ������ 
4��������Ľ��������ǿ��Ե����жϡ���ͼ,(x,y)λ��Ϊ�ڽ����ڿ�λ��Ϊ�����ȣ�����˴�û������ô�������ڵ�����λ��������Ļ��Ϳ��Խ����ˡ� 
����дͼƬ���� 
����ļ���1������ѭ�������ĸ����򣬼����� 
����2���ڿ�λ�ã���x+i��y+j�����������ڵ���x+i+i��y+j���ͣ�x+i��y+j+j�� 
5��ע�⣺����һ�����壬���ǻ�Ҫ����һ��ʼ�ڽ��ͺͺ�˧���棬�����Ļ��ڽ��Ϳ���ֱ�ӻ�ɱ��˧��������
2 1 5
G 10 5
R 1 1

*/
#include<iostream>
#include<cstring>
using namespace std;
char board[14][15];//9*10������
int checkmate(int rx,int ry)
{
    //cout<<"rx "<<rx<<"  ry  "<<ry<<endl;
    if((rx<1||rx>3)||(ry<4||ry>6))//���Ӽ�Խ�磬�������߷�
    {
        //cout<<"escape"<<endl;
        return 1;
    }

    int c_iff=0;//��ǰ���Ӽ�1
    int ix=-1,iy=0;
    int x=rx+ix;//!ע�⣺һ��ʼ��λ�þ��ǽ���λ�ã�����Ҫ�ȱܿ���ͬʱģ���˳���
    int y=ry;
    //int xy,rc_n=10;
//    for(;y<=9;y+=ic)
//    for(;/*x>=1&&*/x<=10;x+=ic)
    for(;y<=9;x+=ix,y+=iy)//3.(4)�ļ��ɼ�33--54��
    {
        //cout<<"x "<<x<<" y "<<y<<endl;
        if(x<1)//�ϱ߹����ˣ��͸ù��±ߵ���
            {ix=1;x=rx;c_iff=0;continue;}
        
		if(x>10)//�ñ��������ˣ�������
        {
            ix=0;//ע�⣺������x�Ͳ��ܶ���
            iy=-1;
            x=rx;
            c_iff=0;
            continue;
        }
        if(y<1)//���б���������������
            {iy=1;y=ry;c_iff=0;continue;}

        if(board[x][y]=='0')//û����
            continue;
			
        //�����ǰ���ڻ���֮ǰû�й� ��
        if((c_iff==0&&(board[x][y]=='R'||board[x][y]=='G'))||//����
           (board[x][y]=='C'&&c_iff==1))//�ڻ�����
        {
            //cout<<board[x][y]<<"  "<<x<<" "<<y<<" dead"<<endl;
            return 1;//dead
        }
        else //���������ڻ򽫣��ͼ�һ
            c_iff++;
    }
//    return 0;
//}
//int horse(int rx,int ry)
//{
	//�ж������Ƿ񽫾�
    for(int ix=1;ix>=-1;ix-=2)
        for(int iy=1;iy>=-1;iy-=2)//�����ж��ĸ���λ
            if(((rx+ix)<1||(rx+ix)>10||(ry+iy)<1||(ry+iy)>9)==0)//��Խ��
                if(board[rx+ix][ry+iy]=='0')//��������
                    if(board[rx+ix*2][ry+iy]=='H'||board[rx+ix][ry+iy*2]=='H')//�Ǹ�����λ��������
                        return 1;//��ɱ
    //cout<<"safe"<<endl;
    return 0;
}
int main()
{
    int T,rx,ry;
    int cx,cy;
    char chess;
    while(cin>>T>>rx>>ry&&!(!T||!rx||!ry))
    {
        memset(board,'0',sizeof(board));
        while(T--)//������
        {
            cin>>chess;
            cin>>cx>>cy;
            board[cx][cy] = chess;
        }

        int i;
        for(i=rx+1;rx<=10&&board[i][ry]=='0';i++);//�ж�һ��ʼ�Ƿ񽫶�˧���Ǿ�NO������˼·5
        if(board[i][ry]=='G'){cout<<"NO"<<endl;continue;}

        int dead_sum=0;//��¼����·�ߣ�Ϊ4���ǽ���
        //cout<<"rx "<<rx<<"  ry  "<<ry<<endl;
        dead_sum += checkmate(rx+1,ry);
        dead_sum += checkmate(rx-1,ry);
        dead_sum += checkmate(rx,ry+1);
        dead_sum += checkmate(rx,ry-1);
        //cout<<"dead_sum  "<<dead_sum<<endl;
        if(dead_sum==4)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
//AC at 2018/2/26
