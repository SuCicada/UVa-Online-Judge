//uva 509 RAID���������ݣ�
#include<iostream>
#include<string>
using namespace std;
/*
1 0 1
1 1 0
0 0 0
0 1 1
*/
//�и��� bca
int a,b,c; //���ݿ飨���У������̣�һ�м������У�,һ��λ���ݼ�λ

//һ����ʾ��ά��ĺ���������������Ҳ����
void show(char ***disk)
{
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            for(int k=0;k<c;k++)
                cout<<disk[i][j][k];
            cout<<"_";
        }
        cout<<endl;
    }
    cout<<endl;
}

int repair(char ***disk,int od_ev)//od_evֱ�Ӵ���0��1
{
    //Ӧ����ѭ��a����ѭ��c����ѭ��b
    //�ҵ�һλȻ�� ѭ��һ�������е����λ
    //cout<<a<<"  "<<b<<"  "<<c<<endl;
    for(int i=0;i<a;i++)
    {
        for(int k=0;k<c;k++)
        {
            int yihuo=0;
            int x_num=-1;
            for(int j=0;j<b;j++)
            {
//        cout<<i<<" "<<j<<"  "<<k<<endl;
//        show(disk);
                if(disk[i][j][k]=='x')
                {
                    if(x_num!=-1)
                        return 0;//disk invalid
                    x_num=j;
                }
                else
                    yihuo=yihuo^(disk[i][j][k]-'0');
            }
            if(x_num!=-1)
                disk[i][x_num][k] = yihuo^od_ev+'0';
            else if(yihuo!=od_ev)
                return -1;   //���ݴ���
        }
    }
    return 1;
}

char hex(string bin)//char b1,char b2,char b3,char b4)
{
    //cout<<bin<<"----"<<endl;
    int n=(bin.at(0)-'0')*2*2*2+ (bin.at(1)-'0')*2*2 + (bin[2]-'0')*2+ (bin[3]-'0');
    if(n<10) return (n+'0');
    switch(n)
    {
        case 10:return 'A';
        case 11:return 'B';
        case 12:return 'C';
        case 13:return 'D';
        case 14:return 'E';
        case 15:return 'F';
    }
//    �����Ǳ�����233
//    string h="0000";
//    h[0]=b1;
//    h[1]=b2;
//    h[2]=b3;
//    h[3]=b4;
//    if(h=="0000") return "0";
//    if(h=="0001") return "1";
//    if(h=="0010") return "2";
//    if(h=="0011") return "3";
//    if(h=="0100") return "4";
//    if(h=="0101") return "5";
//    if(h=="0110") return "6";
//    if(h=="0111") return "7";
//    if(h=="1000") return "8";
//    if(h=="1001") return "9";
//    if(h=="1010") return "A";
//    if(h=="1011") return "B";
//    if(h=="1100") return "C";
//    if(h=="1101") return "D";
//    if(h=="1110") return "E";
//    if(h=="1111") return "F";

}
int main()
{
    int NUM =0;
    while(cin>>b>>c>>a&&b!=0)  //ע�������˳��
    {
        char ***disk;
        char od_ev;
        cin>>od_ev;

        disk = new char**[a]; //diskָ�����a��char**�͵Ŀռ�
        //char **disk[a]
        for(int i=0;i<a;i++)
            disk[i] = new char*[b];   //disk���ÿ��Ԫ��ָ�����b��char*�Ϳռ�
            //char *disk[i][b]
        for(int i=0;i<a;i++)
            for(int j=0;j<b;j++)
                disk[i][j] = new char[c];

            for(int j=0;j<b;j++)
        for(int i=0;i<a;i++)
                for(int k=0;k<c;k++)
                    cin>>disk[i][j][k];

        NUM++;
        cout<<"Disk set "<<NUM<<" is ";

        int retu = repair(disk,od_ev=='E'?0:1);
        if(retu!=1)
        {
            cout<<"invalid."<<endl;
            continue;   //������һ�δ�ѭ��
        }
        //cout<<retu<<endl;

        //show(disk);


        string result;
        string bin;     //Ҫתʮ�����Ƶ���λ������
        int num=0;      //�����4,������λ������
        int sum=a*b*c-a*c;  //һ��Ҫ�����ַ�������ȥУ��λ
        for(int i=0;i<a;i++)
            for(int j=0;j<b;j++)
            {
                if((i+1)%b==(j+1)%b)  //У����
                {
                    //sum-=c;  //���������c��ҲҪ��¼
                    continue;
                }
                for(int k=0;k<c;k++)
                {
//                    cout<<"disk"<<i<<" "<<j<<" "<<k<<" "<<(disk[i][j][k])<<endl;;
                    bin.append(1,disk[i][j][k]);   //�����1�������1�����ڵڶ���Ԫ�ص��ַ�������û����á�
                    num++;
//                    cout<<bin<<"__"<<sum<<" "<<num<<endl;
                    if(num%4==0)
                    {
                        result.append(1,hex(bin));
                        bin.erase();
                    }
                    else if(sum%4!=0&&sum==num)
                        result.append(1,hex(bin+"0000"));
                }
            }

        cout<<"valid, contents are: ";
        cout<<result<<endl;

    }//while

    return 0;
}
//AC at 2018/4/25
