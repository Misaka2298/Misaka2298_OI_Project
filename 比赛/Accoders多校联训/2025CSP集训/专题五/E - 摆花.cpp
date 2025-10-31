// E
// expect pts = 100
// expect diff = orange

#include <bits/stdc++.h>
using namespace std;
const int maxn = 110, mod = 1000007;

int n, m;
int s[maxn];
int f[maxn][maxn];

signed main()
{
	freopen("flower.in", "r", stdin);
	freopen("flower.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++)
		cin >> s[i];
	
	f[0][0] = 1;
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 0 ; j <= m ; j ++)
			for(int k = 0 ; k <= min(j, s[i]) ; k ++)
				f[i][j] = (f[i][j] + f[i-1][j-k]) % mod;
	
	//for(int i = 1 ; i <= m ; i ++)
		//cout << f[n][i] << ' ';
	cout << f[n][m];
	
}