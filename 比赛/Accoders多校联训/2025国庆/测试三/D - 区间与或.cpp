// D
// expect pts = 30
// expect diff = idk
/*
就这个骗分爽
怎么大家都在搓线段树
乔子健你啥时候能学学线段树
*/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10, mod = 1e9+7;
typedef long long LL;

int n, m;
int a[maxn];

signed main()
{
	freopen("interval.in", "r", stdin);
	freopen("interval.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m;	
	while(m --)
	{
		int opt, l, r, x;
		cin >> opt >> l >> r >> x;
		for(int i = l ; i <= r ; i ++)
		{
			if(opt == 1) a[i] = a[i] & x;
			else a[i] = a[i] | x;
		}
	}
	int ans = 0;
	for(int i = 1 ; i <= n ; i ++)
		ans = ((LL)ans + ((LL)a[i] * (LL)i) % mod) % mod;
	cout << ans;
}