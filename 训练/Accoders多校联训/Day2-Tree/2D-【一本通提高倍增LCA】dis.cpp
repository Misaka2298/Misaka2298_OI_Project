// Tree2-D
// Problem: U192488 最短距离
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/U192488
// Memory Limit: 128 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e4+10, maxk = 18;
#define endl '\n'

int n, q;
int e[maxn], ne[maxn], h[maxn], w[maxn], idx;
int depth[maxn], fa[maxn][maxk+1], dist[maxn];

void addedge(int a, int b, int c)
{
	e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

void init()
{
	memset(depth, 0x3f, sizeof depth);
	memset(dist, 0x3f, sizeof dist);
	depth[0] = 0, depth[1] = 1;
	dist[1] = 0;
	
	queue<int> q; 
	q.push(1);
	while(q.size())
	{
		int t = q.front(); q.pop();
		for(int i = h[t] ; i != -1 ; i = ne[i])
		{
			int j = e[i];
			if(depth[j] > depth[t] + 1)
			{
				depth[j] = depth[t] + 1;
				q.push(j);
				dist[j] = dist[t] + w[i];
				fa[j][0] = t;
				for(int k = 1 ; k < maxk ; k ++)
					fa[j][k] = fa[fa[j][k-1]][k-1];
			}
		}
	}
}

int lca(int a, int b)
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
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> q;
	memset(h, -1, sizeof h);
	for(int i = 1 ; i < n ; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		addedge(a, b, c);
		addedge(b, a, c);
	}
	
	init();
	
	while(q--)
	{
		int a, b;
		cin >> a >> b;
		int p = lca(a, b);
		
		cout << dist[a] + dist[b] - 2*dist[p] << endl;
	}
}