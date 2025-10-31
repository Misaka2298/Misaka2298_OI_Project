// Problem: 有向图的拓扑序列
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/description/850/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Time: 2025-10-30 17:33:06

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;

int n, m;
int e[maxn], ne[maxn], h[maxn], idx;
int d[maxn];
queue<int> q;

void addedge(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void topsort()
{
	for(int i = 1 ; i <= n ; i ++)
		if(!d[i])
			q.push(i);
	
	vector<int> ans;
	
	while(q.size())
	{
		int t = q.front(); q.pop();
		ans.push_back(t);
		for(int i = h[t] ; i != -1 ; i = ne[i])
		{
			int j = e[i];
			d[j] --;
			if(!d[j])
				q.push(j);
		}
	}
	
	if(ans.size() == n)
		for(auto i : ans)
			cout << i << ' ';
	else
		cout << -1;
}

signed main()
{
	cin >> n >> m;
	memset(h, -1, sizeof h);
	for(int i = 1 ; i <= m ; i ++)
	{
		int a, b;
		cin >> a >> b;
		d[b] ++;
		addedge(a, b);
	}
	
	topsort();
	
	
	
	
}