// Problem: 数的范围
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/791/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Time: 2025-10-19 15:25:07

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;

int n, m;
vector<int> a;

signed main()
{
	cin >> n >> m;
	for(int i = 0, x ; i < n ; i ++)
		cin >> x, a.push_back(x);
	
	while(m --)
	{
		int x;
		cin >> x;
		int l = lower_bound(a.begin(), a.end(), x) - a.begin();// 左边界
		int r = upper_bound(a.begin(), a.end(), x) - a.begin() - 1;// 右边界
		if(a[l] == x) cout << l << ' ' << r << endl;
		else cout << -1 << ' ' << -1 << endl;
		/* 
		int l = lower_bound(a, a+n, x) - a;
		int r = upper_bound(a, a+n, x) - a - 1;
		*/
		
	}
}