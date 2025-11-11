// Problem: 货仓选址
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/106/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Time: 2025-11-11 19:17:50

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;

int n;
int ans, mid;
int a[maxn];

signed main()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];
	
	sort(a+1, a+1+n);
	
	mid = a[(n+1)/2];
	for(int i = 1 ; i <= n ; i ++)
		ans += abs(a[i] - mid);
	
	cout << ans;
}