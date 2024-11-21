#include <bits/stdc++.h>
using namespace std;
const int maxn = 310;

int n;
int s[maxn];
int dp[maxn][maxn];

signed main()
{
	cin >> n;
	
	for(int i = 1 ; i <= n ; i ++) cin >> s[i];
	for(int i = 1 ; i <= n ; i ++) s[i] += s[i-1];
	
	for(int len = 2 ; len <= n ; len ++)
		for(int i = 1 ; i+len-1 <= n ; i ++)
		{
			int l = i , r = i+len-1;
			dp[l][r] = 1e9;
			for(int k = l ; k <= r ; k ++)
				dp[l][r] = min(dp[l][r] , dp[l][k] + dp[k+1][r] + s[r] - s[l-1]);
		}
		
	cout << dp[1][n];
	
	return 0;
}