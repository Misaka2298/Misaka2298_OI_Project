#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+10 , MOD = 1e9+7;

int n ;
int dp[maxn];

signed main()
{
	cin >> n ;
	dp[0] = 1;
	for(int i = 1 ; i <= n ; i++)
		for(int j = i ; j <= n ; j++)
			dp[j] = (dp[j] + dp[j-i]) % MOD;
			
	cout << dp[n];
	return 0;
}

/*
5
7
*/