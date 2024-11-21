#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+10 , INF = 0x3f;

int n , num[maxn];
int dp[maxn];

signed main()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
		cin >> num[i];
		
	for(int i = 1 ; i <= n ; i++)
	{
		dp[i] = 1;
		for(int j = 1 ; j < i ; j++)
			if(num[j] < num[i])
				dp[i] = max(dp[i] , dp[j]+1);
	}
	
	int flag = -INF;
	for(int i = 0 ; i <= n ; i ++)
		flag = max(flag , dp[i]);
	
	cout << flag;
	return 0;
}