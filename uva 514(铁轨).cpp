#include<iostream>
#include<stack>
using namespace std;

// void show(stack<int> a){
//     while(!a.empty()){
//         cout<<a.top()<<" ";
//         a.pop();
//     }
//     cout<<endl;
// }

// [注意] 最后一组输出之后要有一个空行


int fun(int N){
    stack<int> wait;  // 等待通过的火车
    stack<int> temp;  // 中转轨道
    for(int i=N;i>=1;i--){
        wait.push(i);
    }
    
    int train;
    int no = 0; // 不能吗
    for(int i=1;i<=N;i++){
        cin>>train;
        if(train == 0)
            return 0; // 该退出了
        if(no == 1)
            continue;
    // cout<<train<<" ??????????????"<<endl;
    // cout<<"wait: "; show(wait);cout<<"temp: "; show(temp);cout<<"---------------"<<endl;
        while(temp.empty() || temp.top() != train){

            if(wait.empty()){
                no = 1; // wait空了,中转的第一个却不能走,所以不行
                break;
            }

            int out = wait.top(); // 车厢出等待区
            wait.pop();

            temp.push(out);  // 车厢 进入中转区
        }
        if(temp.top() == train)
            temp.pop();  // 中转的车走了
    }
    if(temp.empty() && wait.empty()){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 1;
}

int main()
{
    int N;
    int index = 0;
    while(cin>>N && N != 0){
        // if(index != 0)
        index = 1;
        while(fun(N)!=0);
        cout<<endl;
    }
    return 0;
}

// AC at 2019/2/8 13:41
// spend about 1 hours