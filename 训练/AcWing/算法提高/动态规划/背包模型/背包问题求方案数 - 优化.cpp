// Problem: 背包问题求方案数 - 优化
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/11/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Time: 2025-09-07 13:33:19

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+10, mod = 1e9+7;

int n, m;
int v[maxn], w[maxn];
int f[maxn], g[maxn];

signed main()
{
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++)
		cin >> v[i] >> w[i];
	
	g[0] = 1;
	for(int i = 1 ; i <= n ; i ++)
		for(int j = m ; j >= v[i] ; j ++)
		{
			int temp = max(f[j], f[j-v[i]] + w[i]), c = 0;
			if(temp == f[j])
				c = g[j] % mod;
			if(temp == f[j-v[i]] + w[i])
				c = (c + g[j-v[i]]) % mod;
			f[j] = temp, g[j] = c;
		}
	
	int ans = 0;
	for(int j = 0 ; j <= m ; j ++)
		if(f[j] == f[m])
			ans = (ans + g[j]) % mod;
	cout << ans;
}