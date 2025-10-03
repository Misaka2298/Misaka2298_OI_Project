//B
#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-7;

double goal;

signed main()
{
	cin >> goal;
	
	double l = -10010, r = 10010, ans = 0;
	while(fabs(l-r) > eps)
	{
		double mid = (l+r)/2;
		if(mid*mid*mid >= goal)
			ans = r = mid;
		else
			l = mid;
	}
	cout << fixed << setprecision(6) << ans;
}