//朴素完全背包问题
//状态转移方程：
//dp[i][j] = max(dp[i][j],dp[i-1][j-k*v[i]]+k*w[i])
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+10;

int n , vv ; 
int v[maxn] , w[maxn];
int dp[maxn][maxn];

int main()
{
	cin >> n >> vv;
	for(int i = 1 ; i <= n ; i++)
		cin >> v[i] >> w[i];
	
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= vv ; j++)
			for(int k = 0 ; k*v[i]<=j ; k++)
				dp[i][j] = max(dp[i][j],dp[i-1][j-k*v[i]]+k*w[i]);
			
	cout << dp[n][vv];
	return 0;
}