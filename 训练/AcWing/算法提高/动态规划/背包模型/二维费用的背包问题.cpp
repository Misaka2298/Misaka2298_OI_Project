// Problem: 二维费用的背包问题
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/8/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Time: 2025-09-07 13:19:34

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+10;

int n, m1, m2;
int w[maxn], v1[maxn], v2[maxn];
int f[maxn][maxn];

signed main()
{
	cin >> n >> m1 >> m2;
	for(int i = 1 ; i <= n ; i ++)
		cin >> v1[i] >> v2[i] >> w[i];
	
	for(int i = 1 ; i <= n ; i ++)
		for(int j = m1 ; j >= v1[i] ; j --)
			for(int k = m2 ; k >= v2[i] ; k --)
				f[j][k] = max(f[j][k], f[j-v1[i]][k-v2[i]] + w[i]);
		
	cout << f[m1][m2];
}