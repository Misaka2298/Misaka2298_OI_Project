#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
typedef pair<int,int> PII;
typedef long long LL;

priority_queue<PII>idleps;//空闲的打印机
priority_queue<PII>busyps;//忙碌的打印机
//first最早可以使用时间，second编号

struct Task{
	LL s , t , tnum;
}tasks[maxn];

int n , m;
vector<LL>ans[maxn];//打印机处理过的文件
//LL cnt[maxn]; // 打印机处理文件的次数

bool cmp(Task a ,Task b)
{
	return a.t > b.t;
}

signed main()
{
	//priority_queue<PII,vector<PII>,greater<PII>>tasks;
	//first时刻,second耗时
	//init
	cin >> n >> m;
	int s , t;
	for(int i = 1; i <= n ; i++)
	{
		cin >> s >> t;
		tasks[i] = {s,t,i};
	}
	
	sort(tasks , tasks+n ,cmp);
	
	for(int i = 1 ; i <= m ; i++)
		idleps.push({0,i});
		
	//solve
	for(int i = 1; i <= n ; i++)
	{
		int t = tasks[i].t , s = tasks[i].s , tnum = tasks[i].tnum;
		vector<LL>adds;
		while(!busyps.empty())
		{
			if(t <= busyps.top().first)
			{
				auto printer = busyps.top();
				LL num = printer.second;
				busyps.pop();
				adds.push_back(num);
			}
			else break;	
		}
		for(auto a : adds) idleps.push({0,a});
		if(idleps.size())//无需等待
		{
			auto printer = idleps.top();
			idleps.pop();
			LL time = printer.first , num = printer.second;
			time = t + s;
			ans[num].push_back(tnum);
			//cnt[num]++;
			busyps.push({time,num});
		}
		else
		{
			auto printer = busyps.top();
			busyps.pop();
			LL time = printer.first , num = printer.second;
			time = s + time;
			ans[num].push_back(tnum);
			//cnt[num]++;
			busyps.push({time,num});
		}
	}
	
	for(int i = 1 ; i<=m ; i++)
	{
		cout << ans[i].size() <<' ';
		sort (ans[i].begin (), ans[i].end ());
		for(auto a : ans[i]) cout << a << ' ';
		cout <<endl;
	}
	return 0;
}