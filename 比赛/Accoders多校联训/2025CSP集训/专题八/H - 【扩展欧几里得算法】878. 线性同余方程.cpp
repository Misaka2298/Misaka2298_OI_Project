// H
// expect pts = 100
// expect diff = idk

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define endl '\n'

LL exgcd(LL a, LL b, LL &x, LL &y)
{
	if(b == 0)
	{
		x = 1, y = 0;
		return a;
	}
	
	LL x1 = x, y1 = y;
	LL gcd = exgcd(b, a%b, x1, y1);
	
	x = y1, y = x1 - a/b * y1;
	return gcd;
}

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
	ios::sync_with_stdio(false); cin.tie(nullptr);
	freopen("equ.in", "r", stdin);
	freopen("equ.out", "w", stdout);
	int T;
	cin >> T;
	
	while(T --)
	{
		LL a, b, m, x, y;
		cin >> a >> b >> m;
		LL gcd = exgcd(a, m, x, y);
		
		if(b % gcd)
			cout << "impossible" << endl;
		else
			cout << b * x % m / gcd << endl;
	}
}















