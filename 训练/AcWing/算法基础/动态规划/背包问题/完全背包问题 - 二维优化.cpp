//二维优化完全背包问题
//状态转移方程：
//dp[i][j] = max(dp[i-1][j] , dp[i][j-v[i]]+w[i])
//为什么是i而不是i-1？因为当容量=j-v[i]时，第i个物品可能存在，所以用i更新。
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+10;
int n , vv;
int v[maxn] , w[maxn];
int dp[maxn][maxn];

int main()
{
	cin >> n >> vv;
	for(int i = 1 ; i <= n ; i++)
		cin >> v[i] >> w[i];
	
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= vv ; j++)
		{
			dp[i][j] = dp[i-1][j];
			if(j >= v[i])dp[i][j] = max(dp[i-1][j] , dp[i][j-v[i]]+w[i]);
		}
	cout << dp[n][vv];	
	return 0;
}