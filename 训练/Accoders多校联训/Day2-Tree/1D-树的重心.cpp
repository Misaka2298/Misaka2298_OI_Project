//Tree1-D
#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5+10;

int n;
int e[maxn], ne[maxn], h[maxn], idx;
int w[maxn], sz[maxn], ans[2], res=0x3f3f3f3f;
bool st[maxn];

void addedge(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void solve(int u)
{
	if(st[u])
		return;
	st[u] = true;
	sz[u] = 1; w[u] = 0;
	
	for(int i = h[u] ; i != -1 ; i = ne[i])
	{
		int j = e[i];
		if(!st[j])
		{
			solve(j);
			sz[u] += sz[j];
			w[u] = max(w[u], sz[j]);
		}
	}
	w[u] = max(w[u], n-sz[u]);
	
	if(w[u] < res)
	{
		res = w[u];
		ans[0] = u;
		ans[1] = 0;
	}
	else if(w[u] == res)
	{
		if(!ans[1] || u < ans[0])
		{
			ans[1] = ans[0];
			ans[0] = u;
		}
		else if(!ans[1] || u < ans[1])
		{
			ans[1] = u;
		}
	}
}

signed main()
{
	memset(h, -1, sizeof h);
	cin >> n;
	for(int i = 1 ; i < n ; i ++)
	{
		int a, b;
		cin >> a >> b;
		addedge(a, b); addedge(b, a);
	}
	
	solve(1);
	
	cout << ans[0] << ' ' << res;
}