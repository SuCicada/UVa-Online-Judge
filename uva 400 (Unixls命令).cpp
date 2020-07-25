#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

/*
[注意] 一行最后一个单词后面不要有两个空格
[注意] 每组最后一个单词后面不用空2格
算行数时向上取整
输出时,设置额外的break条件,即已经输出完最后一个,不要继续越界输出

*/

int main()
{
    int N;
    while(cin>>N){
        vector<string> list;
        int max_len = 0;
        for(int i=0;i<N;i++){
            string str;
            cin>>str;
            max_len = max_len < str.size() ? str.size() : max_len;
            list.push_back(str);
        }



        sort(list.begin(), list.end());
        int count_col = 0;  // 列数
        int count_line = 0; //行数
        count_col = (60+2) / (max_len+2);
        count_line = ceil((double)list.size() / count_col); //[注意]这里除的时候要转换为浮点型
        // cout<<list.size()<<" "<<(double)list.size() / count_col + 0.5<<endl;
        // cout<<max_len<<" "<<count_col<<" "<<count_line<<endl;

        for(int i=0;i<60;i++)
            cout<<"-";  
        cout<<endl;
        for(int i=0;i<count_line;i++){     // 第几行
            for(int k=0; k<count_col && (i+k*count_line)<list.size(); k++){  // 第几列, 循环判断条件中,加上判输出单词个数足够
                if(k>0)  //作为两个词块之间间隔的空格,每行第一个之前没有
                    cout<<"  ";

                string out = list[i+k*count_line];
                cout<<out;

                //输出每个单词后面的占位空格 (不算单词块之间2个空格的间隔)
                for(int j=0;j<max_len-out.size();j++) 
                    cout<<" ";
            }
            cout<<endl;
        }

    }
    return 0;
}

// AC at 2019/2/2 00:22