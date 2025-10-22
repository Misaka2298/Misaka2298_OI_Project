// E
// expect pts = 100
// expect diff = yellow

#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
typedef pair<int, pair<int, int>> PIII;

int n, m;
int g[maxn][maxn], dist[maxn][maxn];
bool st[maxn][maxn];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int getdis(int s, int x, int y, int &ns)
{
	if(x == -1 && y == 0)
		ns = 1;
	if(x == 0 && y == 1)
		ns = 2;
	if(x == 1 && y == 0)
		ns = 3;
	if(x == 0 && y == -1)
		ns = 4;
	
	if(s == 0)
		return 0;
	if(s == 1)
	{
		if(x == -1 && y == 0)
			return 0;
		if(x == 0 && y == -1)
			return 1;
		if(x == 0 && y == 1)
			return 1;
			
		return 2;
	}
	if(s == 2)
	{
		if(x == 0 && y == 1)
			return 0;
		if(x == -1 && y == 0)
			return 1;
		if(x == 1 && y == 0)
			return 1;
			
		return 2;
	}
	if(s == 3)
	{
		if(x == 1 && y == 0)
			return 0;
		if(x == 0 && y == 1)
			return 1;
		if(x == 0 && y == -1)
			return 1;
		return 2;
	}
	if(s == 4)
	{
		if(x == 0 && y == -1)
			return 0;
		if(x == -1 && y == 0)
			return 1;
		if(x == 1 && y == 0)
			return 1;
		return 2;
	}
}

void bfs(int stax, int stay)
{
	queue<PIII> q;
	q.push({stax, {stay, 0}});
	st[stax][stay] = 1;
	
	while(q.size())
	{
		auto t = q.front(); q.pop();
		int x = t.first, y = t.second.first, s = t.second.second;
		
		for(int i = 0 ; i < 4 ; i ++)
		{
			int nx = x+dx[i], ny = y+dy[i];
			int ns = 0;
			int dis = getdis(s, dx[i], dy[i], ns);
			
			if(nx < 1 || nx > n || ny < 1 || ny > m || g[nx][ny])
				continue;
			if(st[nx][ny])
				continue;
			st[nx][ny] = 1;
			
			dist[nx][ny] = dist[x][y] + dis;
			q.push({nx, {ny, ns}});
			
			//cout << s << ' ' << nx << ' ' << ny << ' ' << ns << ' ' << dist[nx][ny] << endl;
		}
	}
}

signed main()
{
	freopen("turn.in", "r", stdin);
	freopen("turn.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= m ; j ++)
			cin >> g[i][j];
	
	int stax, stay, endx, endy;
	cin >> stax >> stay >> endx >> endy;
	
	bfs(stax, stay);
	
	cout << dist[endx][endy];
}