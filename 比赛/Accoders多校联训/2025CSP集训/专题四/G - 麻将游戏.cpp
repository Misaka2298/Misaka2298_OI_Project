// G
// expect pts = 
// expect diff = 

#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
typedef pair<int, pair<int, int>> PIII;

int n, m;
char g[maxn][maxn];

int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

int dist[maxn][maxn];
bool st[maxn][maxn];

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

int bfs(int stax, int stay, int endx, int endy)
{
	//cout << stax << ' ' << stay << endl;
	queue<PIII> q;
	q.push({stax, {stay, 0}});
	memset(st, 0, sizeof st);
	memset(dist, 0, sizeof dist);
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
			
			if(nx < 0 || nx > n+1 || ny < 0 || ny > m+1)
				continue;
			if(st[nx][ny] || (g[nx][ny] == 'X' && (nx != endx || ny != endy)))
				continue;
			st[nx][ny] = 1;
			
			dist[nx][ny] = dist[x][y] + dis;
			q.push({nx, {ny, ns}});
			
			//cout << s << ' ' << nx << ' ' << ny << ' ' << ns << ' ' << dist[nx][ny] << endl;
		}
	}
	
	if(!st[endx][endy])
		return 0;
	return dist[endx][endy]+1;
}

signed main()
{
	freopen("mjong.in", "r", stdin);
	freopen("mjong.out", "w", stdout);
	cin >> m >> n;
	string str;
	getline(cin, str);
	for(int i = 1 ; i <= n ; i ++)
	{
		getline(cin, str);
		
		for(int j = 0 ; j < str.size() ; j ++)
		{
			if(str[j] == ' ')
				g[i][j+1] = 'O';
			else
				g[i][j+1] = str[j];
		}
	}
	
	while(true)
	{
		int x, y, nx, ny;
		cin >> x >> y >> nx >> ny;
		if(x == 0 && y == 0 && nx == 0 && ny == 0)
			break;
		cout << bfs(y, x, ny, nx) << endl;
		//cout << bfs(x, y, nx, ny) << endl;
	}
}