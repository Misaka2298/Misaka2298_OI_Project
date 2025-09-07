// Problem: 混合背包问题
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/7/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Time: 2025-09-07 10:15:33

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;

int n, m;
int v[maxn], w[maxn], s[maxn];
int f[maxn];

signed main()
{
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> v[i] >> w[i] >> s[i];
		if(!s[i])
		{
			for(int j = v[i] ; j <= m ; j ++)
				f[j] = max(f[j], f[j-v[i]] + w[i]);
		} 
		else
		{
			if (s[i] == -1)
				s[i] = 1;
			for(int k = 1 ; k <= s[i] ; k *= 2)
			{
				for(int j = m ; j >= k * v[i] ; j --)
					f[j] = max(f[j], f[j-k*v[i]] + k*w[i]);
				s[i] -= k;
			}
			if(s[i])
				for(int j = m ; j >= s[i] * v[i] ; j --)
					f[j] = max(f[j], f[j-s[i]*v[i]] + s[i]*w[i]);
		}
	}
	cout << f[m];
}