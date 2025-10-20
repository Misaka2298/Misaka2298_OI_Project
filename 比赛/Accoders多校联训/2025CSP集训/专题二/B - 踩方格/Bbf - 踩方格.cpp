// B - ans
// expect pts = 
// expect diff = 

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000;

int n;
bool st[maxn][maxn];
int dx[] = {-1, 0, 0};
int dy[] = {0, 1, -1};
int ans;

void dbug(int i)
{
	if(i == 0)
		cout << 'U';
	if(i == 1)
		cout << 'R';
	if(i == 2)
		cout << 'L';
}

void dfs(int step, int posx, int posy)
{
	if(step == n)
	{
		ans ++;
		//cout << end
		return;
	}
	
	for(int i = 0 ; i < 3 ; i ++)
	{
		int nx = posx+dx[i], ny = posy+dy[i];
		if(st[nx][ny])
			continue;
		st[nx][ny] = 1;
		//dbug(i);
		dfs(step+1, nx, ny);
		st[nx][ny] = 0;
	}
}

signed main()
{
	cin >> n;
	if(n == 0)
	{
		cout << 0;
		exit(0);
	}
	memset(st, 0, sizeof st);
	st[500][500] = 1;
	ans = 0;
	dfs(0, 500, 500);
	cout << ans;
	
	
	
}