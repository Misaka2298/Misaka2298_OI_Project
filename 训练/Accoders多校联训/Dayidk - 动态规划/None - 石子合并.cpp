// Problem: 石子合并
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/284/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Time: 2025-07-29 16:03:44
// expect pts = 

#include <bits/stdc++.h>
using namespace std;
const int maxn = 310;

int n;
int a[maxn], s[maxn];
int f[maxn][maxn];

signed main()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];
	for(int i = 1 ; i <= n ; i ++)
		s[i] = s[i-1] + a[i];
	
	for(int len = 2 ; len <= n ; len ++)
		for(int i = 1 ; i+len-1 <= n ; i ++)
		{
			int l = i, r = i+len-1;
			f[l][r] = INT_MAX;
			for(int k = l ; k < r; k ++)
			{
				f[l][r] = min(f[l][r], f[l][k]+f[k+1][r]+s[r]-s[l-1]);
			}
		}
	
	cout << f[1][n];
}