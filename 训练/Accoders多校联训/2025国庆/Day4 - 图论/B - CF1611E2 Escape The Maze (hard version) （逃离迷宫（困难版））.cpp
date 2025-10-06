// Problem: CF1611E2 Escape The Maze (hard version) （逃离迷宫（困难版））
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1611E2
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// Time: 2025-10-05 19:00:28

#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5+10;
#define endl '\n'

int T, n, m;
int e[maxn], ne[maxn], h[maxn], idx;
int de[maxn], dep[maxn];
queue<int> q;

void init()
{
	idx = 0;
	//memset(e, 0, sizeof e);
	memset(h, 0, sizeof h);
	//memset(ne, 0, sizeof ne);
	memset(de, -1, sizeof de);
	memset(dep, -1, sizeof dep);
}

void addedge(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void bfs(int opt)
{
	while(q.size())
	{
		int t = q.front(); q.pop();
		for(int i = h[t] ; i != -1 ; i = ne[i])
		{
			int j = e[i];
			if(opt == 1) 
			{
				if(de[j] >= 0) continue;
				de[j] = de[t] + 1;
			}
			else
			{
				if(dep[j] >= 0) continue;
				dep[j] = dep[t] + 1;
			}
			q.push(j);
		}
	}
}

int dfs(int u = 1, int fa = -1)
{
	if(de[u] <= dep[u])
		return 1;
	
	bool can = 1;
	int need = 0;
	
	for(int i = h[u] ; i != -1 ; i = ne[i])
	{
		int j = e[i];
		if(j == fa)
			continue;
		int innerneed = dfs(j, u);
		if(innerneed < 0)
			can = 0;
		need += innerneed;
	}
	
	if(!need || !can)
		return -1;
	return need;
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> T;
	while(T --)
	{
		init();
		
		memset(h, -1, sizeof h);
		cin >> n >> m;
		
		for(int i = 1 ; i <= m ; i ++)
		{
			int a;
			cin >> a;
			de[a] = 0;
			q.push(a);
		}
		
		for(int i = 1 ; i < n ; i ++)
		{
			int a, b;
			cin >> a >> b;
			addedge(a, b);
			addedge(b, a);
		}
		
		bfs(1);
		
		dep[1] = 0;
		q.push(1);
		bfs(0);
		
		cout << dfs() << endl;
	}
}