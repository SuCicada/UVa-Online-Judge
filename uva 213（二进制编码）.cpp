/*
1、先接收字符串，因为有空格，所以我用了getline，因为我用string
2、然后我们将输入的字符串存入code这个二维数组里，code[i][j]中i代表二进制码的位数，j代表当前01码的十进制数。以此我们每次循环的j小于2^i-i即可。
3、然后我们用循环，先将三位的二进制数传入bin_dec()函数，来得出接下来代表一个字符的二进制码的位数。
4、contra()函数是用来进行每一组相同码长的字符的输出。
（1）其思路是用一个变量记录当前bcode（01码字符串）读到哪个位了。
（2）然后循环将之后的len位二进制变成一个整数，传入bin_dec()函数得出其代表的十进制数，而这个十进制数也是code数组的第二维的下标。
5、还有一点，因为二进制码在输入的过程中并不一定是在同一行,所以我用了：当前下标+要接受的码长 和 当前的01码字符串长度来进行比较，若大则接收新的一行字符串，再加到原先01码字符串后面。（！注意这里用的是while循环而不是单一次的if判断，是因为可能接收一次字串后也依然不够码长，所以要一直接收到足够长为止。）*/

#include<iostream>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;
char code[7][1<<7];//长度，值，来存字符

int bin_dec(int b)//二进制转十进制
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
int dec_bin(int dec)//十进制转二进制
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

string s;//字符串
string bcode;//01码
//此函数用于输出当前码长为len的一组01码所代表的的字符
void contra(int &n,int len)//下一元素的下标，码长
{
    //cout<<n<<"  "<<len<<endl;
    int dec;
    while(1)
    //do
    {
        int bin=0;
        while(n+len>=bcode.size())//用于接收断裂处之后的01码
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
        memset(code,0,sizeof(code));//清空数组
        //s="$#**\\";
        //bcode="0100000101101100011100101000";
        int si=0;
        for(int i=0;i<7&&si<s.size();i++)//存表
        {
            for(int j=0;j<(1<<(i+1))-1&&si<s.size();j++)
            {
                code[i][j]=s[si++];
                //cout<<i<<"  "<<j<<" "<<code[i][j]<<endl;
            }
        }

        //cout<<bcode.size()<<endl;
        int n=0;//下一个元素下标
        //for(int n=0;n<bcode.size();)
        while(1)
        {
            while(n+3>bcode.size())//用于接收断裂处之后的01码
            {
                //cout<<n+3<<"__"<<bcode.size()<<endl;
                string temp;
                cin>>temp;
                bcode += temp;
            }

            //cout<<"n  "<<n<<"  "<<bcode[n]<<endl;
            int s1=bcode[n]*100+bcode[n+1]*10+bcode[n+2]-111*'0';//三位01码
            if(s1==0) break;
            n+=3;
            //cout<<"---------"<<s1<<endl;
            s1=bin_dec(s1);//判断前三位 分析出码长
            contra(n,s1);
        }
        //cout<<"!!!!!end"<<endl<<endl;
        cout<<endl;
        cin.get();
    }
    return 0;
}
//AC at 2018/2/11









