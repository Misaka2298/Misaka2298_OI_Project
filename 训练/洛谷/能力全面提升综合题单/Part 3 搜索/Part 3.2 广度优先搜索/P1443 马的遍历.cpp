#include <bits/stdc++.h>
using namespace std;
const int maxn = 410;
typedef pair<int, int> PII;

int dist[maxn][maxn];
int n, m, initx, inity;
int deltax[10] = {1, 2, -1, -2, 2, 1, -1, -2};
int deltay[10] = {2, 1, 2, 1, -1, -2, -2, -1};
bool isvis[maxn][maxn];

void bfs()
{
	queue<PII>q;
	memset(dist, 0x3f, sizeof dist);
	dist[initx][inity] = 0;
	isvis[initx][inity] = true;
	q.push({initx, inity});
	while(q.size())
	{
		auto t = q.front(); q.pop();
		int tx = t.first, ty = t.second;
		//cout << tx << ' ' << ty << endl;
		
		for(int i = 0 ; i < 8 ; i ++)
		{
			int xx = tx+deltax[i], yy = ty+deltay[i];
			if(xx < 1 || xx > n) continue;
			if(yy < 1 || yy > m) continue;
			if(isvis[xx][yy]) continue;
			
			isvis[xx][yy] = true;
			if(dist[xx][yy] > dist[tx][ty] + 1)
				dist[xx][yy] = dist[tx][ty] + 1;
			q.push({xx, yy});
		}
	}
}

signed main()
{
	cin >> n >> m >> initx >> inity;
	bfs();
	
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= m ; j ++)
			if(!isvis[i][j])
				dist[i][j] = -1;
	
	
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 1 ; j <= m ; j++)
			cout << dist[i][j] << "    ";
		cout << endl;
	}
}