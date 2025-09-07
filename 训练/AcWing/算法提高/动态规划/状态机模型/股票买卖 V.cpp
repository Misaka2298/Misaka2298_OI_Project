// Problem: 股票买卖 V
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1060/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Time: 2025-09-07 15:29:37

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;

int n, w[maxn], f[maxn][3];//0-empty, 1-have, 2-freeze

signed main()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> w[i];
	
	memset(f, -0x3f, sizeof f);
	f[0][0] = 0;
	for(int i = 1 ; i <= n ; i ++)
	{
		f[i][0] = max(f[i-1][0], f[i-1][2]);
		f[i][1] = max(f[i-1][1], f[i-1][0] - w[i]);
		f[i][2] = f[i-1][1] + w[i];
	}
	
	cout << max(f[n][0], f[n][2]);
}	