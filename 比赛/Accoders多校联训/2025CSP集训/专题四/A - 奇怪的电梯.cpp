// A
// expect pts = 100
// expect diff = orange

#include <bits/stdc++.h>
using namespace std;
const int maxn = 210;

int n, a, b;
int delta[maxn], dist[maxn];
bool st[maxn];

void bfs()
{
	queue<int> q;
	q.push(a);
	//st[a] = 1;
	
	while(q.size())
	{
		int t = q.front(); q.pop();
		if(st[t + delta[t]])
			continue;
		st[t + delta[t]] = 1;
		if(t + delta[t] <= n)
		{
			dist[t+delta[t]] = dist[t] + 1;
			q.push(t+delta[t]);
		}
		
		if(st[t - delta[t]])
			continue;
		st[t - delta[t]] = 1;
		if(t - delta[t] >= 1)
		{
			dist[t-delta[t]] = dist[t] + 1;
			q.push(t-delta[t]);
		}
	}
}

signed main()
{
	freopen("lift.in", "r", stdin);
	freopen("lift.out", "w", stdout);
	cin >> n >> a >> b;
	if(a == b)
	{
		cout << 2;
		exit(0);
	}
	for(int i = 1 ; i <= n ; i ++)
		cin >> delta[i];
	
	bfs();
	
	if(st[b])cout << dist[b];
	else cout << -1;
	
	
}