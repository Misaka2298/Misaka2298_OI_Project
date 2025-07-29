// Problem: 01背包问题
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/2/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Time: 2025-07-28 16:06:22
// expect pts = 100

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+10;

int n, m;
int v[maxn], w[maxn];
int f[maxn];

signed main()
{
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++)
		cin >> v[i] >> w[i];
	
	for(int i = 1 ; i <= n ; i ++)
		for(int j = m ; j >= v[i] ; j --)
				f[j] = max(f[j], f[j-v[i]]+w[i]);
	
	cout << f[m];
}