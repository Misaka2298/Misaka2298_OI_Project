#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;

int n, a;

signed main()
{
	cin >> n;
	while(n--)
	{
		cin >> a;
		int res = a;
		for(int i = 2 ; i <= a / i ; i ++)
			if(a % i == 0)
			{
				res = res / i * (i - 1);
				while(a % i == 0) a /= i;
			}
		if(a > 1) res = res / a * (a - 1);
		
		cout << res << endl;
	}
	return 0;
}