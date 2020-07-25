//在匹配到的中，应选择字符最少的词组
//比如：A . B - C.-  那么.-xx就应该是C
#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

char word[50];           //存真实字符
vector<string> morse;    //存字符的摩斯码
vector<string> dict;     //存词组的字典
vector<string> puzzle;   //存字典对应的摩斯码
vector<string> question; //存要解的摩斯码

string zip(string str)   //词组加密成摩斯码
{
    string ans;
    for(int i=0;i<str.size();i++)
    {
        for(int j=0;j<26+10;j++)
        {
            if(str[i]==word[j])
            {
                ans = ans +morse[j];
                break;
            }
        }
    }
    return ans;
}

string solove(string mos)  //从摩斯解密为词组
{
    int jingzhun_n=-1,jingzhun=0;  //精准匹配的下标，个数
    int mohu_n=-1,mohu=0,mohu_len=999; //模糊匹配的下标，个数，模糊字符长度
    int yes;//匹配位数
    int length=mos.size();
    int puzz_len; //遍历中的词组的长度

    for(int i=0;i<puzzle.size();i++)   //遍历所有的词语
    {
        puzz_len=puzzle[i].size();
        yes =0;   //匹配的字符数量
        //cout<<length<<"   "<<puzz_len<<endl;
        for(int j=0;j<puzz_len&&j<length;j++)  //遍历每个词语摩斯码的每一位
        {
            if(mos[j]==puzzle[i].at(j))
            {
                yes++;
                //cout<<yes<<"||||"<<endl;
            }
            else
                break;
        }//for(j
        if(yes==puzz_len&&length==puzz_len) //精准匹配
        {
            if(jingzhun<1)
                jingzhun_n=i;
            jingzhun++;
        }
        else if(yes==puzz_len&&length>yes|| //模糊匹配，mose长
                yes<puzz_len&&yes==length)  //当前词组长
        {
            if(mohu_len>abs(puzz_len-length))
            {
                mohu_len= abs(puzz_len-length);
//    cout<<"\||||"<<endl<<mohu<<"  "<<dict[mohu_n]<<endl<<endl;
                    mohu_n= i;
                mohu++;
            }
        }
    }//for(i

    if(jingzhun>0)
    {
        if(jingzhun>1)
            return dict[jingzhun_n]+"!";
        return dict[jingzhun_n];
    }
    else if(mohu>0)
    {
        return dict[mohu_n]+"?";
    }
    else
        return dict[0];
}
int main()
{
    //输入字符和对应的摩斯码
    for(int i=0;;i++)
    {
        string temp;
        char c;
        cin>>c;
        if(c=='*')
            break;
        word[i]=c;
        cin>>temp;
        morse.push_back(temp);
    }

    //输入词组的字典
    string temp;
    while(cin>>temp&&temp!="*")
    {
        dict.push_back(temp);
    }
    sort(dict.begin(),dict.end());

    //输入要解密的摩斯码
    while(cin>>temp&&temp!="*")
    {
        question.push_back(temp);
    }

    //输入结束

    //计算加密后的字典中的词组
    for(int i=0;i<dict.size();i++)
    {
        string temp2 =zip(dict[i]);
        puzzle.push_back(temp2);
    }


    //开始解密
    for(int i=0;i<question.size();i++)
    {
        //cout<<question[i]<<"????"<<endl;
        cout<<solove(question[i])<<endl;
    }


//    cout<<dict.size()<<"   "<<puzzle.size()<<endl;
//    for(int i=0;i<puzzle.size();i++)
//    {
//        cout<<dict[i]<<"   ";
//        cout<<puzzle[i]<<endl;
//    }
    return 0;
}
//AC at 2018/4/23

/*
AN           .--.
EARTHQUAKE   ..-.-.-....--.-..-.--.-.
EAT          ..--
GOD          --.----..
HATH         .....--....
IM           ..--
READY        .-...--..-.--
TO           ----
WHAT         .--.....--
WROTH        .--.-.----....
*/
