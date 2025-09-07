// Problem: 大盗阿福
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1051/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Time: 2025-09-07 14:17:03

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10, inf = 0x3f3f3f3f;

int T;
int n;
int w[maxn];
int f[maxn][3];

signed main()
{
	cin >> T;
	while(T --)
	{
		cin >> n;
		f[0][0] = 0, f[0][1] = -inf;
		for(int i = 1 ; i <= n ; i ++)
			cin >> w[i];
		for(int i = 1 ; i <= n ; i ++)
		{
			f[i][1] = f[i-1][0] + w[i];
			f[i][0] = max(f[i-1][0], f[i-1][1]);
		}
		cout << max(f[n][1], f[n][0]) << endl;
	}
}