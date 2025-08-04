//T1
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define endl '\n'

LL sol(LL a, LL b, LL p)
{
	LL ans = 1;
	while (b)
	{
		if (b & 1)
			ans = ans * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return ans;
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n, m, k, x;
	cin >> n >> m >> k >> x;
	cout << (x % n + m % n * sol(10, k, n) % n) % n << endl;
	return 0;
}
