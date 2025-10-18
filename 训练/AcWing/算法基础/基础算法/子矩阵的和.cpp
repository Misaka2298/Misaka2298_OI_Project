// Problem: 子矩阵的和
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/798/
// Memory Limit: 64 MB
// Time Limit: 2000 ms
// Time: 2025-10-18 19:34:02

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+10;

int n, m, q;
int a[maxn][maxn], s[maxn][maxn];

signed main()
{
	cin >> n >> m >> q;
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= m ; j ++)
			cin >> a[i][j];
	
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= m ; j ++)
			s[i][j] = a[i][j] + s[i-1][j] + s[i][j-1] - s[i-1][j-1];
	
	while(q --)
	{
		int x, y, xx, yy;
		cin >> x >> y >> xx >> yy;
		cout << s[xx][yy] - s[x-1][yy] - s[xx][y-1] + s[x-1][y-1] << endl;
	} 
			
}