#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;

int tree[1048576]; // 最多 2**20-1
 


int main()
{
    int T;
    cin>>T;
    while(T--){
        int depth,index;
        cin>>depth>>index;
        // cout<<depth<<" "<<index<<endl;
        int res = 0;
        int bottom = pow(2,depth-1); // 底层数量
        int waitReverse = (index-1) % bottom; 
        for(int i=0;i<depth-1;i++){
            res <<= 1;   
            res += (waitReverse & 1);
            waitReverse >>= 1;
        // cout<<res<<" "<<waitReverse<<endl;
        }
        cout<<res + bottom<<endl;
        continue;
        res = 0;
        memset(tree,0,sizeof(tree));
        for(int i=0;i<index-1;i++){
            int n = 1;
            for(int j=1;j<depth;j++){
                tree[n] = !tree[n];
                if(tree[n] == 1){
                    // left
                    n *=2;
                }else{
                    n = n * 2 + 1;
                }
                // cout<<i<<" "<<j<<" "<<n<<endl;                
            }
                tree[n] = !tree[n];

            // printf("%2d",i+1);
            // for(int k=pow(2,depth-1);k<=pow(2,depth)-1;k++){
            //     cout<<" "<<tree[k];
        // }
                // if((int)(log(k+1)/log(2))==log(k+1)/log(2)){
                // }

            printf(" | %2d %2d %2d \n",i,n,n-(int)pow(2,depth-1) );
            // printf("%5d %5d\n", i , n-(int)pow(2,depth-1));
            // cout<<" | "<<i<<" "<<n<<" "<<n-pow(2,depth-1)<<endl;

            res = n;
        }
        cout<<res<<endl;  

    }
    int end;
    cin>>end;
    // cout<<end<<endl;
    return 0;
}