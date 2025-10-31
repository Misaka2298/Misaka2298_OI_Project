// D
// expect pts = 
// expect diff = 

#include <bits/stdc++.h>
using namespace std;

signed main()
{
	freopen("oula.in", "r", stdin);
	freopen("oula.out", "w", stdout);
	int T;
	cin >> T;
	while(T --)
	{
		int a;
		cin >> a;
		int res = a;
		
		for(int i = 2 ; i <= a/i ; i ++)
		{
			if(a % i == 0)
			{
				res = res - res / i;
				while(a % i == 0)
					a /= i;
			}
		}
		
		if(a > 1)
			res = res - res / a;
		cout << res << endl;		
		
		
		
		
	}
}