// http://www.accoders.com/problem.php?cid=5132&pid=0
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;

int n, m;
int e[maxn], ne[maxn], h[maxn], w[maxn], idx;
int dist[maxn], cnt[maxn];
bool st[maxn];

void addedge(int a, int b, int c)
{
	e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

bool spfa()
{
	memset(dist, -0x3f, sizeof dist);
	memset(cnt, 0, sizeof cnt);
	dist[0] = 0;
	st[0] = 1;
	stack<int> q;
	q.push(0);
	
	while(q.size())
	{
		int t = q.top(); q.pop();
		st[t] = 0;
		for(int i = h[t] ; i != -1 ; i = ne[i])
		{
			int j = e[i];
			if(dist[j] < dist[t] + w[i])// longest road
			{
				dist[j] = dist[t] + w[i];
				cnt[j] ++;
				if(cnt[j] >= n+1) return false;
				if(!st[j])
				{
					q.push(j);
					st[j] = 1;
				}
			}
		}
	}
	return true;
}

signed main()
{
	cin >> n >> m;
	memset(h, -1, sizeof h);
	for(int i = 1 ; i <= m ; i ++)
	{
		int x, a, b;
		cin >> x >> a >> b;
		if(x == 1)
			addedge(b, a, 0), addedge(a, b, 0);
		if(x == 2)
			addedge(a, b, 1);
		if(x == 3)
			addedge(b, a, 0);
		if(x == 4)
			addedge(b, a, 1);
		if(x == 5)
			addedge(a, b, 0);
	}
	
	for(int i = 1 ; i <= n ; i ++)
		addedge(0, i, 1);
		
	if(!spfa())
		cout << -1;
	else
	{
		long long ans = 0;
		for(int i = 1 ; i <= n ; i ++)
			ans += dist[i];
		cout << ans;
	}
}