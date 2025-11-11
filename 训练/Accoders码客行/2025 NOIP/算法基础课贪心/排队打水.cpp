// Problem: 排队打水
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/description/915/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Time: 2025-11-11 19:14:24

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
typedef long long LL;

int n;
LL a[maxn];
LL ans;

signed main()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];
	sort(a+1, a+1+n);
	
	for(int i = 1 ; i <= n ; i ++)
		ans += a[i] * (n-i);
	cout << ans;
}