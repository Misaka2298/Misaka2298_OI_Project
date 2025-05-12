//https://www.acwing.com/problem/content/907/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10, inf = 2e9;
typedef pair<int, int> PII;

int n;
PII range[maxn];

bool rangecmp(PII a, PII b)
{
	return a.second < b.second;
}

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	for(int i = 0 ; i < n ; i ++)
		cin >> range[i].first >> range[i].second;
	
	sort(range, range+n, rangecmp);
	
	/*
	for(int i = 0 ; i < n ; i ++)
		cout << range[i].first << ' ' << range[i].second << endl;
	*/
	
	int ans = 0 , ed = -inf;
	for(int i = 0 ; i < n ; i ++)
		if(range[i].first > ed)
		{
			ans ++;
			ed = range[i].second;
		}
	cout << ans;
}