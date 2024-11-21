#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+10;

int aa , bb ;
char a[maxn] , b[maxn];
int dp[maxn][maxn];

signed main()
{
	cin >> aa >> bb;
	for(int i = 1 ; i <= aa ; i ++)
		cin >> a[i];
	for(int i = 1 ; i <= bb ; i ++)
		cin >> b[i];
		
	for(int i = 1 ; i <= aa ; i ++)
		for(int j = 1 ; j <= bb ; j++)
		{
			dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
			if(a[i] == b[j]) dp[i][j] = max(dp[i][j] , dp[i-1][j-1]+1);
		}
			
	cout << dp[aa][bb];
	
	return 0;
}