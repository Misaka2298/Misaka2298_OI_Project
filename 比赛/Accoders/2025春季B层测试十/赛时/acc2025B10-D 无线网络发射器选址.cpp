//T4
//expect pts = idk, but it cant 100, maybe 70?
//very very violince
//e, "baoli" zen me xie lai zhe?
#include <bits/stdc++.h>
using namespace std;
const int maxn = 130;

int n, g[maxn][maxn], a[maxn][maxn];
int d;


signed main()
{
	cin >> d >> n;
	for(int i = 0 ; i < n ; i++)
	{
		int x, y, num;
		cin >> x >> y >> num;
		g[x+1][y+1] = num;//changed xy-edge to 1~129
	}
	
	for(int i = 1 ; i <= 129 ; i ++)
		for(int j = 1 ; j <= 129 ; j ++)
		{
			int xledge = max(1, i-d), xredge = min(129, i+d);
			int yledge = max(1, j-d), yredge = min(129, j+d);
			for(int ii = xledge ; ii <= xredge ; ii++)
				for(int jj = yledge ; jj <= yredge ; jj++)
					a[i][j] += g[ii][jj];
		}
		
	
	/*
	for(int i = 1 ; i <= 129 ; i++)//debug
	{
		for(int j = 1 ; j <= 129 ; j++)
			cout << a[i][j] << ' ';
		cout << endl;
	}
	*/	
		
	int maxx= -1e9;
	for(int i = 1 ; i <= 129 ; i++)
		for(int j = 1 ; j <= 129 ; j++)
			maxx = max(maxx, a[i][j]);
	
	int ans = 0;
	for(int i = 1 ; i <= 129 ; i++)
		for(int j = 1 ; j <= 129 ; j++)
			if(a[i][j] == maxx)
				ans ++;
	
	cout << ans << ' ' << maxx;
		
}