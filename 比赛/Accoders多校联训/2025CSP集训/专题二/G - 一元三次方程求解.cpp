// G
// expect pts = <100
// expect diff = orange

#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
const ld eps = 1e-4;

ld a, b, c, d;

ld f(ld x)
{
	return a*x*x*x + b*x*x + c*x + d;
}

signed main()
{
	freopen("root.in", "r", stdin);
	freopen("root.out", "w", stdout);
	cin >> a >> b >> c >> d;
	//cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
	 
	for(int i = -100 ; i < 100 ; i ++)
	{
		ld j = i + 1;
		
		ld l = i, r = j;
		ld ans = -1000;
		while(fabs(l-r) > eps)
		{
			ld mid = (l+r) / 2;
			//cout << f(mid) << ' ' << f(l) << endl;
			if(f(mid) * f(l) <= 0)
			{
				r = mid;
				ans = mid;
			}
			else
				l = mid;
				
			//cout << mid << ' ';
		}
		//cout << endl;
		if(ans != -1000)
			cout << fixed << setprecision(2) << ans << ' ';
	}
	
	
}