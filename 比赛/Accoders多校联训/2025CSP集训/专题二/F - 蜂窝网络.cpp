// F
// expect pts = 50 ~ 100
// expect diff = idx
// expect error = TLE 

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;

int n, m;
int city[maxn], tower[maxn];
int ans = 0;

bool check(int r)
{
	for(int i = 1 ; i <= n ; i ++)
	{
		bool flag = false;
		for(int j = 1 ; j <= m ; j ++)
		{
			if(tower[j]-r <= city[i] && tower[j]+r >= city[i])
			{
				flag = 1;
				break;
			}
		}
		if(!flag) return false;
	}
	return true;
}

signed main()
{
	freopen("network.in", "r", stdin);
	freopen("network.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++)
		cin >> city[i];
	for(int i = 1 ; i <= m ; i ++)
		cin >> tower[i];
	
	sort(city+1, city+1+n);
	sort(tower+1, tower+1+n);
	
	int l = 0, r = 1e9;
	while(l <= r)
	{
		int mid = (l+r) / 2;
		if(check(mid))
		{
			ans = mid;
			r = mid - 1;
		}
		else
			l = mid + 1;
	}
	
	cout << ans;
}

/*
bool check(int r)
{
	for(int i = 1 ; i <= n ; i ++)
	{
		bool flag = false;
		for(int j = 1 ; j <= m ; j ++)
		{
			if(tower[j]-r <= city[i] && tower[j]+r >= city[i])
			{
				flag = 1;
				break;
			}
		}
		if(!flag) return false;
	}
	return true;
}
*/


