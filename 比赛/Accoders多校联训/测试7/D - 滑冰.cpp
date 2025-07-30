// T4
// expect pts = 65
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e3+10, maxnode = 2e5+10;
#define endl '\n'

int n;
int g[maxn][maxn];
int x[maxnode], y[maxnode];
int dist[maxn];
bool st[maxn];

int getdist(int x1, int y1, int x2, int y2)
{
	return min(abs(x1-x2), abs(y1-y2));
}

void dijkstra()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	for(int i = 1 ; i <= n ; i ++)
	{
		int t = -1;
		for(int j = 1 ; j <= n ; j ++)
			if(!st[j] && (t == -1 || dist[j] < dist[t]))
				t = j;
		st[t] = true;
		for(int j = 1 ; j <= n ; j++)
			dist[j] = min(dist[j] , dist[t]+g[t][j]);
	}
}

signed main()
{
	//freopen("shortest.in", "r", stdin);
	//freopen("shortest.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	bool isspe1 = true, isspe2 = true;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> x[i] >> y[i];
		if(x[i-1] > x[i] || y[i-1] > y[i])
			isspe2 = false;
		if(x[i] != y[i])
			isspe1 = false;
	}
		
	if((isspe1 || isspe2))
	{
		cout << getdist(x[n], y[n], x[1], y[1]);
		//cout << 'a';
		exit(0);
	}
	
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= n ; j ++)
			g[i][j] = getdist(x[i], y[i], x[j], y[j]);
	
	/*
	for(int i = 1 ; i <= n ; i ++)
	{
		for(int j = 1 ; j <= n ; j ++)
			cout << g[i][j] << ' ';
		cout << endl;
	}
	*/
	dijkstra();
	cout << dist[n];
	
}