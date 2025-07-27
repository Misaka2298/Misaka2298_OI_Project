// Problem: T633435 「Cfz Round 6」Imaichi
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/T633435?contestId=255793
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Time: 2025-07-27 16:16:36
// expect pts = 

#include <bits/stdc++.h>
using namespace std;
const int manx = 1e3 + 10;
#define endl '\n'
typedef pair<int, int> PII;

int c, T;
int n, m, stamy, limit;
long long val[maxn][maxn], dist[maxn][maxn];
int deltax[] = {1, -1, 0};
int deltay[] = {0,  0, 1};

void bfs(int sta)
{
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= m ; j ++)
			dist[i][j] = -2e9;
	dist[sta] = stamy;
	queue<PII> q;
	q.push({1, sta});
	while(q.size())
	{
		auto t = q.front(); q.pop();
		for(int i = 0 ; i < 3 ; i ++)
		{
			int newx = t.first + deltax[i];
			int newy = t.second + deltay[i];
		}
		
	}
}

void init()
{
	for(int i = 0 ; i <= m ; i ++)
		val[0][i] = val[n+1][i] = -2e9; 
	for(int i = 0 ; i <= n ; i ++)
		val[i][0] = val[i][m+1] = -2e9;
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> c >> T;
	while(T--)
	{
		init();
		cin >> n >> m >> stamy >> limit;
		for(int i = 1 ; i <= n ; i ++)
			for(int j = 1 ; j <= m ; j ++)
				cin >> val[i][j];
		
		for(int i = 1 ; i <= n ; i ++)
		{
			bfs(i);
		}
	}
	return 0;
}