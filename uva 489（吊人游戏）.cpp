//用两个整型来记录当前还允许错的次数，和原始字符串的总字符数
//1，因为重复猜测不算错，所以我们先将guess字符串中的重复字符消去，用循环和string::erase()
//2，外循环猜测字符串，内循环原始字符串，如果相同，就将原始字符串的此元素变成‘ * ’。
//3，没猜中一次就记录，内循环结束后来更新记录。若果win或lose就return函数，否则循环都结束之后就说明是‘弃权’。
#include<iostream>
#include<string>
using namespace std;
    string orig,guess;
int hang(int num,int right)
{
    for(int i=0;i<guess.size();i++)
    {
        int iff=0;
        for(int j=0;j<orig.size();j++)
        {
            if(orig[j]==guess[i])
            {
                orig[j]='*';
                iff=1;
                num--;
            }
            if(num==0)
            {
                cout<<"You win."<<endl;
                return 1;//break;
            }
        }
        if(iff==0)
        {
            right--;
        }
        if(right<0)
        {
            cout<<"You lose."<<endl;
            return -1;
        }
//        if(num==0)
//        {
//            cout<<"win"<<endl;
//            break;
//        }
    }
    cout<<"You chickened out."<<endl;
}
int main()
{
    int T;
    while(cin>>T&&T!=-1)
    {
        cin>>orig>>guess;
        for(int i=0;i<guess.size();i++)
        {
            for(int j=i+1;j<guess.size();j++)
            {
                if(guess[j]==guess[i])
                    guess.erase(guess.begin()+j);
            }
        }
        //cout<<guess<<endl;
        int right=6;//错误次数
        int num=orig.size();//要猜的个数
        cout<<"Round "<<T<<endl;
        hang(num,right);
    }
    return 0;
}
//AC at 2018/2/7
