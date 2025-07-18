#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-7;

int n;
double l, r;
double cons[20];

double f(double x)
{
	double res = 0;
	for(int i = n ; i >= 0 ; i--)
		res += cons[i]*pow(x, i);
	return res;
}

signed main()
{
	cin >> n >> l >> r;
	for(int i = n ; i >= 0 ; i--)
		cin >> cons[i];
	
	while(fabs(l-r) > eps)
	{
		double mid = (l+r)/2;
		double lmid = mid - eps;
		double rmid = mid + eps;
		if(f(lmid) < f(rmid))
			l = mid;
		else
			r = mid;
			
	}
	cout << fixed << setprecision(5) <<  l;
}