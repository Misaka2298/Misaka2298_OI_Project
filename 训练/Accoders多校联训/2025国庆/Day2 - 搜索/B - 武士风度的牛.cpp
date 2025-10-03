// B

#include <bits/stdc++.h>
using namespace std;
const int maxn = 200;
typedef pair<int, int> PII;

int n, m;
char g[maxn][maxn];
bool st[maxn][maxn];
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int stax, stay, endx, endy;
int dist[maxn][maxn];

void bfs()
{
	queue<PII> q;
	q.push({stax, stay});
	st[stax][stay] = 1;
	
	while(q.size())
	{
		auto t = q.front(); q.pop();
		int x = t.first, y = t.second;
		for(int i = 0 ; i < 8 ; i ++)
		{
			int nx = x+dx[i], ny = y+dy[i];
			if(nx < 1 || nx > n || ny < 1 || ny > m)
				continue;
			if(st[nx][ny] || g[nx][ny] == '*')
				continue;
			
			st[nx][ny] = 1;
			dist[nx][ny] = dist[x][y] + 1;
			q.push({nx, ny});
		}
	}
}

signed main()
{
	cin >> m >> n;
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= m ; j ++)
		{
			cin >> g[i][j];
			if(g[i][j] == 'K')
				stax = i, stay = j;
			if(g[i][j] == 'H')
				endx = i, endy = j;
		}
	
	bfs();
	cout << dist[endx][endy];
}