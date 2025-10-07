// A
// expect pts = 100
// expect diff = red
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
typedef long long LL;

int n;
LL a[maxn];

signed main()
{
	freopen("keyboard.in", "r", stdin);
	freopen("keyboard.out", "w", stdout);
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];
	
	sort(a+1, a+1+n);

	if(n == 1)
	{
		cout << a[1] - 1;
		exit(0);
	}
	
	LL ans = 0;
	for(int i = 1 ; i < n ; i ++)
			ans += a[i+1] - a[i] - 1;
	cout << ans;
	
}
