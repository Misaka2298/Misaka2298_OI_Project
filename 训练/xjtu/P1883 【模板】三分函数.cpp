#include <bits/stdc++.h>
using namespace std;
const int maxn = 114514, inf = INT_MAX;
const double eps = 1e-9;

int T, n, a[maxn], b[maxn], c[maxn];

double f(double x)
{
	double maxnn = -inf;
	for(int i = 1 ; i <= n ; i ++)
		maxnn = max(maxnn , a[i]*x*x + b[i]*x + c[i]);
	return maxnn;
}

signed main()
{
	cin >> T;
	while(T--)
	{
		cin >> n;
		for(int i = 1 ; i <= n ; i++)
			cin >> a[i] >> b[i] >> c[i];
		
		double l = 0, r = 1000;
		while(r-l > eps)
		{
			double mid1 = (l+l+r)/3;
			double mid2 = (l+r+r)/3;
			if(f(mid1) > f(mid2))
				l = mid1;
			else 
				r = mid2;
		}
		printf("%.4lf\n",f(l));
	}
}