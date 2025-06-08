#include <bits/stdc++.h>
using namespace std;
const int maxn = 310;

int n, m;
int f[maxn][maxn], g[maxn][maxn];
int dx[]={0, 1, 0, -1}, dy[]={1, 0, -1, 0};

int dp(int x, int y)
{
	int &v = f[x][y];
	if(v != -1)
		return v;
	
	v = 1;
	for(int i = 0 ; i < 4 ; i++)
	{
		int nex = x+dx[i], ney = y+dy[i];
		
		if(nex>=1 && nex<=n && ney>=1 && ney<=m && g[x][y] > g[nex][ney])
			v = max(v, dp(nex, ney)+1);
	}
	return v;
}

signed main()
{
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= m ; j ++)
			cin >> g[i][j];
			
	memset(f, -1, sizeof f);
	
	int ans = 0;
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= m ; j++)
			ans = max(ans, dp(i, j));
	
	cout << ans;
}