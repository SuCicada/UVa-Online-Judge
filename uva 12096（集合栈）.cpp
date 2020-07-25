#include <iostream>
#include <set>
#include <map>
#include <stack>
#include <vector>
using namespace std;

map< set<int> ,int> idcache;   //每一个集合对应一个编号
vector< set<int> > setcache;   //每一个编号对应一个集合

int getid(set<int> s)
{
   	if(idcache.count(s))
        return idcache[s];
	else 
		setcache.push_back(s);      //将集合存入vector
	idcache[s]=setcache.size()-1;  //将集合存入map，从0开始，为了让map中的键与值与vector元素与下标相对应
	return idcache[s];
}

int main()
{   
   	int T;	
	cin>>T;
	while(T--)
	{
		stack<int> s;	//只是存的集合的编号
		idcache.clear();
		setcache.clear();
		int n;
		cin>>n;
		while(n--)
		{
			

			// cout<<"n"<<n<<endl;
			string str;
			cin>>str;
			if(str=="PUSH")
			{
				set<int> temps;
				int temp=getid(temps);
				s.push(temp);
			}
			else if(str=="DUP")
			{
				s.push(s.top());
			}
			else 
			{
				set<int> first =setcache[s.top()]; //这时要取的是vetor中的元素，是set<int>类型，而s里元素是int类型
				s.pop();  
				set<int> second=setcache[s.top()]; 
				s.pop(); 
				set<int> ans;
				if(str=="INTERSECT")  
				{
					set<int>::iterator i=first.begin();
					for(;i!=first.end();i++)
					{
						set<int>::iterator j=second.begin();
						for(;j!=second.end();j++)
						{
							if(*i==*j)
								ans.insert(*i);
						}
					}
				}
				if(str=="UNION")
				{
					ans=second;    //直接赋值set<int>
					set<int>::iterator i=first.begin();
					for(;i!=first.end();i++)				
					{
						ans.insert(*i);
					// 	int iff=1;
					// 	set<int>::iterator j=second.begin();
					// 	for(;j!=second.end();j++)
					// 	{
					// 		if(*i==*j)
					// 		{
					// 			iff=0;
					// 			break;
					// 		}
					// 	}
					// 	if(!iff)
					// 		ans.insert(*i);
					}
				}
				if(str=="ADD")
				{
					ans=second;    //直接赋值set<int>
					ans.insert(getid(first)); //插入int型，是first对应的编号，将first作为了ans的一个元素
				}
				s.push(getid(ans));
			}	
			cout<<setcache[s.top()].size()<<endl;

			// cout<<str<<":"<<endl;
			// stack<int> t=s;
			// for(int i=0;i<s.size();i++)
			// {	int ii=t.top();
			// 	t.pop();
			// 	set<int>::iterator it=setcache[ii].begin();
			// 	for(;it!=setcache[ii].end();it++)
			// 		cout<< *it<<" ";
			// 	cout<<"|"<<endl;
			// }
			// cout<<endl;

		}	
		cout<<"***"<<endl;
	}
	return 0;
}
//AC at 2018/5/7

