#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
#define endl '\n';
typedef pair<int, int> PII;

int n, m;
int e[maxn], ne[maxn], h[maxn], w[maxn], idx;
int dist[8][maxn];
int fri[8], ans = 0x3f3f3f3f;
bool st[maxn], isvis[maxn];

void addedge(int a, int b, int c)
{
	e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

void dijkstra(int u, int sta)
{
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	dist[u][sta] = 0;
	memset(st, 0, sizeof st);
	heap.push({0, sta});
	while(heap.size())
	{
		auto t = heap.top(); heap.pop();
		int tid = t.second;
		
		if(st[tid]) continue;
		st[tid] = 1;
		
		for(int i = h[tid] ; i != -1 ; i = ne[i])
		{
			int j = e[i];
			if(dist[u][j] > dist[u][tid] + w[i])
			{
				dist[u][j] = dist[u][tid] + w[i];
				heap.push({dist[u][j], j});
			}
		}
	}
}

void dfs(int u, int cost, int last)
{
	if(u == 6)
	{
		ans = min(ans, cost);
		return;	
	}
	
	for(int i = 0 ; i < 6 ; i ++)
	{
		if(isvis[i]) continue;
		
		isvis[i] = 1;
		dfs(u+1, cost + dist[last][fri[i]], i);
		isvis[i] = 0;
	}
}

signed main()
{
	memset(dist, 0x3f, sizeof dist);
	memset(h, -1, sizeof h);
	cin >> n >> m;
	fri[0] = 1;
	for(int i = 1 ; i < 6 ; i++)
		cin >> fri[i];
	for(int i = 0 ; i < m ; i ++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		addedge(a, b, c); addedge(b, a, c);
	}
	
	//dijkstra(1, 1);
	for(int i = 0 ; i < 6 ; i++)
	{
		dijkstra(i, fri[i]);
	}
	
	dfs(0,0,0);
	
	/*
	for(int i = 0 ; i < 6 ;i ++)
	{
		for(int j = 1 ; j <= n ; j ++)
			cout << dist[i][j] <<' ';
		cout << endl;
	}
	*/
	
	cout << ans;
}