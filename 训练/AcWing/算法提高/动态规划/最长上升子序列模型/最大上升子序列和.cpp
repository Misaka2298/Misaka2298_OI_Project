// Problem: 最大上升子序列和
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1018/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Time: 2025-08-29 16:04:18

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+10;

int n;
int a[maxn], f[maxn];

signed main()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];
	
	int ans = 0;
	for(int i = 1 ; i <= n ; i ++)
	{
		f[i] = a[i];
		for(int j = 1 ; j < i ; j ++)
			if(a[j] < a[i])
				f[i] = max(f[i], f[j] + a[i]);
		ans = max(ans, f[i]);
	}
	cout << ans;
}