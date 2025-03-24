#include <bits/stdc++.h>
using namespace std;

signed main()
{
	int n,m;
	cin >> n >> m;
	
	vector<int> f(n+1,0);
	f[1] = 1;
	for(int i = 2; i <= m ; ++i)
	{
		for(int j = i ; j<=n ; j+=i)
		{
			f[j] += f[j/i];
		}
	}
	int ans = 0;
	for (int i=2 ; i <= n ; ++i)
	{
		ans ^= f[i];
	}
	cout << ans;
}
