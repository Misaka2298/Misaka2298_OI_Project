// Problem: 股票买卖 IV
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1059/
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// Time: 2025-09-07 15:14:25

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10, maxk = 110;

int n, m;
int w[maxn];
int f[maxn][maxk][3];

signed main()
{
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++)
		cin >> w[i];
	
	memset(f, -0x3f, sizeof f);
	f[0][0][0] = 0;
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 0 ; j <= m ; j ++)
		{
			f[i][j][0] = f[i - 1][j][0];
            if (j) f[i][j][0] = max(f[i][j][0], f[i - 1][j - 1][1] + w[i]);
			f[i][j][1] = max(f[i-1][j][1], f[i-1][j][0] - w[i]);
		}
	
	int ans = 0;
	for(int j = 0 ; j <= m ; j ++)
		ans = max(ans, f[n][j][0]);
	cout << ans;
}