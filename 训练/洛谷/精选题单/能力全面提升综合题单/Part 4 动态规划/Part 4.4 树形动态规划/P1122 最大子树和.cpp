// Problem: P1122 最大子树和
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1122
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// Time: 2025-10-24 10:52:12

#include <bits/stdc++.h>
using namespace std;
const int maxn = 16010*2;

int n;
int w[maxn];
int f[maxn];
int e[maxn], ne[maxn], h[maxn], idx;

void addedge(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void dfs(int u, int fa)
{
	f[u] = w[u];
	for(int i = h[u] ; i != -1 ; i = ne[i])
	{
		int j = e[i];
		if(j == fa)
			continue;
		//cout << u << endl;
		dfs(j, u);
		
		f[u] = max(f[u], f[u]+f[j]);
		//cout << u << ' ' << f[u] << endl;
	}
}

signed main()
{
	cin >> n;
	memset(h, -1, sizeof h);
	memset(f, -0x3f, sizeof f);
	for(int i = 1 ; i <= n ; i ++)
		cin >> w[i];
	
	for(int i = 1 ; i < n ; i ++)
	{
		int a, b;
		cin >> a >> b;
		addedge(a, b); addedge(b, a);
	}
	
	dfs(1, 0);
	
	int mx = -0x3f3f3f3f;
	for(int i = 1 ; i <= n ; i ++)
		mx = max(mx, f[i]);
	
	cout << mx;
	
	
	
	
	
	
}