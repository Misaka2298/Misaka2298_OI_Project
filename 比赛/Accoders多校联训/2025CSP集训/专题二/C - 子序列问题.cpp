// C
// expect pts = 100
// expect diff = red+, orange-

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;

int n;
int a[maxn];
int ans;

signed main()
{
	freopen("clist.in", "r", stdin);
	freopen("clist.out", "w", stdout);
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];
	
	int res = 0;
	for(int i = 1 ; i <= n ; i ++)
	{
		res ++;
		if(!(a[i] & a[i+1]))
			ans = max(ans, res), res = 0;
	}
	cout << ans;
}