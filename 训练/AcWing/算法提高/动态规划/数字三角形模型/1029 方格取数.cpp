// Problem: 方格取数
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1029/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Time: 2025-08-10 20:14:24

#include <bits/stdc++.h>
using namespace std;
const int maxn = 20;

int n;
int w[maxn][maxn];
int f[maxn][maxn][maxn];

signed main()
{
	cin >> n;
	int a, b, c;
	while(a || b || c)
	{
		cin >> a >> b >> c;
		w[a][b] = c;
	}
	
	for(int k = 2 ; k <= n+n ; k ++)
		for(int i1 = 1 ; i1 <= n ; i1 ++)
			for(int i2 = 1 ; i2 <= n ; i2 ++)
			{
				int j1 = k-i1, j2 = k-i2;
				if (j1 >= 1 && j1 <= n && j2 >= 1 && j2 <= n)
				{
					int rew = w[i1][j1];
					if(i1 != i2) rew += w[i2][j2];
					int &x = f[k][i1][i2];
					f[k][i1][i2] = max(x, f[k-1][i1-1][i2-1] + rew);
					f[k][i1][i2] = max(x, f[k-1][i1-1][i2] + rew);
					f[k][i1][i2] = max(x, f[k-1][i1][i2-1] + rew);
					f[k][i1][i2] = max(x, f[k-1][i1][i2] + rew);
				}
			}
			
			
			
	cout << f[n+n][n][n];
			
			
			
}