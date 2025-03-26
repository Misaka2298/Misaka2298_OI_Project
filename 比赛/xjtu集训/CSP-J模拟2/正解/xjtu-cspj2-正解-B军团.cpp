#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000010;

long long n, a[maxn], ans;

signed main()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
		cin >> a[i];
	for(int i = 2 ; i <= n ; i++)
		ans += max(a[i], a[i-1]);
	cout << ans;
}
