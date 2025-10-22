// Problem: P1060 [NOIP 2006 普及组] 开心的金明
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1060
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Time: 2025-10-22 14:41:54

#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e4+10, maxm = 100;

int m, n;
int v[maxn], w[maxn];
int f[maxn];

signed main()
{
	cin >> m >> n;
	for(int i = 1, x; i <= n ; i ++)
		cin >> v[i] >> x, w[i] = x * v[i];
	
	
	for(int i = 1 ; i <= n ; i ++)
		for(int j = m ; j >= v[i] ; j --)
			f[j] = max(f[j], f[j-v[i]]+w[i]);
	cout << f[m];
	
}