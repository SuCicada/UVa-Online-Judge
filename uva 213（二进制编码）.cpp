/*
1���Ƚ����ַ�������Ϊ�пո�����������getline����Ϊ����string
2��Ȼ�����ǽ�������ַ�������code�����ά�����code[i][j]��i������������λ����j����ǰ01���ʮ���������Դ�����ÿ��ѭ����jС��2^i-i���ɡ�
3��Ȼ��������ѭ�����Ƚ���λ�Ķ�����������bin_dec()���������ó�����������һ���ַ��Ķ��������λ����
4��contra()��������������ÿһ����ͬ�볤���ַ��������
��1����˼·����һ��������¼��ǰbcode��01���ַ����������ĸ�λ�ˡ�
��2��Ȼ��ѭ����֮���lenλ�����Ʊ��һ������������bin_dec()�����ó�������ʮ�������������ʮ������Ҳ��code����ĵڶ�ά���±ꡣ
5������һ�㣬��Ϊ��������������Ĺ����в���һ������ͬһ��,���������ˣ���ǰ�±�+Ҫ���ܵ��볤 �� ��ǰ��01���ַ������������бȽϣ�����������µ�һ���ַ������ټӵ�ԭ��01���ַ������档����ע�������õ���whileѭ�������ǵ�һ�ε�if�жϣ�����Ϊ���ܽ���һ���ִ���Ҳ��Ȼ�����볤������Ҫһֱ���յ��㹻��Ϊֹ����*/

#include<iostream>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;
char code[7][1<<7];//���ȣ�ֵ�������ַ�

int bin_dec(int b)//������תʮ����
{
    int dec=0;
    for(int i=0;b!=0;i++)
    {
        dec += ((b%10)<<i);
        //cout<<((b%10)<<i)<<endl;
        b/=10;
    }
    //cout<<dec<<endl;
    return dec;
}
int dec_bin(int dec)//ʮ����ת������
{
    int b=0;
    //dec =17;
    for(int i=0;dec!=0;i++)
    {
        //cout<<b<<" + "<<(dec%2)*(int)pow(10,i)<<"  "<<b+(dec%2)*(int)pow(10,i)<<endl;
        b += (dec%2)*(int)(pow(10,i)+0.1);
        //cout<<b<<endl;
        dec=dec>>1;
    }
    return b;
}

string s;//�ַ���
string bcode;//01��
//�˺������������ǰ�볤Ϊlen��һ��01��������ĵ��ַ�
void contra(int &n,int len)//��һԪ�ص��±꣬�볤
{
    //cout<<n<<"  "<<len<<endl;
    int dec;
    while(1)
    //do
    {
        int bin=0;
        while(n+len>=bcode.size())//���ڽ��ն��Ѵ�֮���01��
        {
            //cout<<"??"<<s.size()<<endl;
            string temp;
            cin>>temp;
            bcode += temp;
        }
        for(int i=0;i<len;i++)
        {
        //    cout<<bcode[n]<<"  ccccc"<<endl;
            bin+=(bcode[n++]-'0')*(int)(pow(10,len-i-1)+0.1);//+bcode[n+1]-'0'*11;
        //cout<<"bin  "<<bin<<endl;
        }
        dec=bin_dec(bin);
        if(dec==(1<<len)-1) break;
//        n+=len;
        cout<<code[len-1][dec];
        //cout<<"   _+_+_+_+_+_+"<<endl;
        //cout<<" --- "<<len-1<<"  dec "<<dec<<endl;
    }
}
int main()
{
    //cout<<bin_dec(1111111)<<endl;
    //cout<<dec_bin(63)<<endl;
    while(getline(cin,s)&&cin>>bcode)
    {
        //getline(cin,s);//&&cin>>bcode
        //cin>>bcode;
        memset(code,0,sizeof(code));//�������
        //s="$#**\\";
        //bcode="0100000101101100011100101000";
        int si=0;
        for(int i=0;i<7&&si<s.size();i++)//���
        {
            for(int j=0;j<(1<<(i+1))-1&&si<s.size();j++)
            {
                code[i][j]=s[si++];
                //cout<<i<<"  "<<j<<" "<<code[i][j]<<endl;
            }
        }

        //cout<<bcode.size()<<endl;
        int n=0;//��һ��Ԫ���±�
        //for(int n=0;n<bcode.size();)
        while(1)
        {
            while(n+3>bcode.size())//���ڽ��ն��Ѵ�֮���01��
            {
                //cout<<n+3<<"__"<<bcode.size()<<endl;
                string temp;
                cin>>temp;
                bcode += temp;
            }

            //cout<<"n  "<<n<<"  "<<bcode[n]<<endl;
            int s1=bcode[n]*100+bcode[n+1]*10+bcode[n+2]-111*'0';//��λ01��
            if(s1==0) break;
            n+=3;
            //cout<<"---------"<<s1<<endl;
            s1=bin_dec(s1);//�ж�ǰ��λ �������볤
            contra(n,s1);
        }
        //cout<<"!!!!!end"<<endl<<endl;
        cout<<endl;
        cin.get();
    }
    return 0;
}
//AC at 2018/2/11









