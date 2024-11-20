//01背包问题的一维优化
//状态转移方程：dp[j] = max(dp[j] , dp[j-v[i]]+w[i])
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+10;

int n , vv ;
int v[maxn] , w[maxn];
int dp[maxn];

int main()
{
	cin >> n >> vv;
	for(int i = 1 ; i <= n ; i++)cin >> v[i] >> w[i];
	
	for(int i = 1 ; i <= n ; i++)
		for(int j = vv ; j >= 1 ; j--)
		{
			if(j >= v[i]) dp[j] = max(dp[j] , dp[j-v[i]]+w[i]);
		}
	cout << dp[vv];
	return 0;
}