// T2

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;

int n;
int a[maxn];

signed main()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];
	
	int l = 1, r = n, ans = 0;
	while(l < r)
	{
		if(a[l] == a[r])
		{
			l ++, r--;
			continue;
		}
		int lsum = a[l], rsum = a[r];
		int ll = l, rr = r;
		while(lsum != rsum && ll < rr)
		{
			if(lsum < rsum && ll < rr)
			{
				ll ++;
				lsum += a[ll];
				ans ++;
			}
			if(rsum < lsum && ll < rr)
			{
				rr --;
				rsum += a[rr];
				ans ++;
			}
		}
		l = ll+1, r = rr-1;//ll+1, rr-1?
	}
	cout << ans;
}