// Problem: 合唱队形
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/484/
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// Time: 2025-08-29 15:49:55

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;

int n;
int f[maxn], rf[maxn];
int a[maxn];

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
	for(int i = n ; i >= 1 ; i --)
	{
		rf[i] = 1;
		for(int j = n ; j > i ; j --)
			if(a[j] < a[i])
				rf[i] = max(rf[i], rf[j] + 1);
	}
	
	int ans = 0;
	for(int i = 1 ; i <= n ; i ++)
		ans = max(ans, f[i] + rf[i] - 1);
	cout << n - ans;
}