#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e4+10;
typedef pair<int,int> PII;

int n;
PII cow[maxn];

signed main()
{
	cin >> n;
	for(int i = 0 ; i < n ; i ++)
	{
		int w , s;
		cin >> w >> s;
		cow[i] = {w+s , s};
	}
	
	sort(cow , cow+n);
	
	int res = -2e9 , sum = 0;
	for(int i = 0 ; i < n ; i++)
	{
		int s = cow[i].second , w = cow[i].first-s ;
		res = max(res , sum - s);
		sum += w;
	}
	cout << res;
	return 0;
}