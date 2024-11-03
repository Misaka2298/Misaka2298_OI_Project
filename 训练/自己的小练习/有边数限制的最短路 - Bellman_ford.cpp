#include <bits/stdc++.h>
using namespace std;
const int maxn = 510 , maxm = 1e5+10;

int n , m , k;
int dist[maxn] , backup[maxn];
struct Edge
{
	int a , b , w;
}edge[maxm];

void bellman_ford()
{
	memset(dist,0x3f,sizeof dist);
	dist[1]=0;
	
	for(int i = 0 ; i < k ; i ++)
	{
		memcpy(backup,dist,sizeof dist);
		
		for(int j = 0 ; j < m ; j++)
		{
			int a = edge[j].a , b = edge[j].b , w=edge[j].w;
			dist[b] = min(dist[b] , backup[a] + w);
		}
	}
	
	if(dist[n] > 0x3f3f3f3f / 2)
		cout << "impossible";
	else cout <<dist[n];
}

int main()
{
	cin >> n >> m >> k;
	for(int i = 0 ; i < n ;i ++)
	{
		int a , b , w ;
		cin >> a >> b >> w;
		edge[i] = {a,b,w};
	}
	
	bellman_ford();
	return 0;
}