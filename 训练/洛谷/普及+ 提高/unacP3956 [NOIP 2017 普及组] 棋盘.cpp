#include <bits/stdc++.h>
using namespace std;
const int maxm = 110;
#define endl '\n';

int n, m;
int g[maxm][maxm];
bool st[maxm][maxm], isColor[maxm][maxm];
int ans;

int deltax[] = {0, 0, 1, -1, 0, 0, -2, 2, -1, 1, -1, 1};
int deltay[] = {1, -1, 0, 0, 2, -2, 0, 0, 1, 1, -1, -1};
//                        3 |4

void dfs(int x, int y, int cost)
{
	if(cost >= ans)
		return;
	if(x == m && y == m)
	{
		ans = min(ans, cost);
		//cout << cost << endl;
		return;
	}
	
	for(int i = 0 ; i < 12; i++)
	{
		int nex = x + deltax[i], ney = y + deltay[i];
		if(((nex<0 || nex>m) || (ney<0 || ney>m)) || g[nex][ney] == 9) continue;
		if(st[nex][ney] || (!isColor[nex][ney] && g[m][m] != 5)) continue;
		
		if(((x==m-1 && y==m) || (x==m && y==m-1)) && !isColor[m][m]) cost += 2;
		
		if(i >= 4) cost += 2;//DeltaDist = 2;
		if(g[x][y] == g[nex][ney]) cost += 0;
		if(g[x][y] != g[nex][ney]) cost ++;
		
		st[nex][ney] = 1;
		dfs(nex, ney, cost);
		st[nex][ney] = 0;
		
	}
}


signed main()
{
	cin >> m >> n;
	for(int i = 0 ; i <= m+2; i ++)
		for(int j = 0 ; j <= m+2 ; j ++)
			g[i][j] = 9;
	for(int i = 1 ; i <= m ; i ++)
		for(int j = 1 ; j <= m ; j ++)
			g[i][j] = 0;
			
	while(n--)
	{
		int x, y, c;
		cin >> x >> y >> c;
		isColor[x][y] = 1;
		g[x][y] = c+1;
	}
	
	if(g[m][m] == 0) g[m][m] = 5;
	
	
	for(int i = 0 ; i <= m+1 ; i ++)
	{
		for(int j = 0 ; j <= m+1 ; j++)
			cout << g[i][j] << ' ';
		cout << endl;
	}
	cout << endl;
	
	
	ans = 1e9;
	dfs(1, 1, 0);
	if(ans == 1e9) cout << -1;
	else cout << ans;
}
	


/*
没有转移魔法
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010, maxm = 110;
#define endl '\n';

int n, m;
int g[maxm][maxm];
int ans;
bool st[maxm][maxm], iscolor[maxm][maxm];

int deltax[] = {0, 0, 1, -1};
int deltay[] = {1, -1, 0, 0};

void dfs(int nowx, int nowy, int cost)
{
	if(ans < cost)
		return;//最优性剪枝
	if(nowx == m && nowy == m)
	{
		cout << cost << endl;
		ans = min(ans, cost);
		//cout << 'a';
		return;
	}
	
	for(int i = 0 ; i < 4 ; i ++)
	{
		int newx = nowx + deltax[i], newy = nowy + deltay[i];
		if(g[newx][newy] == 9) continue;//edge
		if(st[newx][newy]) continue;
			
		if(g[newx][newy] == g[nowx][nowy] && g[newx][newy])//same color
			cost += 0;
		if(g[newx][newy] != g[nowx][nowy] && g[newx][newy])//diff color
			cost ++;
		if(!g[newx][newy])//to no color
		{
			if(!iscolor[nowx][nowy])
				continue;//不可能再走
			g[newx][newy] = g[nowx][nowy];//magic			cost += 2;
		}
		
		if(!iscolor[nowx][nowy])
			g[nowx][nowy] = 0;
		st[newx][newy] = 1;
		dfs(newx, newy, cost);
		st[newx][newy] = 0;
		
	}
}

signed main()
{
	cin >> m >> n;
	
	for(int i = 0 ; i <= m+1 ; i++)
		for(int j = 0 ; j <= m+1 ; j++)
			g[i][j] = 9;//edge
	for(int i = 1 ; i <= m ; i ++)
		for(int j = 1 ; j <= m ; j ++)
			g[i][j] = 0;
	
	for(int i = 0 ; i < n ; i++)
	{
		int x, y, c;
		cin >> x >> y >> c;
		iscolor[x][y] = 1;
		g[x][y] = c+1;
	}//0=white, 1=red, 2=yellow;
	
	for(int i = 0 ; i <= m+1 ; i ++)
	{
		for(int j = 0 ; j <= m+1 ; j++)
			cout << g[i][j] << ' ';
		cout << endl;
	}
	cout << endl;
	
	ans = 1e9;
	dfs(1, 1, 0);
	if(ans != 1e9) cout << ans;
	else cout << -1;
	 
}
*/