// T4
// expect pts = idk
// expect diff = yellow

#include <bits/stdc++.h>
using namespace std;
const int maxn = 200;

int n, m;
int ans;
char g[maxn][maxn];

signed main()
{
	freopen("grass.in", "r", stdin);
	freopen("grass.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= m ; j ++)
			cin >> g[i][j];
	
	int x = 1, y = 1;
	for(int i = 1 ; i <= n ; i ++)
	{
		if(i % 2 != 0)//right
		{
			for(int j = 1 ; j <= m ; j ++)
				if(g[i][j] == 'W')
					ans += (abs(x-i)+abs(y-j)), x = i, y = j;
		}	
		else
		{
			for(int j = m ; j >= 1 ; j --)
				if(g[i][j] == 'W')
					ans += (abs(x-i)+abs(y-j)), x = i, y = j;
		}
			
	}
	cout << ans;
	
}