// F
// expect pts = 100
// expect diff = idk

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define endl '\n'

int T;
int a, b, c;

int quickpow(int a, int b, int p)
{
	int res = 1 % p;
	const int mod = p;
	while(b)
	{
		if(b & 1)
			res = ((LL)a % mod * (LL)res % mod) % mod;
		a = ((LL)a % mod * (LL)a % mod) % mod;
		b >>= 1;
	}
	return res;
}

signed main()
{
	freopen("pow.in", "r", stdin);
	freopen("pow.out", "w", stdout);
	cin >> T;
	while(T --)
	{
		cin >> a >> b >> c;
		cout << quickpow(a, b, c) << endl;
	}
	
	
	
	
	
}