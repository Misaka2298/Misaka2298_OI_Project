// D
// expect pts = 30
// expect diff = black.

//伟大的数学家艾斯比

#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
typedef long long LL;

int n;
int a[maxn];
LL ans;

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	freopen("minmax.in", "r", stdin);
	freopen("minmax.out", "w", stdout);
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];
	
	for(int i = 1 ; i <= n ; i ++)
		for(int j = i ; j <= n ; j ++)
			if(i != j)
				ans += max(a[i], a[j]) / min(a[i], a[j]);
	cout << ans;
}