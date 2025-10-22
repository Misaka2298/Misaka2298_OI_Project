// Problem: P1063 [NOIP 2006 提高组] 能量项链
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1063
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// Time: 2025-10-22 18:11:02

#include <bits/stdc++.h>
using namespace std;
const int maxn = 210;

int n;
int f[maxn][maxn];
int num[maxn];
int ans;

signed main()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> num[i], num[i+n] = num[i];
	
	for(int len = 2 ; len <= n ; len ++)
	{
		for(int l = 1 ; l+len-1 <= n*2 ; l ++)
		{
			int r = l+len-1;
			for(int k = l ; k < r ; k ++)
				f[l][r] = max(f[l][r], f[l][k]+f[k+1][r]+num[l]*num[k+1]*num[r+1]);
			ans = max(ans, f[l][r]);
		}
	}
	cout << ans;
}