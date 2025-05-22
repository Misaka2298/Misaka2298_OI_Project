//https://www.acwing.com/problem/content/910/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
typedef pair<int, int> PII;

int n;
PII ranges[maxn];
int ed, ans;

bool rangecmp(PII a, PII b)
{
	return a.second < b.second;
}

signed main()
{
	cin >> n;
	for(int i = 0 ; i < n ; i ++)
		cin >> ranges[i].first >> ranges[i].second;
	
	sort(ranges, ranges+n, rangecmp);
	
	/*
	for(int i = 0 ; i < n ; i++)
		cout << ranges[i].first << ' ' << ranges[i].second << endl;
	*/
	
	ed = -1e9-1;
	for(int i = 0 ; i < n ; i ++)
	{
		int l = ranges[i].first, r = ranges[i].second;
		if(ed < l)
		{
			ans ++;
			ed = r;
		}
	}
	cout << ans;
}