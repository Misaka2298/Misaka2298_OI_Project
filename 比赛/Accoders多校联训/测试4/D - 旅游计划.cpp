// T4
// expect pts = 100?

#include <bits/stdc++.h>
using namespace std;
const int maxn = 4010, maxm = 5010*2;
#define endl '\n'

int n, m;
int e[maxm], ne[maxm], h[maxm], idx;
int dist[maxn][maxn];
bool vis[maxn];

void addedge(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void bfs(int sta)
{
	dist[sta][sta] = 0;
	queue<int> q;
	q.push(sta);
	while(q.size())
	{
		int t = q.front(); q.pop();
		for(int i = h[t] ; i != -1 ; i = ne[i])
		{
			int j = e[i];
			if(dist[sta][j] > dist[sta][t] + 1)
			{
				dist[sta][j] = dist[sta][t] + 1;
				q.push(j);
			}
		}
	}
}


signed main()
{
	freopen("tour.in", "r", stdin);
	freopen("tour.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m;
	memset(dist, 0x3f, sizeof dist);
	memset(h, -1, sizeof h);
	for(int i = 0 ; i < m ; i ++)
	{
		int a, b;
		cin >> a >> b;
		addedge(a, b);
		addedge(b, a);
	}
	
	for(int i = 1 ; i <= n ; i ++)
		bfs(i);
	
	int sta = 0, ed = 0, cost = 0, sum = 0;
	for(int i = 1 ; i <= n ; i ++)
	{
		for(int j = 1 ; j <= n ; j++)
			if(dist[i][j] > cost)
				sta = i, ed = j, cost = dist[i][j];
	}
	vis[sta] = vis[ed] = 1;
	
	//cout << sta << ' ' << ed << endl;
	
	sum += cost;
	cost = 0;
	for(int k = 1 ; k <= 2 ; k ++)
	{
		int nowed = 0;
		for(int i = 1 ; i <= n ; i ++)
			if(dist[ed][i] > cost && !vis[i])
				cost = dist[ed][i], nowed = i;
		sum += cost;
		//cout << ed << ' ' << nowed << endl;
		ed = nowed;
		vis[ed] = 1;
	}
	cout << sum;
	
	/*
	for(int i = 1 ; i <= n ; i ++)
	{
		for(int j = 1 ; j <= n ; j ++)
			cout << dist[i][j] << ' ';
		cout << endl;
	}
	*/
}
