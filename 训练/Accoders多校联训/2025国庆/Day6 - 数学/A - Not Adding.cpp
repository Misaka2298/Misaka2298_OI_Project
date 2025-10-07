// Problem: A - Not Adding
// Contest: Virtual Judge - 20251007多校联训数学
// URL: https://vjudge.net/contest/754636#problem/A
// Memory Limit: 1024 MB
// Time Limit: 1000 ms
// Time: 2025-10-07 08:50:23

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;

int n, v[maxn], mmax = -1, ans;

signed main()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
	{
		int x;
		cin >> x;
		v[x] = 1;
		mmax = max(mmax, x);
	}
	for(int i = 1 ; i <= mmax ; i ++)
	{
		if(!v[i])
		{
			int g = 0;
			for(int j = 2 * i ; j <= mmax ; j += i)
				if(v[j])
					g = __gcd(g, j);
			ans += (g == i);
		}
	}
	cout << ans;
}