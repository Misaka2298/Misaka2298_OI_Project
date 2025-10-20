// A upload
// expect pts = >30
// expect diff = idk, green?
// expect error = WA

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL ans[100] = {0, 1, 8, 343, 1331, 1030301, 1367631, 1003003001, 10662526601, 1334996994331, 1033394994933301, 1000030000300001, 1331399339931331};
LL n;

signed main()
{
	freopen("cube.in", "r", stdin);
	freopen("cube.out", "w", stdout);
	cin >> n;
	sort(ans, ans+12);
	if(n <= 7)
	{
		cout << 1;
		exit(0);
	}
	for(int i = 12 ; i >= 1 ; i --)
	{
		if(ans[i] <= n)
		{
			cout << ans[i];
			break;
		}
	}
}

/*
1
8
343
1331
1030301
1367631
1003003001
10662526601

*/