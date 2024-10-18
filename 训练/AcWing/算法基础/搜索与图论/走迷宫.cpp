#include <bits/stdc++.h>
using namespace std;

const int maxn = 100;
typedef pair<int,int> PII;

int n , m ;
int dist[maxn][maxn],g[maxn][maxn];//g是图
PII q[maxn*maxn];

int bfs()
{
	int hh = 0 , tt = 0 ;
	q[0]={0,0};
	
	memset(dist,-1,sizeof dist);
	dist[0][0]=0;
	
	int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
	
	while(hh <= tt)
	{
		auto t = q[hh++];
		for(int i = 0 ;i < 4 ; i++)
		{
			int x=t.first+dx[i] , y=t.second+dy[i];
			if(x>=0 && y>=0 && x<n && y<m && g[x][y]==0 && dist[x][y]==-1)
			{
				dist[x][y]=dist[t.first][t.second]+1;
				q[++tt] ={x,y};
			}
		}
	}
	
	return dist[n-1][m-1];
}

int main()
{
	cin >> n >> m;
	
	for(int i = 0 ;i < n ;i ++)
		for(int j = 0 ; j < m ;j++)
			cin >> g[i][j];
	
	cout << bfs() << endl;
	return 0;
}