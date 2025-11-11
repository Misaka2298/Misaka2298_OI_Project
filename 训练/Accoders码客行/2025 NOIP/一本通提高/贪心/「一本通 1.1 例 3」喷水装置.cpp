// Problem: #10002. 「一本通 1.1 例 3」喷水装置
// Contest: LibreOJ
// URL: https://loj.ac/p/10002
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Time: 2025-11-10 11:23:49

#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e4+10;
typedef pair<double, double> PDD;

int T;
int n;
double sta, ed;
PDD ranges[maxn];

bool cmp(PDD a, PDD b)
{
	return a.first < b.first;
}

signed main()
{
	cin >> T;
	while(T --)
	{
		double w;
		cin >> n >> ed >> w;
		w /= 2.0;
		sta = 0.0;
		for(int i = 1 ; i <= n ; i ++)
		{
			double a, b;
			cin >> a >> b;
			double eff_r = sqrt(b * b - w * w);
			ranges[i] = {a-eff_r, a+eff_r};
		}
		
		sort(ranges+1, ranges+1+n, cmp);
		
		int ans = 0;
		bool flag = 1;
		while(sta < ed)
		{
			double maxr = -2e9;
			for(int i = 1 ; i <= n ; i ++)
			{
				double l = ranges[i].first, r = ranges[i].second;
				if(sta >= l)
					maxr = max(maxr, r);
			}
			if(maxr <= sta)
			{
				cout << -1 << endl;
				flag = 0;
				break;
			}
			sta = maxr;
			ans ++;
		}
		if(flag)
			cout << ans << endl;
	}
}