//�Ժ�����д˳�������ң����ϵ������α߱������������
//��������ĸ�����@���棬֮���Բ���*������Ϊ��ͳ����ʼ��ĸ�����
//������Ϊ˵�����еķ�Χ������ֱ����char�͵Ķ�ά���鼴�ɡ�
//����ûע����Ϊ���������е����飬�������˶�̬�ڴ�������ɶ�ά���顣���������������ˣ�
//����ע����ڴ�����ע���ˡ�
#include<iostream>
#include<iomanip>
using namespace std;

int hang,lie;
//��������ʾ����
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
    int i,j,pi,pj,*pij;//pϵ����Ϊ��ӡһ���ַ���
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
            if(puzz[i][j]=='*')//��*������ʼ��Ͳ�����
                continue;
            bool iff=false;
            if(j==0||i==0)//����ʼ��
            {
                iff=true;
                qsg++;
            }
            else if(puzz[i][j-1]=='*'||puzz[i-1][j]=='*')//Ϊ�˷�ֹj-1��i-1С��0�����
            {
                iff=true;
                qsg++;
            }
            if(iff)
            {
                if(puzz[i][j]=='@')//��Ȼ��Ԫ��Ҳ����ʼ�񣬵�����Ϊ�Ѿ����߹��ˣ����Բ������䵷��
                        continue;//����break
                cout<<endl//��ʼһ��Ż��У���ֹ�������
                    <<setw(3)//ע����3����Ҷ���
                    <<qsg<<".";
                pi=i;
                pj=j;
                while(puzz[pi][pj]!='*')//���across���ַ�
                {
                    cout<<puzz[pi][pj];
                    puzz[pi][pj]='@';
                    (*pij)++;
                    if(!(pj<lie&&pi<hang))//һ���±�Խ�磬�ͻ����
                        break;
//                    if(AD=='A')
//                        j++;
//                    if(AD=='D')
//                        i++;
                }
            }
            //if(pj<lie&&pi<hang)//���и��õİ취��//yes
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
        puzz=creat();//�����ָ�봫����
        for(int i=0;i<hang;i++)//ԭʼ�Թ�
            for(int j=0;j<lie;j++)
            {
                //puzz[i][j]='o';
                cin>>puzz[i][j];
            }
        //dis(puzz);
        char **puzz2;
        puzz2=creat();
        for(int i=0;i<hang;i++)//��¡���Թ�
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
