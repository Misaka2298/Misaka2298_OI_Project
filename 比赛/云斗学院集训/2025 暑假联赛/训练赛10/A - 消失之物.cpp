// Problem: A - 消失之物
// Contest: Virtual Judge - 专题训练赛 10
// URL: https://vjudge.net/contest/738490#problem/A
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// Time: 2025-08-11 09:45:56

// 餐券上一楼前台拿

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+10;
typedef long long LL;
#define endl '\n'
const int mod = 10;

int n, m;
int v[maxn];
int f[maxn], dp[maxn];

signed main()
{
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++)
		cin >> v[i];
	
	f[0] = 1;
	for(int i = 1 ; i <= n ; i ++)
		for(int j = m ; j >= v[i] ; j --)
			f[j] = (f[j] + f[j-v[i]]) % mod;
	
	for(int i = 1 ; i <= n ; i ++)
	{
		for(int i = 0 ; i <= max(n, m) ; i ++)
			dp[i] = f[i];
			
		for(int j = v[i] ; j <= m ; j ++)
			dp[j] = (dp[j] - dp[j-v[i]]) % mod;
			
		for(int j = 1 ; j <= m ; j ++)
			cout << (dp[j] + mod) % mod;
		cout << endl;
	}

	/*
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 0 ; j <= m ; j ++)
			dp[i][j] = (dp[i][j] + mod) % mod;
	*/
	//cout << f[n][m];
}