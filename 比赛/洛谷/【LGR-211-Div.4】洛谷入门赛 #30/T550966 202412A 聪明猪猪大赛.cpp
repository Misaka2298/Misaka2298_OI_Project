#include <bits/stdc++.h>
using namespace std;

signed main()
{
	int a, b, c, d, x, ans=0;
	cin >> a >> b >> c >> d >> x;
	
	if(x>=a) ans +=b;
	if(x>=c) ans +=d;
	cout << ans;
	return 0;
}