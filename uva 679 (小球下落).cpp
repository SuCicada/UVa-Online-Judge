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
        cout<<res<<" "<<waitReverse<<endl;
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
// AC at 2020/03/11


/*

假设一共6层

最底下一层数量
以这个数量为一组进行轮回
2 ** (6-1) = 32

N = 32


M -> N/2/2
P -> N/2/M
if( i >= M )
i -> [ M -i ] + P



M -> N/2
P -> N/2/M
if( i >= M )
 i -> [ M - i ] + P
16 -> [16 - 16] + P
17 -> [17 - 16] + P
18 -> [18 - 16] + P

 
底层数量  分组按照的大小  当前尺度的分组的答案偏移量  
 N   M   P 
32  16   1  
     8   2
     4   4 
     2   8  
     1  16  

29          
29  16     22 +  1 = 23 
13   8     20 +  2 = 22
5    4     16 +  4 = 20
1    1      0 + 16 = 16 
sub
0           0

11101

4 3   2  11 
1100  12 00 

3   
4 4  1
0    0 

3 2 1
1 1 2
0   0 

0   0
1   2
2   1
3   3
4


先对 2^(d-1) 取模

index = 输入-1
对index取反转,反转位数为 (d-1)

结果 + 2^(d-1)


假设层数d，球数n
    
res = (n-1) % 2^(d-1)

res = ((1 * 2) + 0) * 2 

T(n)  = (T(n >> 2) + (n & 1)) * 2
T(29) = T(14) * 2


29
14   1
 7   0
 3   1
 1   1
 0   1


res = res+


奇数左, 偶数右

*/

/*
    0     0
    1    16
    2     8
    3    24

    4     4
    5    20
    6    12
    7    28

    8     2
    9    18
   10    10
   11    26

   12     6
   13    22
   14    14
   15    30
---
   16     1
   17    17
   18     9
   19    25
   20     5
   21    21
   22    13
   23    29

   24     3
   25    19
   26    11
   27    27
   28     7
   29    23
   30    15
   31    31





   32     0
   33    16
   34     8
   35    24
   36     4
   37    20
   38    12
   39    28





*/