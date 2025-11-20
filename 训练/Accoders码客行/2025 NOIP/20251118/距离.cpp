// Problem: 距离
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1173/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Time: 2025-11-18 08:13:20

#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e4+10, maxk = 18;

int n, m;
int e[maxn], ne[maxn], h[maxn], w[maxn], idx;
int dist[maxn], depth[maxn], fa[maxn][maxk+1];
bool st[maxn];

void addedge(int a, int b, int c)
{
	e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
}

void init()
{
	queue<int> q;
	q.push(1);
	st[1] = 1;
	depth[1] = 1, depth[0] = 0;
	
	while(q.size())
	{
		int t = q.front(); q.pop();
		for(int i = h[t] ; i != -1 ; i = ne[i])
		{
			int j = e[i];
			if(st[j])
				continue;
			st[j] = 1;
			q.push(j);
			
			depth[j] = depth[t] + 1;
			dist[j] = dist[t] + w[i];
			fa[j][0] = t;
			for(int k = 1 ; k < maxk ; k ++)
				fa[j][k] = fa[fa[j][k-1]][k-1];
		}
	}
}

int get_lca(int a, int b)
{
	if(depth[b] > depth[a])
		swap(a, b);
	
	for(int k = maxk-1 ; k >= 0 ; k --)
		if(depth[fa[a][k]] >= depth[b])
			a = fa[a][k];
	
	if(a == b)
		return a;
	
	for(int k = maxk-1 ; k >= 0 ; k --)
		if(fa[a][k] != fa[b][k])
		{
			a = fa[a][k];
			b = fa[b][k];
		}
	return fa[a][0];
}

signed main()
{
	cin >> n >> m;
	memset(h, -1, sizeof h);
	for(int i = 1 ; i < n ; i ++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		addedge(a, b, c);
		addedge(b, a, c);
	}
	
	init();
	
	while(m --)
	{
		int a, b;
		cin >> a >> b;
		int lca = get_lca(a, b);
		
		cout << dist[a] + dist[b] - 2 * dist[lca] << endl;
	}
}