// Problem: 多重背包问题 II
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/5/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Time: 2025-07-28 18:37:20
// expect pts = 

#include <bits/stdc++.h>
using namespace std;
const int maxn = 20100;

int n, m;
int v[maxn], w[maxn];
int f[maxn];

signed main()
{
	cin >> n >> m;
	int idx = 0;
	for(int i = 1 ; i <= n ; i ++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		int k = 1;
		while(k <= c)
		{
			idx ++;
			v[idx] = a * k;
			w[idx] = b * k;
			c -= k;
			k *= 2;
		}
		
		if(c > 0)
		{
			idx ++;
			v[idx] = c * a;
			w[idx] = c * b;
		}
	}
	
	n = idx;
	
	for(int i = 1 ; i <= n ; i ++)
		for(int j = m ; j >= v[i] ; j --)
			f[j] = max(f[j], f[j-v[i]]+w[i]);
		
	cout << f[m];
}