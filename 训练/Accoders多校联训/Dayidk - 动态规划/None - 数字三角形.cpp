// Problem: 数字三角形
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/900/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Time: 2025-07-29 15:48:33
// expect pts = 

#include <bits/stdc++.h>
using namespace std;
const int maxn = 510;

int n;
int g[maxn][maxn];
int f[maxn][maxn];

signed main()
{
	cin >> n;
	
	for(int i = 0 ; i <= n ; i ++)
		for(int j = 0 ; j <= n+1 ; j ++)
			f[i][j] = -INT_MAX;
			
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= i ; j ++)
			cin >> g[i][j];
	
	f[1][1] = g[1][1];
	for(int i = 2 ; i <= n ; i ++)
		for(int j = 1 ; j <= i ; j ++)
			f[i][j] = max(f[i-1][j], f[i-1][j-1]) + g[i][j];
	
	int res = -INT_MAX;
	for(int i = 1 ; i <= n ; i ++)
		res = max(res, f[n][i]);
	cout << res;
}