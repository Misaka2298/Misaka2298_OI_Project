//稠密图用邻接矩阵存，不是邻接表。
#include <bits/stdc++.h>
using namespace std;
const int maxn = 510;
int n , m;
int g[maxn][maxn];
bool st[maxn];  
int dist[maxn];

int dijkstra()
{
	memset(dist,0x3f,sizeof dist);
	dist[1] = 0;
	for(int i = 0 ; i < n ; i++)
	{
		int t = -1;//未确定最短路的点中的最短路点
		for(int j = 1 ; j <= n ; j++)
			if(!st[j] && (t == -1 || dist[j] < dist[t]))
				t = j ;
		
		st[t] = true;
		for(int j = 1 ; j <= n ; j++)
			dist[j] = min(dist[j] , dist[t]+g[t][j]);
	}
	if(dist[n] != 0x3f3f3f3f) return dist[n];
	else return -1;
}

int main()
{
	cin >> n >> m;
	memset(g,0x3f,sizeof g);
	int a , b ,c;
	for(int i = 0 ; i < m ; i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		c = min(c,g[a][b]);
		g[a][b] = c;
	}
	
	cout << dijkstra();
	
	return 0;
}

/*
3 3
1 2 2
2 3 1
1 3 4

3
*/

/*
5 5
1 2 3
3 1 4
2 4 6
4 2 1
1 4 7

-1
*/