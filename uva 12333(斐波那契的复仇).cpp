#include<iostream>
#include<map>
#include<cmath>
#include<vector>
#include<cstdio>
using namespace std;

class Site{
public:
    int minIndex; // 到目前这个结点为止的最小序数
    map<char,Site*> next; // 下一个位们的 位对应结点
    // Site* next; // 下一个位的结点
};

Site root;
// vector<string> fibonacci(100005);
int limitSite = 52;
int sum = 0;
void putTree(string a,int index){
    int len = a.size();
    Site* front = &root; 
    for(int i=0;i<len;i++){
        // 开始一位一位找, 每一位都需要
        // 1. 比较树中有没有结点, 没有就new一个,把自己加上(还有序数),然后记录下一个指针,并把自己给了上一个指针, 
        //    有则比较序数, 换成小的
        char c = a[i];
        if(!(front->next).count(c)){  // 如果没有
            Site* newsite = new Site();  // 手动申请空间, 不然函数结束后就会被清理
            sum ++;
            newsite->minIndex = index; 
            (front->next)[c] = newsite;
            // cout<<i<<" "<<c<<" "<<(front->next).count(c)<<endl;
            // cout<<i<<" "<<c<<" "<<((front->next)[c])->minIndex<<endl;
        }else{
            // cout<<i<<" "<<c<<" "<<((front->next)[c])->minIndex<<endl;
            (front->next)[c]->minIndex = min((front->next)[c]->minIndex, index);
        }

        front = (front->next)[c]; // 跳到下一个结点(位)
    }
    // return;
}

int find(string str){
    int len = str.size();
    Site* front = &root;
    for(int i=0;i<len;i++){
        // 一位一位找, 如果有一位没有找到, 那说明树中没有这个前缀, 返回-1
        // 一直找到最后一位, 这最后一位所在的结点上的值就是要的
        char c = str[i];
        if(!(front->next).count(c)){  // 如果没有
            return -1;
        }
        front = (front->next)[c]; // 跳到下一个结点(位)
    }

    // 没有位了,所以上一个结点就是最后一位所在结点
    return front->minIndex;
}

string add(string a,string b){
    int aLen = a.size()-1; // 数长
    int bLen = b.size()-1;
    int alastSite = min(limitSite, aLen);
    int blastSite = min(limitSite, bLen);
    int aSiteNum = a[alastSite]; // 位数奇偶,从最后一位取得
    int bSiteNum = b[blastSite];
    int ten = 0;
    int newLen = bLen+1; // 新数长度,一位放头放0

    int i = aLen-1;
    int j = bLen-1;
    if(aLen == bLen && aSiteNum!=bSiteNum){ // 位数不等,并且数字已经取了部分了
        i--; // 小的数扔一位
    }

    string res(newLen+1,'0');  // 最后一位放位数(奇偶)
    int resSite = newLen-1;  // 记录结果的当前位数
    for(; j>=0; i--,j--){
        int aa='0';
        if(i>=0){
            aa = a[i];
        }
        int r = aa-'0' + b[j]-'0' + ten;
        ten = r/10;
        res[resSite--] = r%10+'0';
        // cout<<r<<" "<<ten<<" "<<res<<endl;
    }
    // if(plusSite){
    res[0] = ten+'0';
    // }
    if(ten==0){ //不会进位
        string result = res.substr(1,limitSite+1);
        result[result.size()-1] = bSiteNum;
        return result;
    }else{
    // if(aSiteNum!=bSiteNum){ // 位数不等
        string result = res.substr(0,limitSite);
        result[result.size()-1] = !(bSiteNum-'0') +'0';
        return result;
    }
}

int main(){

    string a,b,c;
    a = "11"; 
    b = "11";
    c = "";
    putTree("1",0);
    for(int i=2;i<100000;i++){  // 100000以内,不包括
        c = add(a,b);
        a = b;
        b = c;
        string s = c.substr(0, min(40,(int)c.size()-1) );
        putTree(s,i);
    }
    cout<<sum<<endl;
    return 0;

    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        string n;
        cin>>n;
        int res;
        printf("Case #%d: %d\n", i+1, find(n));
    }
    return 0;
}

// AC at 2020/3/7 13:00



