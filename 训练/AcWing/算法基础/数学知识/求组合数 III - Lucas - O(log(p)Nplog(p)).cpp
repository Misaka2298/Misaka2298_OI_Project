// Problem: 求组合数 III - O(log(p)Nplog(p))
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/889/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Time: 2025-08-28 15:36:19

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define endl '\n'

int qmi(int a, int b, int p)
{
	int res = 1 % p;
	while(b)
	{
		if(b & 1)
			res = (LL)res * a % p;
		a = (LL)a * a % p;
		b >>= 1;
	}
	return res;
}

int C(int a, int b, int p)
{
	if(b > a)
		return 0;
	if(a-b > a)
		b = a - b;
	LL x = 1, y = 1;
	for(int i = 0 ; i < b ; i ++)
	{
		x = x * (a-i) % p;
		y = y * (i+1) % p;
	}
	return (LL)x * qmi(y, p-2, p) % p;
}

LL lucas(LL a, LL b, LL p)
{
	if(a < p && b < p)
		return C(a, b, p);
	return (LL)(C(a%p, b%p, p) * lucas(a/p, b/p, p)) % p;
}

signed main()
{
	int n;
	cin >> n;
	while(n--)
	{
		LL a, b, c;
		cin >> a >> b >> c;
		cout << lucas(a, b, c) << endl;
	}
}