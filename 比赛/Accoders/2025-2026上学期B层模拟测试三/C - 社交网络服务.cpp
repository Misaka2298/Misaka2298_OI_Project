// C - bf
// expect pts = 40
// expect diff = idk

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+10, maxm = 4e5+10;

int n, m;
int e[maxm], ne[maxm], h[maxn], idx;
int dist[maxn][maxn];
bool st[maxn];
int ans;

void addedge(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void fileio()
{
	freopen("sns.in", "r", stdin);
	freopen("sns.out", "w", stdout);
}

void init()
{
	fileio();
	cin >> n >> m;
	memset(h, -1, sizeof h);
	
	for(int i = 1 ; i <= m ; i ++)
	{
		int a, b;
		cin >> a >> b;
		addedge(a, b);
		addedge(b, a);
	}
}

void sol_dist(int sta)//bfs
{
	queue<int> q;
	q.push(sta);
	memset(st, 0, sizeof st);
	st[sta] = 1;
	for(int i = 1 ; i <= n ; i ++)
		dist[sta][i] = 0;
	
	while(q.size())
	{
		int t = q.front(); q.pop();
		for(int i = h[t] ; i != -1 ; i = ne[i])
		{
			int j = e[i];
			if(st[j])
				continue;
			q.push(j);
			st[j] = 1;
			dist[sta][j] = dist[sta][t] + 1;
		}
	}
}

bool is_haveans(int u)
{
	for(int i = 1 ; i <= n ; i ++)
		if(dist[u][i] == 2)
			return true;
	return false;
}

void solve_node(int u)
{
	sol_dist(u);
	while(is_haveans(u))
	{
		for(int i = 1 ; i <= n ; i ++)
			if(dist[u][i] == 2)
			{
				addedge(u, i);
				addedge(i, u);
				ans ++;
			}
		sol_dist(u);
	}
}

void solve()
{
	for(int i = 1 ; i <= n ; i ++)
		solve_node(i);
	cout << ans << endl;
}

signed main()
{
	init();
	
	solve();
}