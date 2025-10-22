// Problem: P3146 [USACO16OPEN] 248 G
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3146
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// Time: 2025-10-22 17:37:38

#include <bits/stdc++.h>
using namespace std;
const int maxn = 260;

int n;
int f[maxn][maxn];
int ans;

signed main()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> f[i][i], ans = max(ans, f[i][i]);
	
	for(int len = 2 ; len <= n ; len ++)
	{
		for(int l = 1 ; l+len-1 <= n ; l ++)
		{
			int r = l+len-1;
			for(int k = l ; k < r ; k ++)
				if(f[l][k] == f[k+1][r] && f[l][k])
					f[l][r] = max(f[l][r], f[l][k]+1);
			ans = max(ans, f[l][r]);
		}
	}
	cout << ans;
}