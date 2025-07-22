//Tree1-C-DoubleDFS
#include <bits/stdc++.h>
using namespace std;
const int maxn = 400010;

int n;
int e[maxn], ne[maxn], h[maxn], idx, dist[maxn], farest;
bool vis[maxn];

void addedge(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u)
{
	if(vis[u]) return;
	vis[u] = true;
	for(int i = h[u] ; i != -1 ; i = ne[i])
	{
		int j = e[i];
		if(!vis[j])
		{
			dist[j] = dist[u] + 1;
			if(dist[j] > dist[farest]) farest = j;
			dfs(j);
		}
	}
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	memset(h, -1, sizeof h);
	cin >> n;
	for(int i = 0 ; i < n-1 ; i++)
	{
		int a, b;
		cin >> a >> b;
		addedge(a, b); addedge(b, a);
	}
	
	farest = 1;
	dfs(1);
	
	memset(vis, false, sizeof(vis));
    memset(dist, 0, sizeof(dist));
	dist[farest] = 0;
	dfs(farest);
	
	cout << dist[farest];
	
}