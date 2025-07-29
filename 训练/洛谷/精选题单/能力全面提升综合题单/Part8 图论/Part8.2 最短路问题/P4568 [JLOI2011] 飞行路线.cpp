#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10, maxk = 55;

int n, m, k, sta, ed;
int dist[maxn][maxk];
bool st[maxn][maxk];
vector<pair<int, int>> g[maxn];

void heap_dijkstra()
{
	memset(dist, 0x3f, sizeof dist);
	dist[sta][0] = 0;
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> heap;
	//dist, id, ktick
	heap.push({0, sta, 0});
	
	while(heap.size())
	{
		auto [udist, u, uktick] = heap.top(); heap.pop();
		
		if(st[u][uktick]) continue;
		st[u][uktick] = true;
		
		for(auto [v, uvlen] : g[u])
		{
			if(dist[v][uktick] > udist + uvlen)
			{
				dist[v][uktick] = udist + uvlen;
				heap.push({dist[v][uktick], v, uktick});
			}
			if(uktick < k && dist[v][uktick+1] > udist)
			{
				dist[v][uktick+1] = udist;
				heap.push({dist[v][uktick+1], v, uktick+1});
			}
		}
	}
}

signed main()
{
	cin >> n >> m >> k >> sta >> ed;
	for(int i = 0 ; i < m ; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		g[a].push_back({b, c});
		g[b].push_back({a, c});
	}
	
	heap_dijkstra();
	
	int ans = 0x3f3f3f3f;
	for(int i = 0 ; i <= k ; i ++)
		ans = min(ans, dist[ed][i]);
	if(ans == 0x3f3f3f3f) cout << -1;
	else cout << ans;
}

/*
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
#define t(x, i) (x+i*n)

int n, m, k;
int sta, ed;
vector<pair<int, int>> g[maxn*2];
int dist[maxn*2];
bool st[maxn*2];

void addedge(int a, int b, int c)
{
	g[t(a, 0)].push_back({t(b, 0), c});
	g[t(b, 0)].push_back({t(a, 0), c});
	
	g[t(a, 1)].push_back({t(b, 1), c});
	g[t(b, 1)].push_back({t(a, 1), c});
}

void spfa(int sta)
{
	memset(dist, 0x3f, sizeof dist);
	queue<int> q;
	q.push(sta);
	st[sta] = true;
	dist[sta] = 0;
	
	while(q.size())
	{
		int x = q.front(); q.pop();
		st[x] = false;
		for(auto [v, len] : g[x])
			if(dist[v] < dist[x] + len)
			{
				dist[v] = dist[x] + len;
				if(!st[v]) st[v] = true, q.push(v);
			}
	}
}


signed main()
{
	cin >> n >> m >> k >> sta >> ed;
	for(int i = 0 ; i < n ; i++)
		g[t(i, 0)].push_back({t(i, 1), 0});
	
	for(int i = 0 ; i < m ; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		addedge(a, b, c);
	}
	
	spfa(sta);
	cout << dist[t(1, ed)];
}
*/