// Problem: 数字组合
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/280/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Time: 2025-09-02 20:11:07

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;

int n, m;
int v[maxn];
int f[maxn];

signed main()
{
	cin >> n >> m;
	for(int i = 1; i <= n ; i ++)
		cin >> v[i];
	
	f[0] = 1;
	for(int i = 1 ; i <= n ; i ++)
		for(int j = m ; j >= v[i] ; j --)
			f[j] += f[j-v[i]];
	
	cout << f[m];
}