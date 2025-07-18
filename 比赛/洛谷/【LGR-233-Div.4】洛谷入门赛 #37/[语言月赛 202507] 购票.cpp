//T2
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL n, a, b;

signed main()
{
	cin >> n >> a >> b;
	if(n == 0)
	{
		cout << 0;
		exit(0);
	}
	if(n*a > b) cout << b;
	else cout << n*a;
}