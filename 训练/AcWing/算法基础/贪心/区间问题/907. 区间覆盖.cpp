#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
typedef pair<int, int> PII;

int n, st, ed;
PII ranges[maxn];

bool rangecmp(PII a, PII b)
{
	return a.first < b.first;
}

signed main()
{
	cin >> st >> ed >> n;
	for(int i = 0 ; i < n ; i ++)
		cin >> ranges[i].first >> ranges[i].second;
	
	sort(ranges, ranges+n, rangecmp);
	
	int ans = 0;
	bool isSuccess = false;
	for(int i = 0 ; i < n ; i++)
	{
		int j = i, maxr = -2e9;
		while(j<n && ranges[j].first<=st)
		{
			maxr = max(maxr, ranges[j].second);
			j++;
		}
		
		if(maxr < st)
		{
			ans = -1;
			break;
		}
		
		ans ++;
		if(maxr >= ed)
		{
			isSuccess = 1;
			break;
		}
			
		st = maxr;
		i = j-1;
	}
	if(!isSuccess) cout << -1;
	else cout << ans;
}