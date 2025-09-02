// Problem: 友好城市
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1014/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Time: 2025-08-29 16:00:43

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
typedef pair<int, int> PII;

int n, f[maxn];
PII a[maxn];

signed main()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i].first >> a[i].second;
	
	sort(a+1, a+n+1);
	
	int ans = 0;
	for(int i = 1 ; i <= n ; i ++)
	{
		f[i] = 1;
		for(int j = 1 ; j < i ; j ++)
			if(a[j].second < a[i].second)
				f[i] = max(f[i], f[j] + 1);
		ans = max(ans, f[i]);
	}
	cout << ans;
}