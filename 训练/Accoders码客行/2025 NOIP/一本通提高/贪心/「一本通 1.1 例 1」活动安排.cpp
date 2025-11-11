// Problem: #10000. 「一本通 1.1 例 1」活动安排
// Contest: LibreOJ
// URL: https://loj.ac/p/10000
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Time: 2025-11-10 08:31:48

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
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
	
	int ans = 0, lastr = -1e9;
	for(int i = 1 ; i <= n ; i ++)
	{
		int l = ranges[i].first, r = ranges[i].second;
		if(lastr <= l)
		{
			ans ++;
			lastr = r;
		}
	}
	cout << ans;
	
	
	
	
	
	
	
}