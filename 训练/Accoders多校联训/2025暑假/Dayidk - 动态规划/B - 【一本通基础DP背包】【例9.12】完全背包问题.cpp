// Problem: 完全背包问题
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/3/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Time: 2025-07-28 16:11:03
// expect pts = 100

//f[i][j] = max(f[i][j], f[i-1][j-v[i]]+w[i], f[i-1][j-2v[i]]+2w[i])
//f[i][j-v[i]]=max(      f[i-1][j-v[i]],      f[i-1][j-2v[i]]+ w[i])

#include <bits/stdc++.h>
using namespace std;
const int maxn = 10100;

int n, m;
int v[maxn], w[maxn];
int f[maxn];

signed main()
{
	cin >> m >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> v[i] >> w[i];
	
	for(int i = 1 ; i <= n ; i ++)
		for(int j = v[i] ; j <= m ; j ++)
			f[j] = max(f[j], f[j-v[i]]+w[i]);
			
	cout << "max=" << f[m];
}