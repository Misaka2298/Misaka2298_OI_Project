#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;

int n;
int l[maxn], r[maxn];

signed main()
{
	//freopen("sequence.in", "r", stdin);
	//freopen("sequence.out", "w", stdout);
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> l[i] >> r[i];
	
	int ans = 0, nowans = 0;
	int maxl = -2e9;
	for(int i = 1 ; i <= n ; i ++)
	{
		if(r[i] >= maxl && l[i] <= r[i-1])
		{
			nowans ++;
			maxl = max(maxl, l[i]);
			//cout << maxl << ' ' << maxr << endl;
			ans = max(nowans, ans);
		}
		else
		{
			ans = max(nowans, ans);
			maxl = l[i];
			nowans = 0;
		}
	}
	cout << ans;
}