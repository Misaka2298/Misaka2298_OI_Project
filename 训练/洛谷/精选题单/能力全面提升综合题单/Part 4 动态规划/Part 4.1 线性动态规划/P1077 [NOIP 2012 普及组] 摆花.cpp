// Problem: P1077 [NOIP 2012 普及组] 摆花
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1077
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// Time: 2025-10-20 19:23:41

#include <bits/stdc++.h>
using namespace std;
const int maxn = 110, mod = 1e6+7;

int n, m;
int f[maxn][maxn];
int s[maxn];

signed main()
{
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++)
		cin >> s[i];
	
	f[0][0] = 1;
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 0 ; j <= m ; j ++)
			for(int k = 0 ; k <= min(j, s[i]) ; k ++)//debug
				f[i][j] = (f[i][j] + f[i-1][j-k]) % mod;
	cout << f[n][m];
}