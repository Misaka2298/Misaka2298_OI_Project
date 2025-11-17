// Problem: P1948 [USACO08JAN] Telephone Lines S
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1948
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// Time: 2025-11-17 19:44:54

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+10, maxm = 2e4+10, maxk = 1e4+10;

int n, m, k;
int h[maxn], e[maxm], ne[maxm], w[maxm], idx;
int dist[maxn][maxk];
bool st[maxn][maxk];

struct Node{
	int u, dis, layer;
};
struct NodeCmp{
	bool operator()(const Node& a, const Node& b) const{
		return a.dis < b.dis;
	}
};

void addedge(int a, int b, int c)
{
	e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
}

void sol()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1][0] = 0;
	priority_queue<Node, vector<Node>, NodeCmp> heap;
	heap.push({1, 0, 0});
	
	while(heap.size())
	{
		auto t = heap.top(); heap.pop();
		int u = t.u, dis = t.dis, layer = t.layer;
		
		for(int i = h[u] ; i != -1 ; i = ne[i])
		{
			int j = e[i];
			if(dist[j][layer] > max(dis, w[i]))
			{
				dist[j][layer] = max(dis, w[i]);
				heap.push({j, dist[j][layer], layer});
			}
			if(layer < k && dist[j][layer+1] > dis)
			{
				dist[j][layer+1] = dis;
				heap.push({j, dist[j][layer+1], layer+1});
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
	
	sol();
	if(dist[n][1] == 0x3f3f3f3f)
		cout << -1;
	else
	{
		int ans = 0x3f3f3f3f;
		for(int i = 0; i <= k; i ++)
		    ans = min(ans, dist[n][i]);
		cout << ans;
	}
		
}