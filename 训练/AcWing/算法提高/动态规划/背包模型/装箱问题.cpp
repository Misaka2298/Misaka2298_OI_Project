// Problem: 装箱问题
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1026/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Time: 2025-09-02 20:02:55

#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;

int n, m;
int v[maxn], w[maxn];
int f[maxn];

signed main()
{
	cin >> m >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> v[i], w[i] = v[i];
	
	for(int i = 1 ; i <= n ; i ++)
		for(int j = m ; j >= v[i] ; j --)
			f[j] = max(f[j], f[j-v[i]] + w[i]);
	
	cout << m - f[m];
}