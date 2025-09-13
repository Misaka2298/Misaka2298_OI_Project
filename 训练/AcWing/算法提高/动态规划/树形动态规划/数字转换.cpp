// Problem: 数字转换
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1077/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Time: 2025-09-13 18:08:51

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;

int n;
int e[maxn], ne[maxn], h[maxn], idx;
int sum[maxn];
int ans;
bool st[maxn];

void addedge(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dfs(int u)
{
	int d = 0;
	int d1 = 0, d2 = 0;
	
	for(int i = h下[u] ; i != -1 ; i = ne[i])
	{
		int j = e[i];
		d = dfs(j) + 1;
		if(d > d1)
			d2 = d1, d1 = d;
		else if(d > d2)
			d2 = d;
	}
	ans = max(ans, d1+d2);
	return d1;
}

signed main()
{
	cin >> n;
	memset(h, -1 , sizeof h);
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 2 ; j<= n / i ; j ++)
			sum[i * j] += i;
	
	for(int i = 2 ; i <= n ; i ++)
		if(i > sum[i])
			addedge(sum[i], i), st[i] = 1;
	
	for(int i = 1 ; i <= n ; i ++)
		if(!st[i])
			dfs(i);
	
	cout << ans;
	
}