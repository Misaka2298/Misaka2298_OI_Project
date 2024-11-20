#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+50;
int n , vv;
int v[maxn] , w[maxn];
int dp[maxn];

int main()
{
	cin >> n >> vv;
	int cnt = 0;
	int a , b , s;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> a >> b >> s;
		int k = 1;
		while(k <= s)
		{
			cnt++;
			v[cnt] = a * k;
			w[cnt] = b * k;
			s -= k;
			k *= 2;
		}
			if(s > 0)
		{
			cnt++;
			v[cnt] = a*s;
			w[cnt] = b*s;
		}
	}
	n=cnt;
		
	//01背包
	for(int i = 1; i <= n ; i++)
		for(int j = vv ; j >=v[i] ; j --)
			dp[j] = max(dp[j] , dp[j-v[i]]+w[i]);
				
	cout << dp[vv];
	return 0;
}