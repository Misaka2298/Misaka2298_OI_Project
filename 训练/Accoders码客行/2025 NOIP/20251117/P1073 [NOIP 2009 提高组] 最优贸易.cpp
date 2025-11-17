// Problem: P1073 [NOIP 2009 提高组] 最优贸易
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1073
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// Time: 2025-11-17 18:59:23

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10, maxm = 1e6+10;
typedef pair<int, int> PII;

int n, m;
int w[maxn];
int h[maxn], e[maxm], ne[maxm], idx;
int dist[maxn][4];
bool st[maxn][4];

void addedge(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void sol()
{
	memset(dist, -0x3f, sizeof dist);
	dist[1][1] = 0;
	queue<PII> q;
	q.push({1, 1});
	st[1][1] = 1;
	
	while(q.size())
	{
		auto t = q.front(); q.pop();
		int u = t.first, layer = t.second;
		st[u][layer] = 0;
		
		for(int i = h[u] ; i != -1 ; i = ne[i])
		{
			int j = e[i];
			if(dist[j][layer] < dist[u][layer])
			{
				dist[j][layer] = dist[u][layer];
				if(!st[j][layer])
				{
					q.push({j, layer});
					st[j][layer] = 1;
				}
				
			}
		}
		
		if(layer == 1 && dist[u][layer+1] < dist[u][layer] - w[u])
		{
			dist[u][layer+1] = dist[u][layer] - w[u];
			if(!st[u][layer+1])
			{
				q.push({u, layer+1});	
				st[u][layer+1] = 1;
			}
		}
		if(layer == 2 && dist[u][layer+1] < dist[u][layer+1] + w[u])
		{
			dist[u][layer+1] = dist[u][layer] + w[u];
			if(!st[u][layer+1])
			{
				q.push({u, layer+1});	
				st[u][layer+1] = 1;
			}
		}
	}
}

signed main()
{
	cin >> n >> m;
	memset(h, -1, sizeof h);
	for(int i = 1 ; i <= n ; i ++)	
		cin >> w[i];
	
	for(int i = 1 ; i <= m ; i ++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		addedge(a, b);
		if(c == 2)
			addedge(b, a);
	}
	
	sol();
	
	cout << max(dist[n][3], 0);
}