// Problem: 最低通行费
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1020/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Time: 2025-08-10 20:10:17

#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;

int n;
int w[maxn][maxn];
int f[maxn][maxn];

signed main()
{
	cin >> n;
	memset(f, 0x3f, sizeof f);
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= n ; j ++)
			cin >> w[i][j], f[i][j] = 0;
	
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= n ; j ++)
		{
			if(i==1 && j==1)
				f[i][j] = w[i][j];
			else
			{
				f[i][j] = min(f[i-1][j], f[i][j-1]) + w[i][j];
			}
		}
	
	cout << f[n][n];
}