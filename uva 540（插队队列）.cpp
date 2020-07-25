#include <iostream>
#include <queue>
#include <map>
#include <string>
using namespace std;

int main()
{
	int T=1;
	int n; //几个组
	while(cin>>n&&n!=0)
	{
		map<int,int> group;  //每个人对应其所属的组
		for(int i=0;i<n;i++)
		{
			int m;//每组几个
			cin>>m;
			for(int j=0;j<m;j++)
			{
				int name;  //每人号码
				cin>>name;
				group[name] = i; //人的号码对应于组名
			}
		}

		string str;
		queue<int> que;//存组的顺序
		queue<int> per[1003];//存所有人的顺序,per[i]是第i组
		
		cout<<"Scenario #"<<T++<<endl;
		while(cin>>str&&str!="STOP")
		{
		//cout<<"???"<<endl;
			if(str == "ENQUEUE")
			{
				int name; 
				cin>>name;
				int qn=group[name];//组名
				if(per[qn].empty())  //说明这个组还没有在队列中
					que.push(qn); //组名入组队列
				per[qn].push(name);
			}
			else
			{
				int qn=que.front(); //获取组名
				cout<<per[qn].front()<<endl; //输出出队列的
				per[qn].pop();  //人出组
				if(per[qn].empty())//如果此组空了
					que.pop();
			}
		}
		cout<<endl;
	}
	return 0;
}
//AC at 2018/5/9