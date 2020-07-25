#include<iostream>
#include<map>
#include<string>
#include<set>
#include<algorithm>
using namespace std;

string lower(string s){
    string re;
    for(int i=0;i<s.size();i++){
        re += s[i]>='a' && s[i]<='z' ? s[i] : s[i] - 'A' + 'a'; 
    }
    return re;
}

int main()
{
    map<string, string> dict;
    string word,temp;

    while(cin>>word && word != "#"){
        // cout<<word<<endl;
        temp = lower(word);
        // cout<<"lower "<<temp<<endl;
        sort(temp.begin(), temp.end());
        // cout<<"--"<<word<<endl;
        // cout<<"dict "<<dict[temp]<<endl;
        if(dict.count(temp) == 0){  //说明没有
            dict[temp] = word;
        }else{ //有了我们就不要了
            dict[temp] = "";
        }
    }
    
    set<string> res;
    map<string, string>::iterator i = dict.begin();
    for(;i!=dict.end();i++){
        if((*i).second != ""){
            // cout<<(*i).second<<endl;
            res.insert((*i).second);
        }
    }
    for(set<string>::iterator i = res.begin(); i != res.end(); i++){
        cout<<(*i)<<endl;
    }

    return 0;
}
// AC at 2019/1/30