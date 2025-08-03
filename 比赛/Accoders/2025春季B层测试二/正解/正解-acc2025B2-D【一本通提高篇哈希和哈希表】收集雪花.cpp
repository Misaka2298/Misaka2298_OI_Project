#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;

unordered_map<int,int>mp;
int n, a, h, ans;

signed main()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> a;
		if(mp[a] > h)
			h = mp[a];
		mp[a] = i;
		ans = max(ans, i-h);
	}
	cout << ans;
}