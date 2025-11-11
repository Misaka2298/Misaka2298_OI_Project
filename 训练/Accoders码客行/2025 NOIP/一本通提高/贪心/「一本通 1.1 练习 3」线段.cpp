// Problem: #10007. 「一本通 1.1 练习 3」线段
// Contest: LibreOJ
// URL: https://loj.ac/p/10007
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Time: 2025-11-10 20:24:42

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
typedef pair<int, int> PII;

int n;
PII ranges[maxn];

bool cmp(PII a, PII b)
{
	return a.second < b.second;
}

signed main()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> ranges[i].first >> ranges[i].second;
	
	sort(ranges+1, ranges+1+n, cmp);
	
	int ans = 0, maxr = 0;
	
	for(int i = 1 ; i <= n ; i ++)
	{
		int l = ranges[i].first, r = ranges[i].second;
		if(l >= maxr)
		{
			maxr = r;
			ans ++;
		}
	}
	
	cout << ans;
}