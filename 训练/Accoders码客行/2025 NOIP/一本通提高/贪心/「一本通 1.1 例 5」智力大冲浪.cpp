#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+10;

int m, n;
struct Task{
	int lim, sub;
}tasks[maxn];
priority_queue<int, vector<int>, greater<int>> heap;

bool cmp(Task a, Task b)
{
	return a.lim < b.lim;
}

signed main()
{
	cin >> m >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> tasks[i].lim;
	for(int i = 1 ; i <= n ; i ++)
		cin >> tasks[i].sub;
	
	sort(tasks+1, tasks+1+n, cmp);
	int day = tasks[1].lim, ans = 0;
	
	for(int i = 1 ; i <= n ; i ++)
	{
		if(day < tasks[i].lim)
		{
			while(day < heap.size())
			{
				ans += heap.top();
				heap.pop();
			}
			day = tasks[i].lim;
		}
		heap.push(tasks[i].sub);
	}
	
	while(day < heap.size())
	{
		ans += heap.top();
		heap.pop();
	}
	
	cout << m - ans;
}