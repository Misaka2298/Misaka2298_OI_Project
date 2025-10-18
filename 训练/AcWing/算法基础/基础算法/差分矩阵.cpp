// Problem: 差分矩阵
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/800/
// Memory Limit: 64 MB
// Time Limit: 2000 ms
// Time: 2025-10-18 19:54:56

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+10;

int n, m, q;
int s[maxn][maxn], a[maxn][maxn], pre[maxn][maxn];

void insert(int x, int y, int xx, int yy, int c)
{
	s[x][y] += c;
	s[xx+1][y] -= c;
	s[x][yy+1] -= c;
	s[xx+1][yy+1] += c;
}

signed main()
{
	cin >> n >> m >> q;
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= m ; j ++)
			cin >> a[i][j];
			
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= m ; j ++)
			insert(i, j, i, j, a[i][j]);
	
	while(q --)
	{
		int x, y, xx, yy, c;
		cin >> x >> y >> xx >> yy >> c;
		insert(x, y, xx, yy, c);
	}
	
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= m ; j ++)
			pre[i][j] = s[i][j] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
	
	for(int i = 1 ; i <= n ; i ++)
	{
		for(int j = 1 ; j <= m ; j ++)
			cout << pre[i][j] << ' ';
		cout << endl;
	}
		
		
		
		
}