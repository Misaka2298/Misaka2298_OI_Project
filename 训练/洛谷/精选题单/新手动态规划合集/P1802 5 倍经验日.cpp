// Problem: P1802 5 倍经验日
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1802
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// Time: 2025-10-21 17:54:31

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+10;

int n, m;
long long lose[maxn], win[maxn], use[maxn];
long long f[maxn][maxn];

signed main()
{
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++)
		cin >> lose[i] >> win[i] >> use[i];
	
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 0 ; j <= m ; j ++)
		{
			//f[i][j] = f[i-1][j];
			if(j >= use[i])
				f[i][j] = max(f[i-1][j-use[i]]+win[i], f[i-1][j]+lose[i]);
			else
				f[i][j] = f[i-1][j] + lose[i];
		}
		
	cout << f[n][m] * (long long)5;
	
}