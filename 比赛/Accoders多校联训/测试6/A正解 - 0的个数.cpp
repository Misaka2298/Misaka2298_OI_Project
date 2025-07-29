#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;

int n;
long long cnt2, cnt5;

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	freopen("zero.in", "r", stdin);
	freopen("zero.out", "w", stdout);
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
	{
		long long a;
		cin >> a;
		if(a == 0)
		{
			cout << 1;
			return 0;
		}
		while(a % 2 == 0)
		{
			cnt2 ++;
			a /= 2;
		}
		while(a % 5 == 0)
		{
			cnt5 ++;
			a /= 5;
		}
	}
	cout << min(cnt2, cnt5);
}