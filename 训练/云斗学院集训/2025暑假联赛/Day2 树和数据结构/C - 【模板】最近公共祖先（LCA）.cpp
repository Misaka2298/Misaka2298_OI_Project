// Problem: 【模板】最近公共祖先（LCA）
// Contest: 云斗学院
// URL: https://www.yundouxueyuan.com/d/jinan202507/p/P3379?tid=688f49e85b065a22f7446c06
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Time: 2025-08-04 07:59:22
// expect pts = 

#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e6+10, maxk = 19;

int n, m;
int e[maxn], ne[maxn], h[maxn], idx;
int fa[maxn][maxk+1], depth[maxn];

void addedge(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void init(int root)
{
	queue<int>q;
	memset(depth, 0x3f, sizeof depth);
	q.push(root);
	depth[0] = 0, depth[root] = 1;
	
	while(q.size())
	{
		int t = q.front(); q.pop();
		for(int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			if(depth[j] > depth[t] + 1)
			{
				depth[j] = depth[t] + 1;
				q.push(j);
				fa[j][0] = t;
				for(int k = 1; k < maxk; k ++)
					fa[j][k] = fa[fa[j][k-1]][k-1];
			}
		}
	}
}

int lca(int a, int b)
{
	if(depth[b] > depth[a])
		swap(a, b);
	for(int k = maxk; k >= 0; k --)
		if(depth[fa[a][k]] >= depth[b])
			a = fa[a][k];
	if(a == b)
		return a;
	for(int k = maxk; k >= 0; k --)
		if(fa[a][k] != fa[b][k])
		{
			a = fa[a][k];
			b = fa[b][k];
		}
	return fa[a][0];
}

signed main()
{
	int root;
	cin >> n >> m >> root;
	memset(h, -1, sizeof h);
	for(int i = 1 ; i < n ; i ++)
	{
		int a, b;
		cin >> a >> b;
		addedge(a, b), addedge(b, a);
	}
	
	init(root);
	
	while(m--)
	{
		int a, b;
		cin >> a >> b;
		cout << lca(a, b) << endl;
	}
}