#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+10, mod = 1e9+7;

int n, f[maxn];

signed main()
{
	cin >> n;
	f[0] = 1;
	for(int i = 1 ; i <= n ; i ++)
		for(int j = i ; j <= n ; j ++)
			f[j] = (f[j] + f[j-i]) % mod;
	
	cout << f[n];
}