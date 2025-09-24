// Problem: 树的最长路径
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1074/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Time: 2025-09-13 15:30:32

#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e7+10;

int n;
int e[maxn], ne[maxn], h[maxn], w[maxn], idx;
int ans;

void addedge(int a, int b, int c)
{
	e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

int dfs(int u, int fa)
{
	int dist = 0;
	int d1 = 0, d2 = 0;
	
	for(int i = h[u] ; i != -1 ; i = ne[i])
	{
		int j = e[i];
		if(j == fa)
			continue;
		int d = dfs(j, u) + w[i];
		dist = max(dist, d);
		
		if(d > d1)
			d2 = d1, d1 = d;
		else if(d > d2)
			d2 = d;
	}
	
	ans = max(ans, d1+d2);
	return dist;
}

signed main()
{
	memset(h, -1, sizeof h);
	cin >> n;
	for(int i = 1 ; i < n ; i ++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		addedge(a, b, c);
		addedge(b, a, c);
	}
	
	dfs(1, -1);
	
	cout << ans;
} 