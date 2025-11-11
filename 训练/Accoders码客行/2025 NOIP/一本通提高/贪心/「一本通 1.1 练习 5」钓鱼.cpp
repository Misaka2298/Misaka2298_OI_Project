// Problem: #10009. 「一本通 1.1 练习 5」钓鱼
// Contest: LibreOJ
// URL: https://loj.ac/p/10009
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Time: 2025-11-11 08:29:54

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10, maxm = 110;
typedef long long LL;

int n, m;
LL f[maxm][maxn];
int sta[maxm], delta[maxm], t[maxm];
LL ans;

signed main()
{
	cin >> n >> m;
	m *= 12;
	for(int i = 1 ; i <= n ; i ++)
		cin >> sta[i];
	for(int i = 1 ; i <= n ; i ++)
		cin >> delta[i];
	for(int i = 2 ; i <= n ; i ++)
		cin >> t[i];
	
	for(int i = 1, tmp = t[1] ; i <= n ; tmp += t[i+1], i ++)
	{
		for(int j = tmp ; j <= m ; j ++)
		{
			for(int k = 0 ; k <= j - tmp ; k ++)
				f[i][j] = max(f[i][j], f[i-1][j-t[i]-k] + max(0, k*sta[i] - k*(k-1)/2 * delta[i]));
			ans = max(ans, f[i][j]);
		}
	}
	
	cout << ans;
}