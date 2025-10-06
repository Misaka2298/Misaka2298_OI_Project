// A
// expect pts = 100
// expect diff = orange
/*
NOIP不是不考数位dp吗
所以这不是数位dp，嗯。
*/

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
typedef long long LL;

LL l, r, k;
LL f[maxn];
LL ans;

LL get3popcount(LL x)// 正确性存疑// 哦看来是很正确的
{
	LL res = 0;
	while(x)
	{
		if(x % 3 == 1)
			res ++;
		x /= 3;
	}
	return res;
}

signed main()
{
	//freopen("radix.in", "r", stdin);
	//freopen("radix.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> l >> r >> k;
	
	for(LL i = l ; i <= r ; i ++)
		if(abs(get3popcount(i) - __builtin_popcount(i)) <= k)
			ans ++;

	cout << ans;
	
	return 0;
}