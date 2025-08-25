// Problem: 线性同余方程
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/880/
// Memory Limit: 64 MB
// Time Limit: 5000 ms
// Time: 2025-08-25 19:18:13

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long LL;

LL exgcd(LL a, LL b, LL &x, LL &y)
{
	if(b == 0)
	{
		x = 1, y = 0;
		return a;
	}
	LL gcd, x1, y1;
	gcd = exgcd(b, a%b, x1, y1);
	x = y1, y = x1 - a/b * y1;
	return gcd;
}

signed main()
{
	int n;
	cin >> n;
	while(n--)
	{
		LL a, b, m, x, y;
		cin >> a >> b >> m;
		LL gcd = exgcd(a, m, x, y);
		if(b % gcd) cout << "impossible" << endl;
		else cout << x * b % m / gcd << endl;
		
	}
}