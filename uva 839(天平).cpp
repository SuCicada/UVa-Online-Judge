#include<iostream>
using namespace std;


int lair(){
    int wl,dl,wr,dr;
    cin>>wl>>dl>>wr>>dr;
    if(wl == 0){
        /* have left branch */
        wl = lair();
    }

    if(wr == 0){
        wr = lair();
    }

    if(wl==0 || wr==0 || wl*dl != wr*dr){
        return 0;
    }else{
        return wl+wr;
    }
}


int main(){
    int T;
    cin>>T;
    while(T--){
        int res = lair();
        if(res == 0){
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
        }
        if(T>0){
            cout<<endl;
        }
    }
}

// AC at 2020/07/21 23:58