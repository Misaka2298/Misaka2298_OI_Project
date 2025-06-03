#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;

int n, m, dist[maxn*3];
bool inq[maxn*3];
vector<pair<int, int>> g[maxn*3];

#define t(x, i) (x+i*n)

void addedge(int a, int b)
{
	g[t(a, 0)].push_back({t(b, 0), 0});
	g[t(a, 1)].push_back({t(b, 1), 0});
	g[t(a, 2)].push_back({t(b, 2), 0});
}

void spfa(int sta)
{
	for(int i = 1 ; i <= n*3 ; i ++)
		dist[i] = INT_MIN;
	queue<int> q;
	q.push(sta);
	inq[sta] = true;
	dist[sta] = 0;
	
	while(q.size())
	{
		int x = q.front(); q.pop();
		inq[x] = false;
		for(auto [v, len] : g[x])
			if(dist[v] < dist[x] + len)
			{
				dist[v] = dist[x] + len;
				if(!inq[v]) inq[v] = true, q.push(v);
			}
	}
}

signed main()
{
	cin >> n >> m;
	for(int i = 1; i <= n ; i ++)
	{
		int v;
		cin >> v;
		g[t(i, 0)].push_back({t(i, 1), -v});
		g[t(i, 1)].push_back({t(i, 2), v});
	}
	
	for(int i = 0 ; i < m ; i ++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		addedge(a, b);
		if(c == 2) addedge(b, a);
	}
	
	spfa(t(1, 0));
	
	cout << dist[t(n, 2)];
}