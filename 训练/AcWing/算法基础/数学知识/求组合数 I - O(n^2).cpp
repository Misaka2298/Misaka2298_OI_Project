// Problem: 求组合数 I - O(n^2)
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/887/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Time: 2025-08-27 20:33:15

#include <bits/stdc++.h>
using namespace std;
const int maxn = 2010, mod = 1e9+7;
typedef long long LL;
#define endl '\n'

int n;
int a, b;
LL c[maxn][maxn];

signed main()
{
	cin >> n;
	for(int i = 0 ; i <= 2009 ; i ++)
	{
		for(int j = 0 ; j <= i ; j ++)
		{
			if(!j) c[i][j] = 1;
			else c[i][j] = (c[i-1][j-1] + c[i-1][j]) % mod;
		}
	}
	
	while(n --)
	{
		cin >> a >> b;
		cout << c[a][b] << endl;
	}
}