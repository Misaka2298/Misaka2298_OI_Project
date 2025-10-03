// T2
// expect pts = 100
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
typedef long long LL;
#define endl '\n'

int n;
LL goal, arr[maxn];
LL ans;

signed main()
{
	freopen("sum.in", "r", stdin);
	freopen("sum.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> goal;
	for(int i = 1 ; i <= n ; i ++)
		cin >> arr[i];
	
	LL sum = 0;
	int l = 1, r = 0;
	
	while(r < n)
	{
		r ++;
		sum += arr[r];	
		
		while(sum > goal && l <= r)
		{
			l ++;
			sum -= arr[l-1];
		}
		
		if(sum == goal)
			ans ++;	
	}
	cout << ans;

	
}