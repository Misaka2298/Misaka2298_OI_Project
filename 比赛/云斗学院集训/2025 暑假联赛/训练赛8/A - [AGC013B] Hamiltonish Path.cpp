// A
// Problem: AT_agc013_b [AGC013B] Hamiltonish Path
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/AT_agc013_b
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Time: 2025-08-09 14:28:57

#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;

int n, m;
int e[maxn], ne[maxn], h[maxn], idx;
int deg[maxn];
vector<int> ans;
bool st[maxn];

void addedge(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u)
{
	bool flag = false;
	for(int i = h[u] ; i != -1 ; i = ne[i])
		if(st[e[i]] != 1)
			flag = 1;
			
	if(!flag) 
	{
		cout << ans.size() << endl;
		for(auto res : ans)
			cout << res << ' ';
		exit(0);
	}
	for(int i = h[u] ; i != -1 ; i = ne[i])
	{
		int j = e[i];
		if(st[j])
			continue;
		st[j] = true;
		ans.push_back(j);
		dfs(j);
	}
}

signed main()
{
	cin >> n >> m;
	memset(h, -1, sizeof h);
	for(int i = 0 ; i < m ; i ++)
	{
		int a, b;
		cin >> a >> b;
		addedge(a, b);
		addedge(b, a);
		deg[a] ++;
		deg[b] ++;
	}
	
	int mn = 1e9;
	for(int i = 1 ; i <= n ; i ++)
		mn = min(mn, deg[i]);
	int sta = 0;
	for(int i = 1 ; i <= n ; i ++)
		if(deg[i] == mn)
		{
			sta = i;
			break;
		}
	
	st[sta] = true;
	ans.push_back(sta);
	dfs(sta);
	
	cout << ans.size() << endl;
	for(auto res : ans)
		cout << res << ' ';
	return 0;
}