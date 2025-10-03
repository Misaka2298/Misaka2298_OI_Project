// A
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+10;
typedef pair<int, int> PII;

int n, m;
bool g[maxn][maxn], st[maxn][maxn];
int dx[] = {1, -1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

void bfs(int stax, int stay)
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
			if(st[nx][ny] || !g[nx][ny])	
				continue;
			st[nx][ny] = 1;
			q.push({nx, ny});
		}
	}
}

signed main()
{
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= m ; j ++)
		{
			char chr;
			cin >> chr;
			if(chr == 'w') g[i][j] = 1;
		}

	int ans = 0;
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= m ; j ++)
			if(!st[i][j] && g[i][j])
				ans ++, bfs(i, j);
	cout << ans;
}