// Problem: 没有上司的舞会
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/287/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Time: 2025-09-13 20:01:30

#include <bits/stdc++.h>
using namespace std;
const int maxn = 12010;

int n;
int e[maxn], ne[maxn], h[maxn], w[maxn], idx;
int f[maxn][2];
bool hasfa[maxn];

void dfs(int u)
{
	f[u][1] = w[u];
	for(int i = h[u] ; i != -1 ; i = ne[i])
	{
		int j = e[i];
		dfs(j);
		
		f[u][1] += f[j][0];
		f[u][0] += max(f[j][0], f[j][1]);
	}
}

void addedge(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

signed main()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> w[i];
	memset(h, -1, sizeof h);
	
	for(int i = 1 ; i < n ; i ++)
	{
		int a, b;
		cin >> a >> b;
		addedge(b, a);
		hasfa[a] = 1;
	}
	
	for(int i = 1 ; i <= n ; i ++)
		if(!hasfa[i])
		{
			dfs(i);
			cout << max(f[i][0], f[i][1]);
		}
	
	
}