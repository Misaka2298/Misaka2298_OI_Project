// D
// expect pts = 12
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL n, q, k;

void spe1()
{
	LL l, r;
	LL ans = 0;
	while(q--)
	{
		cin >> l >> r;
		ans += r-l+1;
	}
	cout << ans;
	exit(0);
}

signed main()
{
	freopen("jumpgame.in", "r", stdin);
	freopen("jumpgame.out", "w", stdout);
	cin >> n >> q >> k;
	if(k == 1)
		spe1();
	
}