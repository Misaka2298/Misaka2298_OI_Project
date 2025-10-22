// B
// expect pts = 100
// expect diff = orange

#include <bits/stdc++.h>
using namespace std;
const int maxn = 510;
typedef pair<int, int> PII;

int n, m, a, b;
int dist[maxn][maxn];
bool st[maxn][maxn];
queue<PII> q;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void bfs()
{
	while(q.size())
	{
		auto t = q.front(); q.pop();
		int x = t.first, y = t.second;
		for(int i = 0 ; i < 4 ; i ++)
		{
			int nx = x+dx[i], ny = y+dy[i];
			
			if(st[nx][ny])
				continue;
			st[nx][ny] = 1;
			if(nx < 1 || nx > n || ny < 1 || ny > m)
				continue;
			dist[nx][ny] = dist[x][y] + 1;
			q.push({nx, ny});
		}
		
	}
}

signed main()
{
	freopen("vguard.in", "r", stdin);
	freopen("vguard.out", "w", stdout);
	cin >> n >> m >> a >> b;
	for(int i = 1 ; i <= a ; i ++)
	{
		int x, y;
		cin >> x >> y;
		st[x][y] = 1;
		q.push({x, y});
	}
	bfs();
	
	while(b --)
	{
		int x, y;
		cin >> x >> y;
		cout << dist[x][y] << endl;
		
	}
	
	
}