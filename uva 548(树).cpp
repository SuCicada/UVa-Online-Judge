#include<iostream>
#include<cstdio>
#include<sstream>
#include<cstring>
using namespace std;


int inorder[10004];
int postorder[10004];
int inindex[10004];

// int fin_inorder(int begin, int end, int value){
    // int i=begin;
    // for(;i<=end && inorder[i] != value;i++);
    
    // return inindex[value];
// }

int min_top_value = 100000004; // 最小的权和
int loft = -1;  // 叶子本身的值,
/* 参数: 当前子树的 中序前,后 后序前,后 */
int calcul(int in_begin, int in_end, int post_begin, int post_end, int alculate_root_value){
    // in_end - in_begin == post_end - post_begin
    
    int root_value = postorder[post_end]; // 根, 从后序
    int root_in_index = inindex[root_value];//fin_inorder(in_begin, in_end, root_value);

    alculate_root_value = alculate_root_value + root_value; // 新的累计根值, 加上自己身上的

    // cout<<in_begin<<" "<<in_end<<" "<<post_begin<<" "<<post_end<<" "<<alculate_root_value<<endl;
    // cout<<root_value<<" "<<root_in_index<<endl;


    if(in_end <= in_begin){ // 叶子了
        // if(loft == -1){ // 第一个叶子
        //     min_top_value = alculate_root_value;
        //     loft = inorder[in_begin];
        //     return 0;
        // }
        // cout<<alculate_root_value<<" "<<min_top_value<<"   "<<loft<<" "<<inorder[in_begin]<<endl;
        
        if(loft == -1 ||  // 第一个叶子
            (alculate_root_value < min_top_value) ||  
            (alculate_root_value == min_top_value && inorder[in_begin] < loft) ) {
                min_top_value = alculate_root_value;
                loft = inorder[in_begin];
            }
        return 0;
    }

    int len = root_in_index-1-in_begin;

    if(root_in_index > in_begin){
        calcul(in_begin, root_in_index-1,
                post_begin, post_begin + len, 
                alculate_root_value); // 左枝
    }

    len = in_end - root_in_index-1;
    if(root_in_index < in_end){
        calcul(root_in_index+1, in_end, 
                post_end-1-len , post_end-1, 
                alculate_root_value); // 右枝
    }

    return 0;
}

void init(){
    memset(inorder,0,sizeof(inorder));
    memset(postorder,0,sizeof(postorder));
    memset(inindex,0,sizeof(inindex));
    min_top_value = 100000004; // 最小的权和
    loft = -1;  // 叶子本身的值
}

int main()
{
    int row = 0;
    string line;
    while(getline(cin,line)){
        // cout<<n<<" ";
        stringstream ss(line);
        int i=0;
        int n;
        
        if(row==0){
            // 新的一组, 要初始化
            // 代表是一组中的第一行,即中序遍历
            init();
            while(ss>>n){
                inorder[i] = n;
                inindex[n] = i;
                i++;
            }
            row = 1;
        }else{
            // 一组中的第二行, 即后序遍历
            while(ss>>n){
                postorder[i++] = n;
            }
            row = 0;

            calcul(0,i-1,0,i-1,0);
            cout<<loft<<endl;
        }

        // char c = cin.get();
        // cout<<c<<endl;
        // if(c!=' '){
            // 新的一行
            // if(row==0) 
                // row = 1;
            // else{
                // for(int j=0;j<i;j++) cout<<inorder[j]<<" ";cout<<endl;
                // for(int j=0;j<i;j++) cout<<postorder[j]<<" ";cout<<endl;

                // loft = postorder[i-1];    

                // cout<<"res---- "<<loft<<endl;
                // row = 0;
            // }
            // i = 0;
        // }
    }

    return 0; 
}
// AC at 2020/03/21