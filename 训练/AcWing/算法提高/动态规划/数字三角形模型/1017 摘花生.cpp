// Problem: 摘花生
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1017/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Time: 2025-08-10 20:05:11

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+10;


int T;
int n, m;
int w[maxn][maxn];
int f[maxn][maxn];

signed main()
{
	cin >> T;
	while(T--)
	{
		cin >> n >> m;
		//memset(f, 0x3f, sizeof f);
		for(int i = 1 ; i <= n ; i ++)
			for(int j = 1 ; j <= m ; j ++)
				cin >> w[i][j], f[i][j] = 0;
				
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= m; j ++)
			{
				if(i==1 && j==1)
					f[i][j] = w[i][j];
				else
					f[i][j] = max(f[i-1][j], f[i][j-1]) + w[i][j];
			}
		cout << f[n][m] << endl;
	}
}