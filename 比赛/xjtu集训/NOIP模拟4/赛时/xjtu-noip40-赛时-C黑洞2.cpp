//T3
#include <bits/stdc++.h>
using namespace std;
const int maxn = 43;

int T, n, m, res;
char g[maxn][maxn];
string live[maxn][maxn];
bool st[maxn][maxn];

signed main()
{
	cin >> T;
	while(T--)
	{
		int dotcnt;
		cin >> n >> m;
		for(int i = 0 ; i <= n+1 ; i ++)
			for(int j = 0 ; j <= m+1 ; j ++)
				g[i][j] = 'O';
		
		for(int i = 1 ; i <= n ; i++)
			for(int j = 1 ; j <= m ; j++)
			{
				cin >> g[i][j];
				if(g[i][j] == '.')
					dotcnt++;
			}
				
		if(dotcnt == 1)
		{
			cout << 1 << endl;
			continue;
		}
		if(dotcnt == 0)
		{
			cout << 0 << endl;
			continue;
		}
		
		
		cout << 0 << endl;
		/*
		res = 0;
		for(int i = 1 ; i <= n ; i++)
			for(int j = 1 ; j <= m ; j++)
				if(g[i][j] != 'O')
				{
					memset(st, false, sizeof st);
					
				}		
		*/
		
	}
}