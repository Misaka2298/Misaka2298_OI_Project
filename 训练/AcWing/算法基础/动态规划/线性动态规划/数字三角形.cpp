#include <bits/stdc++.h>
using namespace std;
const int maxn = 510 , INF = 1e9;
int n , num[maxn][maxn];
int dp[maxn][maxn] = {-INF};

signed main()
{
	cin >> n ;
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= i ; j++)
			cin >> num[i][j];
			
	for (int i = 0; i <= n; i ++ )
        for (int j = 0; j <= i + 1; j ++ )
            dp[i][j] = -INF;
	
	dp[1][1] = num[1][1];
	for(int i = 2 ; i <= n ; i++)
		for(int j = 1 ; j <= i ; j++)
			dp[i][j] = max(dp[i-1][j-1] + num[i][j], dp[i-1][j]+ num[i][j]);
			
	int flag = -1e9;
	for(int i = 1 ; i <= n ; i ++)
		flag = max(flag , dp[n][i]);
	
	cout << flag;
	return 0;
}