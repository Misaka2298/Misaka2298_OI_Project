#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2+10;

int n, m;
long long g[maxn][maxn];

signed main()
{
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= n ; j++)
		{
			if(i == j)	g[i][j] = 0;
			else g[i][j] = 0x3f3f3f3f;
		}
	
	int v1,v2;
	long long w;
	
	for(int i = 0 ; i < m ; i++)
	{ 
		cin>>v1>>v2>>w;
		g[v2][v1] = g[v1][v2] = min(g[v1][v2], w);
	}
			
	for(int k = 1 ; k <= n ; k++)
		for(int i = 1 ; i <= n ; i++)
			for(int j = 1 ; j <= n ; j++)
				if((i!=j)&&(i!=k)&&(j!=k))
					g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
	
	for(int i = 1 ; i <= n ; i ++)
	{
		for(int j = 1 ; j <= n ; j++)
		{
			if(j > 1) cout << " ";
			cout << g[i][j];
		}
		cout << endl;
	}
		
}