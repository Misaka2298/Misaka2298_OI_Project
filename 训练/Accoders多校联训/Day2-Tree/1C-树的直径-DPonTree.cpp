//Tree1-C-DPonTree
#include <bits/stdc++.h>
using namespace std;
const int maxn = 400010;

int n;
int e[maxn], ne[maxn], h[maxn], d1[maxn], d2[maxn], idx, dmax;
bool vis[maxn];

void addedge(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u)
{
	if(vis[u])
		return;
	vis[u] = true;
	d1[u] = d2[u] = 0;
	for(int i = h[u] ; i != -1 ; i = ne[i])
	{
		int j = e[i];
		if(!vis[j])
		{
			dfs(j);
			int t = d1[j] + 1;
			if(t > d1[u])
			{
				d2[u] = d1[u];
				d1[u] = t;
			}
			else if(t > d2[u])
			{
				d2[u] = t;
			}
		}
	}
	dmax = max(dmax, d1[u] + d2[u]);
}

signed main()
{
	cin >> n;
	memset(h, -1, sizeof h);
	for(int i = 1 ; i < n ; i ++)
	{
		int a, b;
		cin >> a >> b;
		addedge(a, b); addedge(b, a);
	}
	
	dfs(1);
	cout << dmax;
}