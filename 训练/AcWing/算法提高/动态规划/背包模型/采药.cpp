// Problem: 采药
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/425/
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// Time: 2025-09-02 19:56:27

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;

int m, n;
int v[maxn], w[maxn];
int f[maxn];

signed main()
{
	cin >> m >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> v[i] >> w[i];
	
	for(int i = 1 ; i <= n ; i ++)
		for(int j = m ; j >= v[i] ; j --)
			f[j] = max(f[j], f[j-v[i]] + w[i]);
	
	cout << f[m];
	
}