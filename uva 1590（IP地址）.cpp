/*
110000100101010110100000_10110001
110000100101010110100000_10110111
110000100101010110100000_10110010

11000010010101011010000010110000
11111111111111111111111111111000
*/
//���������ֻ����һ��IP��ַ����ʱ����Ӧ��32λ1
#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<cmath>
#include<cstdio>
using namespace std;
string binary(int dec)
{
    string str="00000000";
    stack<int> s;
    int bin=0;
    for(int i=7;i>=0;i--)
    {
        //s.push(dec%2);
        str[i]=dec%2+'0';
        dec /= 2;
    }
//    while(!s.empty())
//    {
//        bin = bin*10 + s.top();
//        s.pop();
//    }
//    return bin;
    return str;
}
int decimal(string bin)
{
    int dec =0;
    for(int i=0;i<8;i++) //�Ӹ�λ��ʼ
    {
        dec += (int)pow(2,8-i-1)* (bin[i]-'0');
    }
    return dec;
}
int main()
{
    int T;
    while(cin>>T)
    {
        vector<string>ip; //  �洢���������ip
        int num=0;
        if(T==1)  //��ֹֻ����һ����ַ���������
            num=32;
        while(T--)    //����
        {
            int a[4];
            string str;
            scanf("%d.%d.%d.%d",&a[0],&a[1],&a[2],&a[3]);
            for(int i=0;i<4;i++)
            {
                str += binary(a[i]);
            }
            ip.push_back(str);
        }
        for(int j=0;j<32;j++)    //�ж���ȵ�λ��
        {
            int iff=0;
            for(int i=1;i<ip.size();i++)
            {
                //cout<<ip.at(i)<<endl;
                if(ip.at(0)[j] == ip.at(i)[j])  //��һλ���
                {
                    iff=1;
                }
                else
                {
                    iff=0;
                    break;
                }
            }
            if(iff)         //��һλ��ȣ�����λ����һ
                num++;
            else
                break;
        }
        string zero="00000000"; //����0
        string mask,minip;
        int score[4];//�洢��С������ĸ�ʮ����ip��ַ��
        int score2[4];//�洢mask���ĸ�ʮ���Ƶ�ip��ַ��

        for(int i=1;i<=32-num;i++)  //�ȴ����ʼ��0
        {
            minip='0'+minip;
            mask='0'+mask;
        }
        for(int i=num-1;i>=0;i--)   //���Ĳ�
        {
            minip=ip[0].at(i)+minip;
            mask='1'+mask;
        }

//        cout<<num<<endl;
//        for(int i=0;i<ip.size();i++)
//            cout<<ip[i]<<endl;
//        cout<<endl;
//        cout<<mask<<endl;

        for(int i=0;i<4;i++)  //������С����
        {
            score[i] =decimal(minip.substr(i*8,8));
            score2[i] =decimal(mask.substr(i*8,8));
            //������̭�ķ����ǣ��߱任���߱ȶ��Ƿ�λ��������С����λ��
            //�Ƚ������������һ����С����Ķ����Ƶ�ַ,Ȼ����ֱ�ӱ任��Ҫ������
//            if(i*8+8>num)
//            {
//                //cout<<i*8<<" "<<num<<endl;
//                //cout<<ip[0].substr(i*8,num-i*8)<<"|"<<zero.substr(0,32-num)<<endl;
//                score[i]=decimal(ip[0].substr(i*8,num-i*8)+zero.substr(0,32-num));
//            }
//            else
//            {
//                //cout<<ip[0].substr(i*8,8)<<endl;
//                score[i]=decimal(ip[0].substr(i*8,8));
//            }
        }

        printf("%d.%d.%d.%d\n",score[0],score[1],score[2],score[3]);
        printf("%d.%d.%d.%d\n",score2[0],score2[1],score2[2],score2[3]);
    }
    return 0;
}
//AC at 2018/4/22
