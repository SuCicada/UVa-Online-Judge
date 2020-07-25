//uva 509 RAID（磁盘数据）
#include<iostream>
#include<string>
using namespace std;
/*
1 0 1
1 1 0
0 0 0
0 1 1
*/
//列个行 bca
int a,b,c; //数据块（几行），磁盘（一行几个，列）,一单位数据几位

//一个显示三维表的函数，辅助，不用也可以
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

int repair(char ***disk,int od_ev)//od_ev直接传来0或1
{
    //应该先循环a，再循环c，后循环b
    //找到一位然后 循环一行中所有的这个位
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
                return -1;   //数据错误
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
//    以下是暴力解233
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
    while(cin>>b>>c>>a&&b!=0)  //注意输入的顺序
    {
        char ***disk;
        char od_ev;
        cin>>od_ev;

        disk = new char**[a]; //disk指向存着a个char**型的空间
        //char **disk[a]
        for(int i=0;i<a;i++)
            disk[i] = new char*[b];   //disk里的每个元素指向存着b个char*型空间
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
            continue;   //进行下一次大循环
        }
        //cout<<retu<<endl;

        //show(disk);


        string result;
        string bin;     //要转十六进制的四位二进制
        int num=0;      //间隔是4,代表四位二进制
        int sum=a*b*c-a*c;  //一共要过的字符量，除去校验位
        for(int i=0;i<a;i++)
            for(int j=0;j<b;j++)
            {
                if((i+1)%b==(j+1)%b)  //校验码
                {
                    //sum-=c;  //将查过的这c个也要记录
                    continue;
                }
                for(int k=0;k<c;k++)
                {
//                    cout<<"disk"<<i<<" "<<j<<" "<<k<<" "<<(disk[i][j][k])<<endl;;
                    bin.append(1,disk[i][j][k]);   //这里的1代表加入1个处于第二个元素的字符，这里没处理好。
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
