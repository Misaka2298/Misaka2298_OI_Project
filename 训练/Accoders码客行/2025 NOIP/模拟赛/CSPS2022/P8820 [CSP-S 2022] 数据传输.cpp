// Problem: P8820 [CSP-S 2022] 数据传输
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P8820?contestId=90216
// Memory Limit: 1024 MB
// Time Limit: 3000 ms
// Time: 2025-11-20 10:38:50

#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5+10, maxk = 18;
typedef long long LL;

int n, Q, k;
int e[maxn], ne[maxn], h[maxn], idx;
LL w[maxn];
int depth[maxn], fa[maxn][maxk];
bool st[maxn];
LL ans = 1e18+10;

void addedge(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void build()
{
	queue<int> q;
	q.push(1);
	depth[0] = 0, depth[1] = 1;
	st[1] = 1;
	
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
			fa[j][0] = t;
			for(int kk = 1 ; kk < maxk ; kk ++)
				fa[j][kk] = fa[fa[j][kk-1]][kk-1];
		}
	}
}

int getlca(int a, int b)
{
	if(depth[b] > depth[a])
		swap(a, b);
		
	for(int kk = maxk-1 ; kk >= 0 ; kk --)
		if(depth[fa[a][kk]] >= depth[b])
			a = fa[a][kk];
	
	if(a == b)
		return a;
	
	for(int kk = maxk-1 ; kk >= 0 ; kk --)
		if(fa[a][kk] != fa[b][kk])
		{
			a = fa[a][kk];
			b = fa[b][kk];
		}
}

void init()
{
	memset(h, -1, sizeof h);
	cin >> n >> Q >> k;
	for(int i = 1 ; i <= n ; i ++)
		cin >> w[i];
	for(int i = 1 ; i < n ; i ++)
	{
		int a, b;
		cin >> a >> b;
		addedge(a, b);
		addedge(b, a);
	}
	build();
	memset(st, 0, sizeof st);//复用
}

int getdist(int a, int b)
{
	int lca = getlca(a, b);
	return depth[a] + depth[b] - 2 * depth[lca];
}

void dfs(int sta, int ed, LL sum, string road)
{
	//cout << sta << endl;
	if(sum > ans)
		return ;//cut;
	if(sta == ed)
	{
		//cout << road << ' ' << sum << endl;
		ans = min(ans, sum);
		return ;
	}
	
	for(int i = 1 ; i <= n ; i ++)
	{
		if(i == sta || st[i])
			continue;
		if(getdist(sta, i) > k)
			continue;
		
		st[i] = 1;
		dfs(i, ed, sum+w[i], road+to_string(i));
		st[i] = 0;
	}
}

void solve()
{
	for(int q = 1 ; q <= Q ; q ++)
	{
		int sta, ed;
		cin >> sta >> ed;
		ans = 1e18+10;
		memset(st, 0, sizeof st);
		st[sta] = 1;
		dfs(sta, ed, w[sta], "");
		
		cout << ans << endl;
	}
}

signed main()
{
	init();
	solve();
}