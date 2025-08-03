#include <bits/stdc++.h>
using namespace std;
const int maxn = 3000;

int g[maxn][maxn];
int n, nodes, roads;
int cows[maxn];

void floyd()
{
	for(int k = 1 ; k <= nodes ; k ++)
		for(int i = 1 ; i <= nodes ; i ++)
			for(int j = 1 ; j <= i ; j++)
				g[j][i] = g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
}

signed main()
{
	cin >> n >> nodes >> roads;
	for(int i = 0 ; i < n ; i ++)
	{
		int a;
		cin >> a;
		cows[a] ++;
	}
	memset(g, 0x3f3f3f3f, sizeof g);
	for(int i = 0 ; i < roads ; i ++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		g[a][b] = g[b][a] = min(g[a][b] , c);
	}
	
	int ans = 0x3f3f3f3f;
	floyd();
	for(int i = 1 ; i <= nodes ; i++)
	{
		int sum = 0;
		for(int j = 1 ; j <= nodes ; j ++)
		{
			if(i == j || !cows[j]) continue;
			sum += g[i][j] * cows[j];
		}
		if(ans > sum && sum >= 0) ans = sum;
	}
	cout << ans;
}