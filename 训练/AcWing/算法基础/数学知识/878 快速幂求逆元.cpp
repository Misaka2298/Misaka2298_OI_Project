// Problem: 快速幂求逆元
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/878/
// Memory Limit: 64 MB
// Time Limit: 5000 ms
// Time: 2025-08-25 14:11:40

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long LL;

LL qmi(int a, int b, int p)
{
	LL res = 1 % p;
	while(b)
	{
		if(b & 1)
			res = res * a % p;
		a = a * (LL) a % p;
		b >>= 1;
	}
	return res;
}

signed main()
{
	int n;
	cin >> n;
	while(n --)
	{
		int a, p;
		cin >> a >> p;
		if(a % p == 0) cout << "impossible" << endl;
		else cout << qmi(a, p-2, p) << endl;
	}
}