/*


#include<iostream>
#include<algorithm>
#include<iterator>
#include<vector>
#include<string>
#include<cstdio>
#include<iomanip>
#include<map>
#include<cmath>
#include<cstring>
using namespace std;

vector<string> fibonacci(100005);
map<string,int> fiboSorted;
vector<string> fiboName(100005);
vector<int> fiboIndex(100005);
int limitSite = 52;

string add(string a,string b){
    int aLen = a.size()-1;
    int bLen = b.size()-1;
    int aSiteNum = a[limitSite>aLen?aLen:limitSite];
    int bSiteNum = b[limitSite>bLen?bLen:limitSite];
    int ten = 0;
    int newLen = bLen+1; // 新数长度,一位放头放0

    int i = aLen-1;
    int j = bLen-1;
    if(aLen == bLen && aSiteNum!=bSiteNum){ // 位数不等,并且数字已经取了部分了
        i--; // 小的数扔一位
    }

    string res(newLen+1,'0');  // 最后一位放位数(奇偶)
    int resSite = newLen-1;  // 记录结果的当前位数
    for(; j>=0; i--,j--){
        int aa='0';
        if(i>=0){
            aa = a[i];
        }
        int r = aa-'0' + b[j]-'0' + ten;
        ten = r/10;
        res[resSite--] = r%10+'0';
        // cout<<r<<" "<<ten<<" "<<res<<endl;
    }
    // if(plusSite){
    res[0] = ten+'0';
    // }
    if(ten==0){ //不会进位
        string result = res.substr(1,limitSite+1);
        result[result.size()-1] = bSiteNum;
        return result;
    }else{
    // if(aSiteNum!=bSiteNum){ // 位数不等
        string result = res.substr(0,limitSite+1);
        result[result.size()-1] = !(bSiteNum-'0') +'0';
        return result;
    }
}
vector<string> fibo(100005);
// int find(string str,int fbegin,int fend);

// map<int,map<int,map<int,int> > > dict;
int dict[1004];

int presitename = 3;    

int find(string str){
    int presitenum10 = pow(10,presitename);
    int threenum = 0;// = (name[0]-'0')*100 + (name[1]-'0')*10 + (name[2]-'0');
    int len = str.size(); // 这个长度很重要
    int nowSiteName = presitename; // min(len,presitename); // 考虑数字要更小的情况, 比如12 我们要存12的位置, 不能是120
    for(int j=0;j<nowSiteName;j++){
        if(len >= j+1){ // 加1是因为要比对数字字符长度
            threenum += (str[j]-'0') * pow(10,nowSiteName-1-j);
        }
    }

    int newSite = pow(10,presitename-min(len,presitename));  // 这个是为了确定查找的区间, 要使用的数量级和长度相关



    // cout<<threenum<<endl;
    int index = dict[threenum];
    int end = -1;
    int nextSite = threenum+newSite;
    if(dict[nextSite] == -1){
        nextSite += 5* newSite;
    }
    // while((end == -1) && (nextSite <= presitenum10)){  // 防止 dict下一位没有东西
    //     end = dict[nextSite];
    //     cout<<nextSite<<" "<<dict[nextSite]<<" "<<end<<endl;
    //     nextSite += newSite;
    // }

    if(nextSite > presitenum10){
        end = 100001;
    }else{
        end = dict[nextSite]; 
    }

    // cout<<index<<" "<<end<<endl;
    // 要找合适的,先从index开始一个一个数比较,
    // 一位一位的比,如果相同,就记录fibo序数,取小,一直比到不相等,跳出
    int startSame = 0;
    int minFiboIndex = 100001;
    for(int i=index;i<end;i++){
        if( str.size() <= fiboName[i].size()){
            string fs = fiboName[i].substr(0,str.size()); 
            // cout<<i<<" "<<str<<" "<<fs<<endl;
            if(str == fs){
                minFiboIndex = min(fiboIndex[i],minFiboIndex);
                startSame = 1;
            }else{
                if(startSame == 1){
                    break;
                }
            }
        }
    }
    if(minFiboIndex == 100001){
        minFiboIndex = -1;
    }
    return minFiboIndex;
}   

map<string,int> answer;
int run(){

    fibonacci[0] = fibonacci[1] = "11";
    fiboSorted["1"] = 0;
    for(int i=2;i<=100000;i++){
        fibonacci[i] = add(fibonacci[i-2],fibonacci[i-1]);
        string s = fibonacci[i].substr(0,fibonacci[i].size()-1);
        fiboSorted[s] = i;
        // cout<<fibonacci[i]<<" "<<i<<" "<<fiboSorted[fibonacci[i]]<<endl;
        // cout<<setw(2)<<i<<" ";
        // cout<<" "<<setw(limitSite+1)<<fibonacci[i].substr(0,fibonacci[i].size()-1)<<" ";
        // cout<<setw(4)<<fibonacci[i].substr(fibonacci[i].size()-1);
        // cout<<endl;
        // stirng aa =
        // cout<<" "<<setw(4)<<
        // cin.get();
    }

    // copy(fibonacci.begin(),fibonacci.end(),ostream_iterator<string>(cout," |\n"));
    // cout<<fibonacci[99999]<<endl;
    // cout<<endl;
    memset(dict,-1,sizeof(dict));

    int i=0;
    for(map<string,int>::iterator m = fiboSorted.begin();m!=fiboSorted.end();m++,i++){
        // cout<<m->first<<" "<<m->second<<endl;
        fiboName[i] = m->first;
        fiboIndex[i] = m->second;

        string name = m->first;
        int index = i;
        int threenum = 0;// = (name[0]-'0')*100 + (name[1]-'0')*10 + (name[2]-'0');
        int len = name.size(); // 这个长度很重要
        int nowSiteName = presitename; // min(len,presitename); // 考虑数字要更小的情况, 比如12 我们要存12的位置, 不能是120
        for(int j=0;j<nowSiteName;j++){
            if(len >= j+1){ // 加1是因为要比对数字字符长度
                threenum += (name[j]-'0') * pow(10,nowSiteName-1-j);
            }
        }

        // cout<<threenum<<" "<<dict[threenum]<<" "<<index<<endl;   
        if(dict[threenum] == -1){ // 未记录
            dict[threenum] = index; // 因为递增遍历 map 数列, 所以第一次填入的 map 序号肯定是最小的
        }

    }

    // for(int i=0;i<sizeof(dict)/sizeof(int);i++){
    //     printf("%03d %6d %s\n ",i,dict[i],fiboName[dict[i]].c_str());
    //         // cout<<i<<dict[i]<<endl;
    // }
    // makedict();


// return 0;
    // int mapLen = i;
    int T;
    cin>>T;
    for(int i=0;i<T;i++){
        string n;
        cin>>n;
        int res;
        if(answer.count(n)){
            res = answer[n];
        }else{
            res = find(n);
            answer[n] = res;
        }
        printf("Case #%d: %d\n", i+1, res);
        // cout<<"find(n)<<endl;

        // int res = find(n,0,mapLen);
        // cout<<fiboIndex[res]<<endl;
    }
    // cout<<fiboSorted.size()<<endl;
    // cout<<(fiboSorted.begin()+1)->first<<endl;
}



int main()
{
    run();
    return 0;
}






*/