//T2
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+10;
typedef pair<int, int> PII;

int n, m, id, c, idx;
bool g[maxn][maxn], isopened[maxn][maxn], isnum[maxn][maxn], isbfsed[maxn][maxn];

int deltax[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int deltay[] = {0, 1, 1, 1, 0, -1, -1, -1};

void bfs(int x, int y)
{
	queue<PII>bfsq;
	while(!bfsq.empty()) bfsq.pop();//clear
	bfsq.push({x, y});
	isbfsed[x][y] = true;
	
	while(bfsq.size())
	{
		auto t = bfsq.front(); bfsq.pop();
		for(int i = 0 ; i < 8 ; i++)
		{
			int xx = t.first+deltax[i] , yy = t.second+deltay[i];
			if(xx>=1 && yy>=1 && xx<=n && yy<=m && !isnum[xx][yy] && !isbfsed[xx][yy] && !g[xx][yy])
			{
				isbfsed[xx][yy] = true;
				bfsq.push({xx,yy});
			}
		}
	}
	return;
}

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> id >> n >> m >> c;
	for(int i = 0 ; i <= n+1 ; i++)
		for(int j = 0 ; j <= m+1 ; j++)
			isnum[i][j] = true;
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= m ; j++)
			isnum[i][j] = false;
	

	for(int i = 0 ; i < c ; i ++)
	{
		int x, y;
		cin >> x >> y;
		g[x][y] = true;// isnum[x][y] = true; isopened[x][y] = true;
		for(int i = x-1 ; i <= x+1 ; i++)
			for(int j = y-1; j <= y+1 ; j++)
				if(!g[i][j])
					isnum[i][j] = true;
	}
	
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= m ; j ++)
		{
			if(!isnum[i][j] && !isbfsed[i][j] && !g[i][j])
			{
				//cout << i << ' ' << j << endl; //debug
				bfs(i, j);
				idx++;
			}
		}
		
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= m ; j++)
		{
			if(!isnum[i][j] && !g[i][j])
			{
				for(int ii = i-1 ; ii <= i+1 ; ii++)
					for(int jj = j-1 ; jj <= j+1 ; jj++)
						if(!g[i][j]) isopened[ii][jj] = true;
			}
		}
	
		
	
	int res = idx;
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= m ; j++)
			if(!g[i][j] && !isopened[i][j] && isnum[i][j])
				res++;
	cout << res;
}