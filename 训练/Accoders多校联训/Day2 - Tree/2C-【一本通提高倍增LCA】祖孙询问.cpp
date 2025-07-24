// Tree2-C
// Problem: 祖孙询问
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1174/
// Memory Limit: 64 MB
// Time Limit: 1000 ms

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
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
	cin >> n;
	int root = 0;
	memset(h, -1, sizeof h);
	
	for(int i = 0 ; i < n ; i ++)
	{
		int a, b;
		cin >> a >> b;
		if(b == -1) root = a;
		else addedge(a, b), addedge(b, a);
	}
	
	init(root);
	
	cin >> q;
	while(q--)
	{
		int a, b;
		cin >> a >> b;
		int lcap = lca(a, b);
		if(lcap == a)
			cout << 1 << endl;
		else if(lcap == b)
			cout << 2 << endl;
		else
			cout << 0 << endl;
	}
}