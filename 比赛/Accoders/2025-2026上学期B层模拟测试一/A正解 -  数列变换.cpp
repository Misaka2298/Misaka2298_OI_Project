#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10, mod = 998244353;
typedef long long LL;

LL n, m;
LL arr[maxn];
LL a, b;

char finalopt;
LL opttick;

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	freopen("trans.in", "r", stdin);
	freopen("trans.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++)
		cin >> arr[i];
	
	for(int i = 1 ; i <= m ; i ++)
	{
		char opt;
		LL k;
		cin >> opt >> k;
		if(opt == 'A')
			a += k;
		else
			b += k;
	}
	
	if(a > b)
		finalopt = 'a', opttick = a - b;
	else if(a < b)
		finalopt = 'b', opttick = b - a;
	else
		opttick = 0;
	
	while(opttick --)
	{
		if(finalopt == 'a')
			for(int i = 2 ; i <= n ; i ++)
				arr[i] = (arr[i] + arr[i-1]) % mod;
		else
			for(int i = n ; i >= 2 ; i --)
				arr[i] = (arr[i] - arr[i-1]) % mod;
	}
	
	for(int i = 1 ; i <= n ; i ++)
		cout << (arr[i] + mod) % mod << ' ';
	
	return 0;
}