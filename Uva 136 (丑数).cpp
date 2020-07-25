#include<iostream>
#include<set>
using namespace std;

int main()
{
    set<long long int>num;
    num.insert(1);
    // num.insert(2);
    // num.insert(3);
    // num.insert(5);

    int sum = 0;
    int multi[3] = {2,3,5};
    // cout<<min<<endl;
    while(1){
        long long int min = *(num.begin());
        for(int i=0;i<3;i++){
            long long int n = min*multi[i];
            num.insert(n);
            // cout<<sum<<" "<<min<<" * "<<multi[i]<<" = "<<n<<endl;
            // if(sum==1500){
            //     break;
            // }            
        }
        num.erase(num.begin());
        // cout<< min << " "<< *num.begin() <<endl;
        sum++;
        if(sum==1500){
            cout<<"The 1500'th ugly number is "<<min<<"."<<endl;
            break;
        } 
        // cin.get();
    }

    return 0;
}
// AC at 2019/1/31