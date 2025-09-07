// Problem: 庆功会
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1021/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Time: 2025-09-07 09:36:32

#include <bits/stdc++.h>
using namespace std;
const int maxn = 6010;

int n, m;
int v, s, w;
int f[maxn];

signed main()
{
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> v >> w >> s;
		for(int j = m ; j >= v ; j --)
			for(int k = 0 ; k<=s && k*v<=j ; k ++)
				f[j] = max(f[j], f[j - k*v] + k*w);
	}
	cout << f[m];
}