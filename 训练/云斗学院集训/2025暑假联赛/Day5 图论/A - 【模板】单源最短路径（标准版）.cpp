// Problem: P4779 【模板】单源最短路径（标准版）
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4779
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// Time: 2025-08-07 10:34:53

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
	memset(dist, 0x3f, sizeof dist);
	memset(st, false, sizeof st);
	//st[sta] = 1;
	dist[sta] = 0;
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	heap.push({0, sta});
	
	while(heap.size())
	{
		auto t = heap.top(); heap.pop();
		int tid = t.second, tdist = t.first;
		
		if(st[tid]) continue;
		st[tid] = 1;
		
		for(int i = h[tid]; i != -1; i = ne[i])
		{
			int j = e[i];
			if(dist[j] > w[i] + dist[tid])
			{
				dist[j] = w[i] + dist[tid];
				heap.push({dist[j], j});
			}
		}
	}
}

signed main()
{
	memset(h, -1, sizeof h);
	cin >> n >> m >> sta;
	for(int i = 0; i < m; i ++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		addedge(a, b, c);
	}
	
	dijkstra();
	for(int i = 1; i <= n; i ++)
		cout << dist[i] << ' ';
}