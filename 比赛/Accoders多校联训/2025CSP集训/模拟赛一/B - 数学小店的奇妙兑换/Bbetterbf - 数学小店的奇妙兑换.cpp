// B betterbf

#include <bits/stdc++.h>
using namespace std;

__int128 n, k;

signed main()
{
	freopen("drink.in", "r", stdin);
	freopen("drink.out", "w", stdout);
	
	string strn, strk;
	cin >> strn >> strk;
	
	for(char chr : strn)
		n = n*10 + (chr - '0');
	
	for(char chr : strk)
		k = k*10 + (chr - '0');
	
	__int128 ans = n / (k-1);
	
	string res;
	
	while(ans)
	{
		res += char('0' + ans % 10);
		ans /= 10;
	}
	reverse(res.begin(), res.end());
	cout << res;
	
	
	
	
	
	
}