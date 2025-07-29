// Problem: P3379 【模板】最近公共祖先（LCA）
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3379
// Memory Limit: 512 MB
// Time Limit: 2000 ms

//AC on subtask#0
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
#define endl '\n'

int n, q;
int e[maxn], ne[maxn], h[maxn], idx;
int fa[maxn][16], depth[maxn];

void addedge(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void init(int root)
{
	memset(depth, 0x3f, sizeof depth);
	depth[0] = 0, depth[root] = 1;
	queue<int>q;
	q.push(root);
	
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
				fa[j][0] = t;
				for(int k = 1 ; k <= 15 ; k ++)
					fa[j][k] = fa[fa[j][k-1]][k-1];
			}
		}
	}
}

int lca(int a, int b)
{
	if(depth[b] > depth[a])
		swap(a, b);
	for(int k = 15 ; k >= 0 ; k --)
		if(depth[fa[a][k]] >= depth[b])
			a = fa[a][k];
	
	if(a == b) return a;
	
	for(int k = 15 ; k >= 0 ; k --)
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
	int root = 0;
	cin >> n >> q >> root;
	memset(h, -1, sizeof h);
	
	for(int i = 1 ; i < n ; i ++)
	{
		int a, b;
		cin >> a >> b;
		addedge(a, b), addedge(b, a);
	}
	
	init(root);
	while(q--)
	{
		int a, b;
		cin >> a >> b;
		cout << lca(a, b) << endl;

	}
}