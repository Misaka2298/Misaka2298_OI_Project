#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
typedef long long LL;

LL n, arr[maxn], s, p, q;

signed main()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
		cin >> arr[i];
	
	for(int i = 2 ; i <= n ; i++)
	{
		s = arr[i] - arr[i-1];
		if(s > 0)
			p += s;
		else 
			q -= s;
	}
	LL ans1 = max(p, q);
	LL ans2 = abs(p-q) + 1; 
	cout << ans1 << endl << ans2;
}