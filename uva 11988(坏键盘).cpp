#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
// #include<algorithm>
using namespace std;

const int MAX = 100000;
int nextt[MAX+5];

int main()
{
    string str;
    while(cin>>str){
        memset(nextt,0,sizeof(nextt));
        // nexxtt[]
        int cur = 0;
        int last = 0;
        str = " "+str;
        for(int i=1;i<str.size();i++){
        // cout<<"word: "<<str[i]<<endl;
            if(str[i]=='['){
                cur = 0;
            }else if(str[i]==']'){
                cur = last;
                // last = i;
            }else{
                int temp = nextt[cur];
                last = temp==0?i:last;
                nextt[cur] = i; // 光标的下一个就是现在     
                nextt[i] = temp;
                cur = i; // 移动光标到现在这里
            }
        //     cout<<"last: "<<last<<"   cur: "<<cur<<endl;
        // for(int i=0;i<str.size();i++)cout<<nextt[i]<<" ";cout<<endl;
        }
        for(int i=nextt[0];i!=0;i = nextt[i])cout<<str[i];cout<<endl;
    }
    return 0;
}

//AC at 2019/2/11 18:06

// ===============[ mine array ]=============================
char chs[MAX+5];
int main2()
{
    string str;
    while(cin>>str){
        memset(chs,0,sizeof(chs));
        memset(nextt,0,sizeof(nextt));
        // int home = 0,end = 0;
        int first = 1;  // 第一个字母的下标
        int last = 1;   // 最后一个字母的下标
        // int now = 1;    // 现在字母的下标
        int pre = 0;    // 前一个
        int _new = 0;
        // next[first] = last; // 初始就是最后一个的下一个
        chs[0] = '|';
        for(int i=0;i<str.size();i++){
            // cout<<"word: "<<str[i]<<endl;
        // for(int i=0;i<str.size();i++)cout<<str[next[i]-1]<<" ";cout<<endl;
            if(str[i]=='['){
                // home = 1;
                // end = 0;
                // now = first;
                // first = i;
                // next[i] = first;
                // i++;
                // now = first-1;
            }else if(str[i]==']'){
                // home = 0;
                // end = 1;
                // last = i;
                // now = last;
                pre = last;
            }else{
                // int new = now+1;
                int temp = nextt[pre];  // 将的下一个记录
                // next[now] = new;
                // next[new] = temp;
                _new = _new+1;
                if(i>0&&str[i-1]=='['){
                    nextt[_new] = _new==1?0:first;
                    first = _new;

                }else if(i>0&&str[i-1]==']'){
                    // now = _new;
                    nextt[pre] = _new;
                    nextt[_new] = temp;
                    last = _new;
                }
                else{
                    if(temp==0)
                        last = _new;
                    nextt[pre] = _new;
                    nextt[_new] = temp;
                }
                pre = _new;
                // now = now+1;
                // next[now] = now + 1;
                chs[_new] = str[i];
                // last ++;
            }
        // cout<<"first: "<<first<<"  last: "<<last<<"  now: "<<now<<endl;
        //     for(int j=0;j<str.size()+1;j++) cout<< (chs[j]?chs[j]:'-') <<" ";cout<<endl;
        //     for(int j=0;j<str.size()+1;j++) cout<<nextt[j]<<" ";cout<<endl;
        }

        // for(int i=0;i<str.size();i++)printf("%d ",chs[i]);cout<<endl;
        for(int ii=first;ii!=0;){
            cout<<chs[ii];
            // printf("%d ",chs[ii]);
            ii = nextt[ii];
        }
        cout<<endl;
    }
    return 0;
}

// AC at 2019/2/11 12:41


// ======================[ list ]=====================================
#include<iostream>
#include<string>
#include<list>
using namespace std;

int main1()
{
    string str;
    while(cin>>str){
        list<char> text;
        int now = 0;
        list<char>::iterator inow=text.begin();
        // cout<< (text.begin()==text.end()) <<endl;
        for(int i=0;i<str.size();i++){
            if(str[i]=='['){
                // now = 0;
                inow = text.begin();
            }else if(str[i]==']'){
                // now = text.size();
                inow = text.end();
            }else{
                // list<char>::iterator a=text.begin();
                // for(int i=0;i<now;i++)
                //     a++;
                text.insert(inow, str[i]);
//                 cout<<"new: "<< *text.insert(inow, str[i])<<endl;
//                 cout<<"dis: "<< distance(text.begin(), inow)<<endl;
//                 // inow++;
//                 cout<<"dis: "<< distance(text.begin(), inow)<<endl;

//                 cout<< (inow==text.end()) <<endl;
// for(list<char>::iterator i=text.begin();i!=text.end();i++)cout<<(*i);cout<<endl;
            }

        }
        for(list<char>::iterator i=text.begin();i!=text.end();i++)
            cout<<(*i);
        cout<<endl;
    }
    return 0;
}

// AC at 2019/2/11 00:55