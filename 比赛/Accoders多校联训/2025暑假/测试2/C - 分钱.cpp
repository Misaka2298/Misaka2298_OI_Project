//T3
//expect pts = idk;
#include <bits/stdc++.h>
using namespace std;

signed main()
{
	freopen("kas.in", "r", stdin);
	freopen("kas.out", "w", stdout);
	long long ans;
	int n;
	cin >> n;
	while(n--)
	{
		long long a;
		cin >> a;
		ans += a;
	}
	cout << ans / 2;
}