// Problem: P4281 [AHOI2008] 紧急集合 / 聚会
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4281
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// Time: 2025-07-22 15:34:25

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10, maxk = 18;
#define endl '\n'

int n, q;
int e[maxn], ne[maxn], h[maxn], idx, root = 1;
int fa[maxn][maxk+1], depth[maxn];

void addedge(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void init()
{
	memset(depth, 0x3f, sizeof depth);
	depth[0] = 0, depth[root] = 1;
	queue<int> q;
	q.push(root);
	
	while(!q.empty())
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

int getdist(int a, int b, int c)
{
	return depth[a] + depth[b] - 2*depth[c];
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> q;
	memset(h, -1, sizeof h);
	for(int i = 1 ; i < n ; i ++)
	{
		int a, b;
		cin >> a >> b;
		addedge(a, b);
		addedge(b, a);
	}
	
	init();
	
	while(q--)
	{
		int a, b, c, dist = 0;
		cin >> a >> b >> c;
		int pab = lca(a, b), pbc = lca(b, c), pac = lca(a, c);
		if(pab == pbc)
		{
			dist = getdist(a,pac,lca(a,pac))+getdist(b,pac,lca(b,pac))+getdist(c,pac,lca(c,pac));
			cout << pac << ' ' << dist << endl;
		}
		else if(pab == pac)
		{
			dist = getdist(a,pbc,lca(a,pbc))+getdist(b,pbc,lca(b,pbc))+getdist(c,pbc,lca(c,pbc));
			cout << pbc << ' ' << dist << endl;
		}
		else
		{
			dist = getdist(a,pab,lca(a,pab))+getdist(b,pab,lca(b,pab))+getdist(c,pab,lca(c,pab));
			cout << pab << ' ' << dist << endl;
		}
	}
	
}