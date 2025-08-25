// Problem: 快速幂
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/877/
// Memory Limit: 64 MB
// Time Limit: 5000 ms
// Time: 2025-08-25 11:39:17

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define endl '\n'

LL qmi(int a, int b, int p)
{
	LL res = 1 % p;
	while(b)
	{
		if(b & 1)
			res = res * a % p;
		a = a * (LL)a % p;
		b >>= 1;
	}
	return res;
}

signed main()
{
	int n;
	cin >> n;
	while(n--)
	{
		int a, b, p;
		cin >> a >> b >> p;
		cout << qmi(a, b, p) << endl;
	}
}