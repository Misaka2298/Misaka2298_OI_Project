// T2 - baoli
// expect pts = 
// expect diff = 

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int T;
LL n, ans;

bool check(LL x)
{
	int goal = x % 10;
	while(x)
	{
		if(x % 10 != goal)
			return false;
		x /= 10;
	}
	return true;
}

signed main()
{
	freopen("data.in", "r", stdin);
	freopen("right.out", "w", stdout);
	cin >> T;
	while(T --)
	{
		cin >> n;
		for(LL i = 1 ; i <= n ; i ++)
			if(check(i))
				ans ++;
		cout << ans << endl;
		ans = 0;
	} 
}