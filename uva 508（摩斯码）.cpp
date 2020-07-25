//��ƥ�䵽���У�Ӧѡ���ַ����ٵĴ���
//���磺A . B - C.-  ��ô.-xx��Ӧ����C
#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

char word[50];           //����ʵ�ַ�
vector<string> morse;    //���ַ���Ħ˹��
vector<string> dict;     //�������ֵ�
vector<string> puzzle;   //���ֵ��Ӧ��Ħ˹��
vector<string> question; //��Ҫ���Ħ˹��

string zip(string str)   //������ܳ�Ħ˹��
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

string solove(string mos)  //��Ħ˹����Ϊ����
{
    int jingzhun_n=-1,jingzhun=0;  //��׼ƥ����±꣬����
    int mohu_n=-1,mohu=0,mohu_len=999; //ģ��ƥ����±꣬������ģ���ַ�����
    int yes;//ƥ��λ��
    int length=mos.size();
    int puzz_len; //�����еĴ���ĳ���

    for(int i=0;i<puzzle.size();i++)   //�������еĴ���
    {
        puzz_len=puzzle[i].size();
        yes =0;   //ƥ����ַ�����
        //cout<<length<<"   "<<puzz_len<<endl;
        for(int j=0;j<puzz_len&&j<length;j++)  //����ÿ������Ħ˹���ÿһλ
        {
            if(mos[j]==puzzle[i].at(j))
            {
                yes++;
                //cout<<yes<<"||||"<<endl;
            }
            else
                break;
        }//for(j
        if(yes==puzz_len&&length==puzz_len) //��׼ƥ��
        {
            if(jingzhun<1)
                jingzhun_n=i;
            jingzhun++;
        }
        else if(yes==puzz_len&&length>yes|| //ģ��ƥ�䣬mose��
                yes<puzz_len&&yes==length)  //��ǰ���鳤
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
    //�����ַ��Ͷ�Ӧ��Ħ˹��
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

    //���������ֵ�
    string temp;
    while(cin>>temp&&temp!="*")
    {
        dict.push_back(temp);
    }
    sort(dict.begin(),dict.end());

    //����Ҫ���ܵ�Ħ˹��
    while(cin>>temp&&temp!="*")
    {
        question.push_back(temp);
    }

    //�������

    //������ܺ���ֵ��еĴ���
    for(int i=0;i<dict.size();i++)
    {
        string temp2 =zip(dict[i]);
        puzzle.push_back(temp2);
    }


    //��ʼ����
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
