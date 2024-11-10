#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+10;

int n , vv ;
int v[maxn] , w[maxn];
int f[maxn][maxn];

int main()
{
	cin >> n >> vv;
	for(int i = 1 ; i <= n ; i++)cin >> v[i] >> w[i];
	
	for(int i = 1 ; i <= n ; i++)
		for(int j = 0 ; j <= vv ; j++)
		{
			f[i][j] = f[i-1][j];
			if(j >= v[i]) f[i][j] = max(f[i][j] , f[i-1][j-v[i]]+w[i]);
		}
	cout << f[n][vv];
	return 0;
}