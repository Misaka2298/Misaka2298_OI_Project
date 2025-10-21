// C
// expect pts = 100
// expect diff = orange

#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
const int maxn = 12;

int n, m, k;
bool g[maxn][maxn][maxn], st[maxn][maxn][maxn];

int dx[] = {1, 0, -1, 0, 0, 0};
int dy[] = {0, 1, 0, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

int bfs(int stax, int stay)
{
	int ans = 0;
	queue<pair<int,pair<int, int>>> q;
	q.push({stax, {stay, 1}});
	st[stax][stay][1] = 1;
	ans ++;
	
	while(q.size())
	{
		auto t = q.front();
		q.pop();
		int x = t.first, y = t.second.first, z = t.second.second;
		for(int i = 0 ; i < 6 ; i ++)
		{
			int nx = x+dx[i], ny = y+dy[i], nz = z+dz[i];
			if(st[nx][ny][nz] || !g[nx][ny][nz])
				continue;
			if(nx < 1 || nx > n || ny < 1 || ny > m || nz < 1 || nz > k)
				continue;
			
			st[nx][ny][nz] = 1;
			ans ++;
			q.push({nx, {ny, nz}});
		}
	}
	return ans;
}

signed main()
{
	freopen("congrid.in", "r", stdin);
	freopen("congrid.out", "w", stdout);
	cin >> k >> n >> m;
	char chr;
	for(int z = 1 ; z <= k ; z ++)
		for(int x = 1 ; x <= n ; x ++)
			for(int y = 1 ; y <= m ; y ++)
				cin >> chr, g[x][y][z] = (chr == '.');
		
	int stax, stay;
	cin >> stax >> stay;
	cout << bfs(stax, stay);
			
			
}