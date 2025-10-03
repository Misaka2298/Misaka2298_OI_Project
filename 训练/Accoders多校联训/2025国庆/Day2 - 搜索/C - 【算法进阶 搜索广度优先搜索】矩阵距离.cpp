// C
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
typedef pair<int, int> PII;

int n, m;
int g[maxn][maxn], dist[maxn][maxn];
bool st[maxn][maxn];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
queue<PII> q;

void bfs()
{
	//memset(dist, 0, sizeof dist);
	while(q.size())
	{
		auto t = q.front(); q.pop();
		int x = t.first, y = t.second;
		for(int i = 0 ; i < 4 ; i ++)
		{
			int nx = x + dx[i], ny = y + dy[i];
			if(nx < 1 || nx > n || ny < 1 || ny > m)
				continue;
			if(st[nx][ny])
				continue;
			
			dist[nx][ny] = dist[x][y] + 1;
			//if(g[nx][ny])
				//return dist[nx][ny];
			st[nx][ny] = 1;
			q.push({nx, ny});
		}
	}
}

signed main()
{
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++)
	{
		string str;
		cin >> str;
		for(int j = 0 ; j < str.length() ; j ++)
			g[i][j+1] = str[j] - '0';
	}
	
	for(int i = 1 ; i <= n ; i ++)
	{
		for(int j = 1 ; j <= m ; j ++)
			if(g[i][j] == 1)
				q.push({i, j}), st[i][j] = 1;
	}
	
	bfs();
	
	for(int i = 1 ; i <= n ; i ++)
	{
		for(int j = 1 ; j <= m ; j ++)
			cout << dist[i][j] << ' ';
		cout << endl;
	}
		

		
}