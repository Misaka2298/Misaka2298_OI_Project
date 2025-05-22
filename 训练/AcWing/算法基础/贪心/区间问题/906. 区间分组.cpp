//https://www.acwing.com/problem/content/908/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
typedef pair<int, int> PII;

int n;
PII ranges[maxn];

signed main()
{
	cin >> n;
	for(int i = 0 ; i < n ; i++)
		 cin >> ranges[i].first >> ranges[i].second;
		
	sort(ranges, ranges+n);
	
	priority_queue<int, vector<int>, greater<int>> heap_maxr;
	for(int i = 0 ; i < n ; i ++)
	{
		int l = ranges[i].first, r = ranges[i].second;
		if(!heap_maxr.size() || heap_maxr.top() >= l) heap_maxr.push(r);
		else
		{
			heap_maxr.pop();
			heap_maxr.push(r);
		}
	}
	cout << heap_maxr.size();
}