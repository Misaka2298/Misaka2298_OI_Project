// Problem: P4822 [BJWC2012] 冻结
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4822
// Memory Limit: 125 MB
// Time Limit: 3000 ms
// Time: 2025-11-17 18:44:37

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+10, maxk = 55;
typedef pair<int, pair<int, int >> PIII;

int n, m, k;
int e[maxn], ne[maxn], h[maxn], w[maxn], idx;
int dist[maxn][maxk];
bool st[maxn][maxk];

void addedge(int a, int b, int c)
{
	e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
}

void sol_mindist()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1][0] = 0;
	priority_queue<PIII, vector<PIII>, greater<PIII>> heap;
	heap.push({0, {1, 0}});
	
	while(heap.size())
	{
		auto t = heap.top(); heap.pop();
		int u = t.second.first, dis = t.first, layer = t.second.second;
		if(st[u][layer])
			continue;
		st[u][layer] = 1;
		
		for(int i = h[u] ; i != -1 ; i = ne[i])
		{
			int j = e[i];
			if(dist[j][layer] > dis + w[i])
			{
				dist[j][layer] = dis + w[i];
				heap.push({dist[j][layer], {j, layer}});
			}
			if(layer < k && dist[j][layer+1] > dis + w[i] / 2)
			{
				dist[j][layer+1] = dis + w[i] / 2;
				heap.push({dist[j][layer+1], {j, layer+1}});
			}
		}
	}
}

signed main()
{
	cin >> n >> m >> k;
	memset(h, -1, sizeof h);
	for(int i = 1 ; i <= m ; i ++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		addedge(a, b, c);
		addedge(b, a, c);
	}
	
	sol_mindist();
	
	int ans = 0x3f3f3f3f;
	for(int i = 1 ; i <= k ; i ++)
		ans = min(ans, dist[n][i]);
	cout << ans;
}