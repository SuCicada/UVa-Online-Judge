/*
˼·��������ĳ�����ʽ���֣�ÿһ�εı��������� ��һ�������� �C ��һλ��*������������ֻҪ�ҵ������￪ʼ�ı�������֮ǰ��ĳһ��������һ������ô����һλ�㿪ʼѭ�����������������������ӣ�2/3

  0.6 6  //
3|2.0    //һ��ʼ������������
  1.8    //28 = 4���̣�* 7��������
    2 0  //20 = (30����������- 4���̣�* 7��������)*10
         //��ʼѭ��
         //ͬʱ���Ƿ��� ����ı�����20 �͵ڶ��еı�����20 һ����  
1
2
3
4
5
6
���������������дһ�³������㣬��Ŀ����붮��

*/
#include<iostream>
#include<cstring>
using namespace std;
int const N = 3000;
int divident[N+5];//������
int result[N+5];//����
int circle(int nd,int n1)
{
    for(int i=0;i<nd;i++)
    {
        if(n1==divident[i])//����ѭ��
        {
            return i;//���� ѭ�����ͷ��λ��,
        }
    }
    return -1;
}
int main()
{
    int a,b;
    while(cin>>a>>b)
    {
        int n1=a;//������
        int nc=-1;
        int nd=1,nr=0;//��Ϊresult��һλ������λ������Ϊ��������� nd=1
        memset(divident,0,sizeof(divident));
        memset(result,0,sizeof(result));
        do
        {
            result[nr++]=n1/b;//cout<<n1/b;
            //cout<<n1<<" n1  "<<result[nr-1]<<endl;
            //if(nc==1)
                //result//cout<<".";
            n1 = (n1-n1/b*b);
            n1*=10;
            divident[nd++]=n1;//��ÿһ�׶εı���������
            //cout<<n1<<" "<<result[nr-1]<<endl;
            if(n1==0)//��������
            {
                result[nr++]=0;
                nc=nd-1;
                nd++;
                break;
            }
         }while((nc=circle(nd-1,n1))==-1);//&&nr<=50);//nc---(nd-1)ѭ��
//         if(nr>50)
//            nc=1;
         //cout<<nc<<"  "<<result[nc]<<"  "<<nd-1<<"  "<<divident[nd-1]<<endl;
        cout<<a<<"/"<<b<<" = ";
        cout<<result[0]<<".";
        for(int i=1;i<nc;i++)
            cout<<result[i];
        cout<<"(";
        for(int i=nc;i<nd-1&&i<=50;i++)
            cout<<result[i];
        if(nr>50)
            cout<<"...";
        cout<<")"<<endl;
       // cout<<nd<<"  "<<nc<<endl;
        cout<<"   "<<nd-nc-1//(nr<=50?nd-nc-1:99)Ҫ��������
            <<" = number of digits in repeating cycle"<<endl<<endl;
    }
    return 0;
}
//AC at 2017/12/30
/*
    42
7|3.0
  2 8   //n1/b*b
    20 //n1-n1/b*b , n1*=10
    14
     60


4|1.0
    80
    80
     0
*/

