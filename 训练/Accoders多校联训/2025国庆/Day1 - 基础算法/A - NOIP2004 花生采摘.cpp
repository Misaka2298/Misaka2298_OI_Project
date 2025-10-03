// A

#include <bits/stdc++.h>
using namespace std;
const int maxn = 25;
typedef pair<int, int> PII;

int n, m, lim;//limit
int g[maxn][maxn];
int ans, t;//time
vector<PII> inc;//increase
bool st[maxn][maxn];
int cnt;

signed main()
{
	cin >> n >> m >> lim;
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= m ; j ++)
			cin >> g[i][j], cnt += (g[i][j] != 0);
	
	for(int k = 1 ; k <= cnt ; k ++)
	{
		int mx = 0;
		for(int i = 1 ; i <= n ; i ++)
			for(int j = 1 ; j <= m ; j ++)
				if(!st[i][j] && mx < g[i][j])
					mx = g[i][j];
					
		for(int i = 1 ; i <= n ; i ++)
			for(int j = 1 ; j <= m ; j ++)
				if(!st[i][j] && mx == g[i][j])
					inc.push_back({i, j}), st[i][j] = 1;
	}
	
	if(inc[0].first*2+1 > lim)
		cout << 0, exit(0);
	
	t += inc[0].first;//初始
	PII pos = {inc[0].first, inc[0].second};//init
	for(auto i : inc)
	{
		int x = pos.first, y = pos.second;
		int nx = i.first, ny = i.second;
		
		if(t + (abs(nx-x) + abs(ny-y)) + nx + 1 > lim)
			break;
		
		t += (abs(nx-x) + abs(ny-y));
		pos = {nx, ny};
		ans += g[nx][ny];
		t += 1;
	}
	
	cout << ans;
	
	
	
}