// B
// expect pts = 100
// expect diff = orange

#include <bits/stdc++.h>
using namespace std;

int n, ans;

bool check(int x)
{
	int cnt = 0;
	for(int i = 2 ; i <= x / i ; i++)
	{
		if(x % i == 0)
		{
			while(x % i == 0)
				x /= i;
			cnt ++;
		}	
	}
	if(x > 1) cnt ++;
			
	return (cnt == 2);
}

signed main()
{
	freopen("primes.in", "r", stdin);
	freopen("primes.out", "w", stdout);
	cin >> n;
	for(int i = 2 ; i <= n ; i ++)
		if(check(i))
			ans ++;
			
	cout << ans;
}