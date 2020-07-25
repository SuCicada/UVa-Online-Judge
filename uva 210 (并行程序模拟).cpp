#include<iostream>
#include<vector>
#include<string>
#include<deque>
#include<map>
#include<cstdio>
using namespace std;


// 当前程序执行完,配额时间有剩余: 让下一个程序继续用
// 当配额时间用完,当前程序一句代码没执行完: 继续执行到完
// 多组输入
// 每组输出之间空一行
// 所有变量初值为0
// 最后一组的输出之后不要有空行

map<char, int> vars;
vector<deque<string> > group;
deque<int> stop;
deque<int> wait;

void show(){
    cout<<"--------------"<<endl;
    for(int i=0;i<group.size();i++){
    cout<<endl<<i<<endl;
        for(int j=0;j<group[i].size();j++){
            cout<<group[i][j]<<endl;
        }
    }


    
}
void status(){
    for(int i=0;i<stop.size();i++){
        cout<<stop[i]<<" ";
    }
    cout<<endl;


    for(int i=0;i<wait.size();i++){
        cout<<wait[i]<<" ";
    }
    cout<<endl;

    cout<<"--------------"<<endl;
    for(map<char, int>::iterator i = vars.begin();i!=vars.end();i++){
        cout<< (*i).first <<" = "<< (*i).second <<endl;
    }
}

void fun(){
    int N,t1,t2,t3,t4,t5,Q;
    cin>>N>>t1>>t2>>t3>>t4>>t5>>Q;
    cin.get(); // [注意] 接收空格
    group = vector<deque<string> >(N);
    for(int i=0;i<N;i++){
        string str;
        // getline(cin, str);
        while(str != "end"){
            getline(cin, str);
            group[i].push_back(str); 
        }
        wait.push_back(i);
    }

    // show();
    int index = 0; //当前第几个程序
    int count_live = N;
    int lock = 0;  // 作为临界资源的记录型信号量,代表阻塞程序个数
    int part_time = 0; // 单位剩余时间
    // int pluse_time = 0; // 上一局剩下的时间
    while(count_live){
        // cout<<count_live<<endl;
        // if(group[index].empty()){
        //     // index = (index+1)%N;
        //     continue;
        // }

        // cout<<"?????????????<   "<<endl;
        // status();
        // cout<<"lock :"<<lock<<endl;
        // cout<<"^^^^^^^^^^^^^   "<<endl;

        int end_flag = 0; // 0:程序没结束, 1:程序end结束 -1:程序阻塞
        index = wait[0]; // 读取等待队列首
        wait.pop_front();

        // part_time = part_time <= 0? Q: part_time;
        part_time = Q;
        while(part_time>0){  // 一个单位时间剩余的时间
            string code = group[index][0]; // 读取程序队列首代码
            // group[index].pop_front();   // lock时可能不成功,所以不能放这里
            // index = (index+1)%N;

            string judge = code.substr(0,2);
            // cout<<index<<" : code "<<code<<endl;
            if(judge == "pr"){ // print 
                cout<<index+1<<": "<< vars[code[6]]<<endl;
                // cout<<"========================================"<<endl;
                part_time -= t2;

            }else if(judge == "lo"){ // lock
                // cout<<"lock"<<endl;
                if(lock){  // 要阻塞,语句不执行,不记时
                    stop.push_back(index);
                    end_flag = -1;
                    part_time = 0; // 此次时间片废了
                    break; // 进入阻止队列,就不用进入等待队列了, 而且lock代码还需要执行
                }else{    // 正常执行
                    lock++;
                    part_time -= t3;
                }

            }else if(judge == "un"){ // unlock
                // cout<<"unlock"<<endl;
                int pro = stop[0];
                if(!stop.empty()){ // 若是最后一个解锁的,那么阻塞队列就是空
                    stop.pop_front();
                    wait.push_front(pro);
                }
                lock--;
                part_time -= t4;

            }else if(judge == "en"){ // end
                // cout<<"end"<<endl;
                count_live --;
                // continue;  // 跳过插入deque
                part_time -= t5;
                // pluse_time = part_time - part_time;
                // group[index].pop_front();  // 执行成功,代码出队列
                end_flag = 1;
                break;  // 结束本程序,时间片给下一个

            }else{  // var
                int n;
                sscanf(code.substr(4).c_str(), "%d",&n);
                vars[judge[0]] = n;
                part_time -= t1;
            }

            group[index].pop_front();  // 执行成功,代码出队列
            // show();
        }
        if(end_flag == 0)
            wait.push_back(index);  // 时间片完,只要程序没有end, 就会入wait队列
        // else if(end_flag == -1)

    }
}


int main()
{
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        if(i>0)
            cout<<endl;
        vars.clear();
        group.clear();
        stop.clear();
        wait.clear();
        fun();
    }

    
    return 0;
}

// AC at 2019/2/8 00:25
// spend about 4 hours
