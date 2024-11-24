#include <bits/stdc++.h>
using namespace std;
const int maxn = 202 , INF = 1e9;
int dist[maxn][maxn];
int n , m , Q;

void floyd()
{
	for(int k = 1 ; k <=n ; k++)
		for(int i = 1 ; i <= n ; i++)
			for(int j = 1 ; j <= n ; j++)
				dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
				
	return;
}

int main()
{
	cin >> n >> m >> Q;
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= n ; j++)
		{
			if(i == j) dist[i][j] = 0;
			else dist[i][j] = INF;	
		}
		
	int a,b,w;
	while(m--)
	{
		cin >> a >> b >> w;
		dist[a][b] = min(dist[a][b] , w);
	}
	
	floyd();
	
	while(Q--)
	{
		cin >> a >> b;
		if(dist[a][b] > INF / 2) cout << "impossible" << endl;
		else cout << dist[a][b] << endl;
	}
	return 0;
}