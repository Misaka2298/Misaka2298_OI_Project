#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 12 , maxm = pow(2,12);
LL dp[maxn][maxm];
bool st[maxm];
int n , m ;

int main()
{
	while(cin >> n >> m , n || m)
	{     
		for(int i = 0 ; i < pow(2,n) ; i++)
		{
			int cnt = 0;
			st[i] = true;
			for(int j = 0 ; j < n ; j++)
			{
				if(i >> j & 1)
				{
					if(cnt & 1) st[i] = false;
					cnt = 0;
				}
				else cnt ++;
			}
			if(cnt & 1) st[i] = false;
		}
		memset(dp , 0 , sizeof dp);
		dp[0][0] = 1;
		for(int i = 1 ; i <= m ; i ++)
			for(int j = 0 ; j < pow(2,n) ; j ++)
				for(int k = 0 ; k < pow(2,n) ; k++)
					if((j & k) == 0 && st[j | k])
						dp[i][j] += dp[i-1][k];			
		cout << dp[m][0] << endl;
	}
	return 0;
}