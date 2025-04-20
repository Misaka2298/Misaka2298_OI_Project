//T6
#include <bits/stdc++.h>
using namespace std;
const int maxn = 810;

int g[maxn][maxn], cows[maxn], distsum[maxn];
int n, nodes, roads; 
//bool st[maxn];

void floyd()
{
	for(int k = 1 ; k <= nodes ; k++)
		for(int i = 1 ; i <= nodes ; i++)
			for(int j = 1 ; j <= nodes ; j++)
				g[i][j] = min(g[i][j],g[i][k]+g[k][j]);
	return;
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> nodes >> roads;
	for(int i = 0 ; i < n ; i ++)
	{
		int cow;
		cin >> cow;
		cows[cow] ++;
	}
	memset(g, 0x3f, sizeof g);
	for(int i = 0 ; i < maxn ; i ++)
		g[i][i] = 0;
	
	for(int i = 0 ; i < roads ; i ++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		g[a][b] = g[b][a] = min(g[a][b],c);
	}
	
	floyd();
	for(int node = 1 ; node <= nodes ; node++)
	{
		for(int subnode = 1 ; subnode <= nodes ; subnode ++)
		{
			if(subnode == node) continue;
			distsum[node] += g[node][subnode] * cows[subnode];
		}
	}
	
	int ans = 0x3f;
	for(int node = 1 ; node <= nodes ; node++)
		ans = min(ans, distsum[node]);
	cout << ans;
}