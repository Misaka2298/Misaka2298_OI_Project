// Problem: 最长上升子序列
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/897/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Time: 2025-07-29 15:48:25
// expect pts = 

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;

int n;
int a[maxn];
int f[maxn];

signed main()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];
	
	for(int i = 1 ; i <= n ; i ++)
	{
		f[i] = 1;
		for(int j = 1 ; j < i ; j ++)
			if(a[j] < a[i])
				f[i] = max(f[i], f[j] + 1);
	}
	
	int ans = 0;
	for(int i = 1 ; i <= n ; i ++)
		ans = max(ans, f[i]);
	cout << ans;
}