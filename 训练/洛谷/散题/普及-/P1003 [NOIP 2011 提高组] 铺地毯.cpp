#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;

int n;
int a[maxn], b[maxn], g[maxn], k[maxn];
int ans;

signed main()
{
	cin >> n;
	
	for(int i = 0 ; i < n ; i++)
		cin >> a[i] >> b[i] >> g[i] >> k[i];
	
	int x, y;
	cin >> x >> y;
	
	for(int i = 0 ; i < n ; i++)
	{
		if(a[i] <= x && x <= a[i]+g[i] && b[i] <= y && y <= b[i]+k[i])
			ans = i+1;
	}
	
	if(ans == 0) cout << -1;
	else cout << ans;
	
	return 0;
}