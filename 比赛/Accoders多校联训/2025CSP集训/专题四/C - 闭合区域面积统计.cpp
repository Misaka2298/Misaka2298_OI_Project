// C
// expect pts = 100
// expect diff = yellow-

#include <bits/stdc++.h>
using namespace std;
const int maxn = 15;
typedef pair<int, int> PII;

int n = 10, m = 10;
int g[maxn][maxn];
int sz[maxn], idx;
int id[maxn][maxn];

int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

bool isntans[maxn];

void bfs(int u, int stax, int stay)
{
	queue<PII> q;
	q.push({stax, stay});
	id[stax][stay] = u;
	sz[u] ++;
	
	while(q.size())
	{
		auto t = q.front(); q.pop();
		int x = t.first, y = t.second;
		
		for(int i = 0 ; i < 4 ; i ++)
		{
			int nx = x+dx[i], ny = y+dy[i];
			if(id[nx][ny] || nx < 0 || nx > n+1 || ny < 0 || ny > m+1 || g[nx][ny])
				continue;
			id[nx][ny] = id[x][y];
			sz[u] ++;
			q.push({nx, ny});
		}
	}
}

signed main()
{
	freopen("area.in", "r", stdin);
	freopen("area.out", "w", stdout);
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= m ; j ++)
			cin >> g[i][j];
	
	bfs(++idx, 0, 0);
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= m ; j ++)
			if(!id[i][j] && !g[i][j])
				bfs(++idx, i, j);
	
	for(int i = 1 ; i <= idx ; i ++)
		if(!isntans[i])
		{
			cout << sz[i];
			break;
		}
	
	
}