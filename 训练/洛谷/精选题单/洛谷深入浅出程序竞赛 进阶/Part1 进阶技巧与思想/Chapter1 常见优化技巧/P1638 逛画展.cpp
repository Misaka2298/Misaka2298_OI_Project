// Problem: P1638 逛画展
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1638
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// Time: 2025-11-15 09:58:38

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;

int n, m;
int arr[maxn];
int cnt[maxn];
bool st[maxn];

signed main()
{
	cin >> n >> m;
	int mcnt = 0;
	for(int i = 1 ; i <= n ; i ++)
		cin >> arr[i];
	
	int l = 0, r = 0, ansl = 0x3f3f3f3f, ansr, anslen = 0x3f3f3f3f;
	while(l <= n)
	{
		while(mcnt < m)
		{
			r ++;
			if(r > n)
				break;
			if(cnt[arr[r]] == 0)
				st[arr[r]] = 1, mcnt ++;
			cnt[arr[r]] ++;
		}
		
		while(true)
		{
			if(l < r)
				 l ++;
			if(l >= r) break;
			if(cnt[arr[l]] == 1)
				break;
			cnt[arr[l]] --;
		}
		
		if(r <= n && (r-l+1 < anslen || (r-l+1 == anslen && l < ansl)))
			ansl = l, ansr = r, anslen = r-l+1;
		
		l = r-1;
		memset(cnt, 0, sizeof cnt);
		mcnt = 0;
	}
	cout << ansl << ' ' << ansr;
}