//D
#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-5;

double l, r;

double f(double x)
{
	return (exp(x)+exp(-x))/2+x;
}

signed main()
{
	cin >> l >> r;
	
	while(fabs(l-r) > eps)
	{
		double mid = (l+r)/2;
		double lmid = mid - eps, rmid = mid + eps;
		
		if(f(lmid) < f(rmid)) r = mid;
		else l = mid;
	}
	cout << fixed << setprecision(4) << f(l);
}