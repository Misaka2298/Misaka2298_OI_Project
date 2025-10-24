// Problem: P2016 战略游戏
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2016
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// Time: 2025-10-24 08:19:03

#include <bits/stdc++.h>
using namespace std;
const int maxn = 3010;

int n;
int e[maxn], ne[maxn], h[maxn], idx;
int f[maxn][2];

void addedge(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void dfs(int u, int fa)
{
	f[u][1] = 1;
	for(int i = h[u] ; i != -1 ; i = ne[i])
	{
		int j = e[i];
		
		if(j == fa)
			continue;
		dfs(j, u);
		
		f[u][1] += min(f[j][0], f[j][1]);
		f[u][0] += f[j][1];
	}
}

signed main()
{
	memset(h, -1, sizeof h);
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
	{
		int a, b, k;
		cin >> a >> k;
		while(k --)
		{
			cin >> b;
			addedge(a, b); addedge(b, a);
		}
	}
	
	dfs(0, -1);
	
	cout << min(f[0][0], f[0][1]);

	
}