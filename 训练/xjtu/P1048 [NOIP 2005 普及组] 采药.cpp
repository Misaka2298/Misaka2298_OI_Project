#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;

int n, m, w[maxn], v[maxn], f[maxn][maxn];

signed main()
{
	cin >> m >> n;
	for(int i = 1 ; i <= n ; i++)
		cin >> v[i] >> w[i];
	
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= m ; j++)
		{
			f[i][j] = f[i-1][j];
			if(j >= v[i])
				f[i][j] = max(f[i][j], f[i-1][j-v[i]]+w[i]);
		}
	cout << f[n][m];
}