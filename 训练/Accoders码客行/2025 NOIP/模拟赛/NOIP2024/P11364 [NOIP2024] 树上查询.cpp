// Problem: P11364 [NOIP2024] 树上查询
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P11364?contestId=217331
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// Time: 2025-11-18 16:30:46

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+20, maxk = 21;

int n, m;
int e[maxn], ne[maxn], h[maxn], idx;
int depth[maxn], fa[maxn][maxk+1];

void addedge(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void init()
{
	queue<int> q;
	q.push(1);
	depth[0] = 0, depth[1] = 1;
	
	while(q.size())
	{
		int t = q.front(); q.pop();
		for(int i = h[t] ; i != -1 ; i = ne[i])
		{
			int j = e[i];
			
			if(depth[j])
				continue;
			q.push(j);
			depth[j] = depth[t] + 1;
			fa[j][0] = t;
			for(int k = 1 ; k < maxk ; k ++)
				fa[j][k] = fa[fa[j][k-1]][k-1];
			
		}
	}
}

int getlca(int a, int b)
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
	memset(h, -1, sizeof h);
	cin >> n;
	for(int i = 1 ; i < n ; i ++)
	{
		int a, b;
		cin >> a >> b;
		addedge(a, b);
		addedge(b, a);
	}
	init();
	
	depth[1000010] = 2e9;
	cin >> m;
	while(m --)
	{
		int l, r, len, ans = 0;
		cin >> l >> r >> len;
		for(int i = l ; i+len-1 <= r ; i ++)
		{
			int dmn = 1000010, dmx = 0;
			for(int j = i ; j <= i+len-1 ; j ++)
				if(depth[dmn] > depth[j])
					dmn = j;
				
			for(int j = i ; j <= i+len-1 ; j ++)
				if(depth[dmx] < depth[j] && (len == 1 || dmn != j))
					dmx = j;
			int lca = getlca(dmn, dmx);
			if(depth[lca] > ans)
			{
				ans = depth[lca];
				//cout << dmn << ' ' << dmx << ' ' << ans << endl;
			}
			
		}
		cout << ans << endl;
	}
}