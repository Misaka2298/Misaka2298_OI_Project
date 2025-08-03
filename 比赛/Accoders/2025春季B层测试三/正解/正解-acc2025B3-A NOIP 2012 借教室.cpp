#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;

int n, m;
int classes[maxn];
struct req{
	int l, r, w;
}reqs[maxn];
long long s[maxn];

bool check(int x)
{
	memset(s, 0, sizeof s);
	
	for(int i = 1 ; i <= x ; i ++)
	{
		s[reqs[i].l] += reqs[i].w;
		s[reqs[i].r+1] -= reqs[i].w;
	}
	
	for(int i = 1 ; i <= n ; i++)
	{
		s[i] += s[i-1];
		if(s[i] > classes[i])
			return 0;
	}
	return 1;
}

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++)
		cin >> classes[i];
	
	for(int i = 1 ; i <= m ; i++)
	{
		int a, b, c;
		cin >> c >> a >> b;
		reqs[i] = {a, b, c};
	}
	
	int l = 1, r = m, mid, ans = -1;
	while(l <= r)
	{
		mid = (l+r)/2;
		if(check(mid)) l = mid+1;
		else
		{
			ans = mid;
			r = mid-1;
		}
	}
	
	if(ans != -1) cout << -1 << endl << ans;
	else cout << 0;
	
}