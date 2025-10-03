// Problem: 多重背包问题 I
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/4/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Time: 2025-07-28 18:29:05
// expect pts = 100

#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;

int n, m;
int v[maxn], w[maxn], s[maxn];
int f[maxn][maxn];

signed main()
{
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++)
		cin >> v[i] >> w[i] >> s[i];
	
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 0 ; j <= m ; j ++)
			for(int k = 0 ; k<=s[i] && k*v[i]<=j ; k ++)
				f[i][j] = max(f[i][j], f[i-1][j-k*v[i]]+k*w[i]);
	
	cout << f[n][m];
}