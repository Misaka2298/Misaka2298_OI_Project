#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;

int n, m, T;
int p[maxn], maxp=-1e9;
int e[maxn], ne[maxn], h[maxn], idx;
int dist[maxn];
bool vis[maxn];

int iloveccf(int pos, int need)
{
	if(need > maxp)
		return -1;
		
	if(p[pos] >= need)
		return 0;
	memset(dist, 0x3f, sizeof dist);
	memset(vis, false, sizeof vis);
	queue<int>q;
	q.push(pos);
	dist[pos] = 0;
	vis[pos] = true;
	
	while(q.size())
	{
		int t = q.front();
		q.pop();
		for(int i = h[t] ; i != -1 ; i = ne[i])
		{
			int now = e[i];
			if(!vis[now] && dist[now] > dist[t])
			{
				dist[now] = dist[t] + 1;
				vis[now] = true;
				if(p[now] >= need) return dist[now];
				q.push(now);
			}
		}
	}
	return -1;
}

void addedge(int a, int b)
{
	e[idx] = b ,ne[idx] = h[a] , h[a] = idx++;
}

signed main()
{
	cin >> n >> m >> T;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> p[i];
		maxp = max(maxp, p[i]);
	}
	//cout << maxp << endl;
	
	memset(h, -1, sizeof h);
	for(int i = 0 ; i < m ; i++)	
	{
		int u, v;
		cin >> u >> v;
		addedge(u,v); addedge(v,u);
	}
	
	while(T--)
	{
		int x, q;
		cin >> x >> q;
		cout << iloveccf(x, q) << endl;
	}
}