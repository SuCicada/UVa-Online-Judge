#include<iostream>
#include<map>
#include<string>
#include<stack>
#include<vector>
using namespace std;

map<char, vector<int> > matrixs;

// void show(){
//     for(map<char, vector<int> >::iterator i=matrixs.begin();i!=matrixs.end();i++){
//         cout<<(*i).first<<" : "<<(*i).second[0]<<"  "<<(*i).second[1]<<endl;
//     }
// }

int main()
{
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        char a;
        int n,m;
        cin>>a>>n>>m;
        // int t[2]={n,m};
        matrixs[a] = vector<int>(2); //定义好vector大小,否则用push_back
        matrixs[a][0] = n;
        matrixs[a][1] = m;
    }
    // show();
    string formula;
    stack<char> flag;  // 括号
    stack<vector<int> >  chara; // 代表矩阵的行列
    while(cin>>formula){
        // cout<<"---0-------"<<endl;
        // cout<<formula<<endl;
        int sum = 0;
        int res_index = 0;
        int i;
        for(i=0;i<formula.size();i++){
            // cout<<i<<" : "<<formula[i]<<endl;
            if(formula[i] == '('){
                // flag.push(i);

            }else if(formula[i] == ')'){
                // int satrt = flag.top();
                // flag.pop();
                
                vector<int> a = chara.top();
                chara.pop();
                vector<int> b = chara.top();
                chara.pop();

                // cout<<b[0]<<" "<<b[1]<<endl;

                if(b[1] != a[0])  // 注意栈中取出的是反过来的,
                    break;
                // int re = mulit(b,a);  // 注意栈中取出的是反过来的,
                // if(re == -1) // error
                //     break;
                sum += b[0] * b[1] * a[1];
                vector<int> tt(2);
                tt[0] = b[0]; // 注意栈中取出的是反过来的
                tt[1] = a[1];
                // matrixs['*'] = tt;
                chara.push(tt);
            }else{
                chara.push(matrixs[formula[i]]);
            }
        }   
        if(i<formula.size())
            cout<<"error"<<endl;
        else{
            cout<<sum<<endl;
        }
    }
    return 0;
}

// AC at 2019/2/8 23:06
// about 1 or 2 hours ?