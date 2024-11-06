#include <bits/stdc++.h>
using namespace std;
const int maxn = 202 , INF = 1e9;
int g[maxn][maxn];
int n , m , Q;

void floyd()
{
	for(int k = 1 ; k <=n ; k++)
		for(int i = 1 ; i <= n ; i++)
			for(int j = 1 ; j <= n ; j++)
				g[i][j] = min(g[i][j],g[i][k]+g[k][j]);
				
	return;
}

int main()
{
	cin >> n >> m >> Q;
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= n ; j++)
		{
			if(i == j) g[i][j] = 0;
			else g[i][j] = INF;	
		}
		
	int a,b,w;
	while(m--)
	{
		cin >> a >> b >> w;
		g[a][b] = min(g[a][b] , w);
	}
	
	floyd();
	
	while(Q--)
	{
		cin >> a >> b;
		if(g[a][b] > INF / 2) cout << "impossible" << endl;
		else cout << g[a][b] << endl;
	}
	return 0;
}