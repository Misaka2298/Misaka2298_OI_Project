// Problem: CF144D Missile Silos
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF144D
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// Time: 2025-10-05 13:36:46

#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
typedef pair<int, int> PII;

int n, m, sta;
int e[maxn], ne[maxn], h[maxn], w[maxn], idx;
int dist[maxn];
bool st[maxn];

void addedge(int a, int b, int c)
{
	e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
}

void dijkstra()
{
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	heap.push({0, sta});
	memset(dist, 0x3f, sizeof dist);
	dist[sta] = 0;
	
	while(heap.size())
	{
		auto t = heap.top(); heap.pop();
		int u = t.second, dis = t.first;
		if(st[u]) continue;
		st[u] = 1;
		for(int i = h[u] ; i != -1 ; i = ne[i])
	 	{
			int j = e[i];
			if(dist[j] > dist[u] + w[i])
			{
				dist[j] = dist[u] + w[i];
				heap.push({dist[j], j});
			}
		}
	}
}

signed main()
{
	memset(h, -1, sizeof h);
	cin >> n >> m >> sta;
	for(int i = 1 ; i <= m ; i ++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		addedge(a, b, c);
		addedge(b, a, c);
	}
	
	dijkstra();
	
	int goal;
	cin >> goal;
	int ans = 0;
	for(int i = 1 ; i <= n ; i ++)
		if(dist[i] == goal)
			ans ++;
	for(int i = 1 ; i <= n ; i ++)
		cout << dist[i] << ' ';
	cout << endl;
	
	cout << ans;
	
}