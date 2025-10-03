// T2
// expect pts = 0

#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long uLL;

uLL n, tmax;
uLL sum;

signed main()
{
	freopen("bread.in", "r", stdin);
	freopen("bread.out", "w", stdout);
	cin >> n >> tmax;
	for(int i = 1 ; i <= n ; i ++)
	{
		uLL a;
		cin >> a;
		sum += a;
	}
	
	uLL l = 0, r = sum, ans = 0;
	while(l < r)
	{
		uLL mid = (l+r) / 2;
		if((sum/mid) <= tmax)
		{
			r = mid - 1;
			ans = mid;
		}
		else
			l = mid + 1;
	}
	if((sum/(ans-1)) <= tmax)
		ans --;
	cout << ans;
}