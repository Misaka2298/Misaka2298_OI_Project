#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+10;

int id, n, m, k, c, cnt[maxn][maxn], res[1000005];
bool g[maxn][maxn];

void update(int x1, int y1, int x2, int y2)
{
	cnt[x1][y1]++;
	cnt[x2+1][y1]--;
	cnt[x1][y2+1]--;
	cnt[x2+1][y2+1]++;
	
}

signed main()
{
	cin >> id >> n >> m >> k >> c;
	
	for(int i = 0 ; i < c ; i++)
	{
		int x, y;
		cin >> x >> y;
		g[x][y] = true;
		update(max(1, x-k), max(1, y-k), min(n, x+k), min(m, y+k));
	}
	
	for (int i = 1; i <= n; ++i)
    	for (int j = 1; j <= m; ++j) 
    		cnt[i][j] += cnt[i][j - 1];
    		
 	for (int i = 1; i <= n; ++i)
    	for (int j = 1; j <= m; ++j)
    		cnt[i][j] += cnt[i - 1][j];
	
	int mx = 0;
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= m ; j ++)
			if(!g[i][j])
				res[cnt[i][j]]++, mx = max(mx, cnt[i][j]);
	
	for(int i = 1 ; i <= mx ; i++)
		cout << res[i] << ' ';
}