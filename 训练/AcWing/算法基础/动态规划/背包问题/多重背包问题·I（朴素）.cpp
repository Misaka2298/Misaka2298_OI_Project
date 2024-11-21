#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e2+10;
int n , vv;
int v[maxn] , w[maxn] ,s[maxn];
int dp[maxn][maxn];

int main()
{
	cin >> n >> vv;
	for(int i = 1 ; i <= n; i++)
		cin >> v[i] >> w[i] >> s[i];
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= vv ; j++)
			for(int k = 0 ; k<=s[i] && k*v[i]<=j ; k++)
				dp[i][j]=max(dp[i-1][j],dp[i][j-k*v[i]]+k*w[i]);
				
	cout << dp[n][vv];
	return 0;
}