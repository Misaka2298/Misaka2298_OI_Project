// Problem: 背包问题求方案数 - 朴素
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
int f[maxn][maxn], g[maxn][maxn];

signed main()
{
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++)
		cin >> v[i] >> w[i];

	for(int i = 1 ; i <= n ; i ++)
		for(int j = 0 ; j <= m ; j ++)
		{
            f[i][j] = f[i - 1][j];
            if (j >= v[i]) f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
        }
	
	g[0][0] = 1;
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 0 ; j <= m ; j ++)
		{
			if (f[i][j] == f[i - 1][j])
                g[i][j] = (g[i][j] + g[i - 1][j]) % mod;
                
            if (j >= v[i] && f[i][j] == f[i - 1][j - v[i]] + w[i])
                g[i][j] = (g[i][j] + g[i - 1][j - v[i]]) % mod;
		}
	
	int ans = 0;
	for(int j = 0 ; j <= m ; j ++)
		if(f[n][j] == f[n][m])
			ans = (ans + g[n][j]) % mod;
	
	cout << ans;
}