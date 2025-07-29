// Problem: 最长公共子序列
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/899/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Time: 2025-07-29 16:00:18
// expect pts = 

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;

int n, m;
char a[maxn], b[maxn];
int f[maxn][maxn];

signed main()
{
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];
	for(int j = 1 ; j <= m ; j ++)
		cin >> b[j];
	
	for(int i = 1 ; i <= n; i ++)
		for(int j = 1 ; j <= m ; j ++)
		{
			f[i][j] = max(f[i-1][j], f[i][j-1]);
			if(a[i] == b[j])
				f[i][j] = max(f[i][j], f[i-1][j-1]+1);
		}
		
	cout << f[n][m];
}