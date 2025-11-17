// Problem: P13096 [FJCPC 2025] 难以控制的滑板火箭
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P13096
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// Time: 2025-11-11 19:55:09

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010, inf = 0x3f3f3f3f;

int T;
int n, m;
int l, r;
bool g[maxn][maxn];
int dist[maxn][maxn][2];
bool st[maxn][maxn][2];
struct Node{
	int x, y, s;
};
int dx[] = {0, 1, 0, -1, 1, -1, -1, 1};
int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};

void bfs(int sta)
{
	queue<Node> q;
	q.push({1, 1, sta});
	dist[1][1][sta] = 0;
	st[1][1][sta] = 1;
	
	while(q.size())
	{
		Node t = q.front(); q.pop();
		int x = t.x, y = t.y, s = t.s;
		
		for(int i = 0 ; i < 8 ; i ++)
		{
			int nx = x + dx[i], ny = y + dy[i], ns = s ^ 1;
			if(nx < 1 || nx > n || ny < 1 || ny > m)
				continue;
			if(!g[nx][ny] || st[nx][ny][ns])
				continue;
			
			st[nx][ny][ns] = 1;
			dist[nx][ny][ns] = min(dist[nx][ny][ns], dist[x][y][s] + 1);
			q.push({nx, ny, ns});
		}
	}
	
}

void init(int a, int b)
{
	for(int i = 1 ; i <= a ; i ++)
		for(int j = 1 ; j <= b ; j ++)
			g[i][j] = st[i][j][0] = st[i][j][1] = 0, dist[i][j][0] = dist[i][j][1] = inf;
}

signed main()
{
	cin >> T;
	while(T --)
	{
		cin >> n >> m >> l >> r;
		init(n, m);
		for(int i = 1 ; i <= n ; i ++)
		{
			string str;
			cin >> str;
			for(int j = 1 ; j <= str.size() ; j ++)
				if(str[j-1] == '1')
					g[i][j] = 1;
		}
		
		//bfs(1);// e
		bfs(0);// o
		
		
		int dis;
		if(dist[n][m][0] == inf && dist[n][m][1] == inf)
		{
			cout << -1 << endl;
			continue;
		}
		if(dist[n][m][0] == inf)
			dis = dist[n][m][1];
		else if(dist[n][m][1] == inf)
			dis = dist[n][m][0];
		else
			dis = min(dist[n][m][1], dist[n][m][0]);
		//cout << dis << endl;
		
		if(l != r)
			cout << (dis-1) / r + 1 << endl; 			
		else
		{
			if(l%2 != 0)
			{
				int anse = (dist[n][m][1]-1) / r + 1;
				if(anse%2 == 0)
					anse ++;
				int anso = (dist[n][m][0]-1) / r + 1;
				if(anso%2 != 0)
					anso ++;
				cout << min(anse, anso) << endl;
			} 
			else
			{
				if(dist[n][m][0] == inf)
					cout << -1 << endl;
				else
					cout << (dist[n][m][0] - 1) / r + 1 << endl;
					
			}
			//cout << ans << endl;
		}
		//cout << endl;
		
	}
}