// Problem: P1049 [NOIP 2001 普及组] 装箱问题
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1049
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// Time: 2025-10-22 14:28:11

#include <bits/stdc++.h>
using namespace std;
const int maxn = 100, maxm = 20020;

int n, m;
int v[maxn];
int f[maxm];

signed main()
{
	cin >> m >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> v[i];
	
	for(int i = 1 ; i <= n ; i ++)
		for(int j = m ; j >= v[i] ; j --)
			f[j] = max(f[j], f[j-v[i]]+v[i]);

	cout << m - f[m];
}