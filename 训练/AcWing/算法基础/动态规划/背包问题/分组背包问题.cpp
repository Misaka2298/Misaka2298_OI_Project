#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;

int n , vv;
int v[maxn][maxn] , w[maxn][maxn] , s[maxn];
int dp[maxn];

int main()
{
	cin >> n >> vv ;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> s[i];
		for(int j = 0 ; j < s[i] ; j++)
			cin >> v[i][j] >> w[i][j];
	}
	
	for(int i = 1 ; i <= n ; i ++)
		for(int j = vv ; j >= 1; j --)
			for(int k = 0 ; k < s[i] ; k ++)
				if(j >= v[i][k])
					dp[j] = max(dp[j] , dp[j-v[i][k]]+w[i][k]);
					
	cout << dp[vv];
	return 0;
}