// Problem: P13595 『GTOI - 1B』筝
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P13595
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Time: 2025-11-20 18:40:44

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7+10;

int n;
int a[maxn];
int ans;
int pos[maxn];

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i], pos[a[i]] = i;
	
	int may = 0, r = 0;
	for(int i = 1 ; i <= n ; i ++)
	{
		may = max({may, pos[a[i]-1], pos[a[i]+1]});
		if(i > r)
		{
			ans ++;
			r = may;
		}
			
	}
	
	cout << ans;
	
}