// Problem: P8817 [CSP-S 2022] 假期计划
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P8817?contestId=90216
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Time: 2025-11-20 08:20:41

// expect pts = 40;

#include <bits/stdc++.h>
using namespace std;
const int maxn = 310;
typedef long long LL;

int n, m, k;
int dist[maxn][maxn];
LL w[maxn];
bool st[maxn];
LL ans = 0;

void floyd()
{
	for(int kk = 1 ; kk <= n ; kk ++)
		for(int i = 1 ; i <= n ; i ++)
			for(int j = 1 ; j <= n ; j ++)
				dist[i][j] = min(dist[i][j], dist[i][kk] + dist[kk][j]);
}

void init()
{
	cin >> n >> m >> k;
	w[1] = 0;
	for(int i = 2 ; i <= n ; i ++)
		cin >> w[i];
	
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= n ; j ++)
			if(i != j)
				dist[i][j] = 0x3f3f3f3f;
	
	for(int i = 1 ; i <= m ; i ++)
	{
		int a, b;
		cin >> a >> b;
		dist[a][b] = dist[b][a] = 1;
	}
	
	floyd();
	
	
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= n ; j ++)
			dist[i][j] = max(0, dist[i][j] - 1);
	
}

bool check(string road, int u)
{
	for(int i = 0 ; i < road.size() ; i ++)
		if(u == road[i]-'0')
			return false;
	return true;
}

void dfs(int u, int sta, LL sum, string road)
{
	if(u > 4)
	{
		if(road[road.size()-1] == '1')
			return;
		/*
		if(dist[sta][1] <= k)
			cout << road << ' ' << sum << endl;
		*/
		if(dist[sta][1] <= k)
			ans = max(ans, sum);
		return ;
	}
	
	for(int i = 1 ; i <= n ; i ++)
		if(dist[sta][i] <= k && !st[i])// check(road, i))
		{
			st[i] = 1;
			dfs(u+1, i, sum+w[i], road+to_string(i));
			st[i] = 0;
		}
			
}

void solve()
{
	st[1] = 1;
	dfs(1, 1, 0, "");
	
	cout << ans;
}

signed main()
{
	init();
	//cout << dist[1][5] << endl;
	
	solve();
}