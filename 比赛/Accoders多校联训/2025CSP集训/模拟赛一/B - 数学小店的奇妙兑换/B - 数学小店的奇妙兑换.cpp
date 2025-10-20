// B
// expect pts = 0 ~ 30
// expect diff = idk, green?

/*
看起来像很神秘的exgcd推式子。
看不懂。
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL n, k;
LL ans;
LL closek;
LL r;

bool check()
{
	closek = n;
	for(LL i = n ; ; i ++)
		if(i % 3 == 0 && i)
		{
			closek = i;
			break;
		}
	r = closek - n;
	if(closek/k >= r)
	{
		return true;
	}
	return false;
}

signed main()
{
	freopen("drink.in", "r", stdin);
	freopen("drink.out", "w", stdout);
	cin >> n >> k;
	ans += n / k;
	n = (n/k) + (n%k);
	//cout << ans << endl;
	
	bool flag = 1;
	while(flag)
	{
		bool aa = check();
		//cout << n << ' ' << closek << ' ';
		flag = (n >= k || aa);
		if(!flag)
			break;
		if(n >= k)
		{
			ans += n/k;
			n = (n/k) + (n%k);
		}
		else
		{
			ans += closek/k;
			n = (closek/k) + (closek%k) - r;//debug
		}
		//cout << ans << endl;
	}
	cout << ans;
}