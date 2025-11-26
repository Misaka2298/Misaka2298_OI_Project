// Problem: T701837 【模板】负环
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/T701837?contestId=293606
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// Time: 2025-11-25 13:25:06

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;

int T;
int n, m;
int e[maxn], ne[maxn], h[maxn], w[maxn], idx;
int cnt[maxn], dist[maxn];
bool st[maxn];

void addedge(int a, int b, int c)
{
	e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
}

void init_clear()
{
	memset(e, 0, sizeof e);
	memset(ne, 0, sizeof ne);
	memset(h, -1, sizeof h);
	memset(cnt, 0, sizeof cnt);
	memset(dist, 0, sizeof dist);
	memset(w, 0, sizeof w);
	memset(st, 1, sizeof st);
	idx = 0;
}

void init()
{
	init_clear();
	cin >> n >> m;
	for(int i = 1 ; i <= m ; i ++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if(c >= 0)
		{
			addedge(a, b, c);
			addedge(b, a, c);
		}
		else
			addedge(a, b, c);
	}
}

bool check()//spfa
{
	queue<int> q;
	for(int i = 1 ; i <= n ; i ++)
		q.push(i);
	
	while(q.size())
	{
		int t = q.front(); q.pop();
		st[t] = 0;
		for(int i = h[t] ; i != -1 ; i = ne[i])
		{
			int j = e[i];
			if(dist[j] > dist[t] + w[i])
			{
				dist[j] = dist[t] + w[i];
				cnt[j] = cnt[t] + 1;
				if(cnt[j] >= n)
					return true;
				if(!st[j])
				{
					q.push(j);
					st[j] = 1;
				}
			}
		}
	}
	return false;
}

signed main()
{
	cin >> T;
	while(T --)
	{
		init();
		if(check())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}