// Problem: 扩展欧几里得算法
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/879/
// Memory Limit: 64 MB
// Time Limit: 5000 ms
// Time: 2025-08-25 14:17:28

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int exgcd(int a, int b, int &x, int &y)
{
	if(b == 0)
	{
		x = 1, y = 0;
		return a;
	}
	int x1, y1, gcd;
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
		int a, b, x, y;
		cin >> a >> b;
		exgcd(a, b, x, y);
		cout << x << ' ' << y << endl;
	}
}
