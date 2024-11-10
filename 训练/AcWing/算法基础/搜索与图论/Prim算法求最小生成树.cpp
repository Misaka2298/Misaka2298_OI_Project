#include <bits/stdc++.h>
using namespace std;
const int maxn = 510 , INF = 0x3f3f3f3f;
int n , m;
int g[maxn][maxn];
int dist[maxn];
bool st[maxn];

int prim()
{
	memset(dist,0x3f,sizeof dist);
	int res = 0;
	for(int i = 0 ; i < n ; i++)
	{
		int t = -1;
		for(int j = 1 ; j <= n ; j++)
			if(!st[j] && (t == -1 || dist[t] > dist[j] ))
				t = j;
			
		if(i && dist[t] == INF) return INF;
		if(i) res += dist[t];
		st[t] = true;
		
		for(int j = 1 ; j <= n ; j ++) dist[j] = min(dist[j] , g[t][j]);
		
	}
	return res;
}

int main()
{
	cin >> n >> m;
	memset(g,0x3f,sizeof g);
	while(m--) 
	{
		int a , b , w;
		cin >> a >> b >> w;
		g[a][b] = g[b][a] = min(g[a][b] , w);
	}
	
	int ans = prim();
	
	if(ans == INF) cout << "impossible";
	else cout << ans;
	return 0;
}