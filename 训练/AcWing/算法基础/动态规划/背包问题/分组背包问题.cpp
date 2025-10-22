#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;

int n , m;
int v[maxn][maxn] , w[maxn][maxn] , s[maxn];
int f[maxn];

signed main()
{
	cin >> n >> m ;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> s[i];
		for(int j = 1 ; j <= s[i] ; j++)
			cin >> v[i][j] >> w[i][j];
	}
	
	for(int i = 1 ; i <= n ; i ++)
		for(int j = m ; j >= 1; j --)
			for(int k = 1 ; k <= s[i] ; k ++)
				if(j >= v[i][k])
					f[j] = max(f[j] , f[j-v[i][k]]+w[i][k]);
					
	cout << f[m];
	return 0;
}