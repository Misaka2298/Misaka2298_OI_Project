// Problem: 分组背包问题
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/9/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Time: 2025-07-28 18:59:13
// expect pts = 

#include <bits/stdc++.h>
using namespace std;
const int maxn = 210;

int n, m, T;
int v[maxn][maxn], w[maxn][maxn], s[maxn];
int f[maxn];
int lastc;

signed main()
{
	cin >> m >> n >> T;
	int idx = 0;
	for(int i = 0 ; i < n ; i ++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if(i && lastc != c)
		{
			s[lastc] = idx;
			idx = 0;
		}
		lastc = c;
		v[c][++idx] = a;
		w[c][idx] = b;
	}
	s[lastc] = idx;
	
	for(int i = 1 ; i <= T ; i ++)
		for(int j = m ; j >= 0 ; j --)
			for(int k = 0 ; k <= s[i] ; k ++)
				if(v[i][k] <= j)
					f[j] = max(f[j], f[j-v[i][k]]+w[i][k]);
	cout << f[m];
}