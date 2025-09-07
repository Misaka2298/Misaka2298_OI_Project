// Problem: 潜水员
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1022/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Time: 2025-09-07 11:17:06

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+10;

int n, m, t;
int O[maxn], N[maxn], v[maxn];
int f[maxn][maxn];

signed main()
{
	cin >> n >> m >> t;
	for(int i = 1 ; i <= t ; i ++)
		cin >> O[i] >> N[i] >> v[i];
	
	memset(f, 0x3f, sizeof f);
	f[0][0] = 0;
	for(int i = 1 ; i <= t ; i ++)
		for(int j = n ; j >= 0 ; j --)
			for(int k = m ; k >= 0 ; k --)
				f[j][k] = min(f[j][k], f[max(j-O[i], 0)][max(k-N[i], 0)] + v[i]);
	cout << f[n][m];
}