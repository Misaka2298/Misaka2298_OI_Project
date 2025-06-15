#include <bits/stdc++.h>
using namespace std;

double a, b, c, d;
double ans[4];
int idx;

double func(double x)
{
	return a*pow(x,3) + b*pow(x,2) + c*x + d;
}

signed main()
{
	cin >> a >> b >> c >> d;
	double l, r;
	for(int i = -100 ; i <= 99 ; i ++)
	{
		l = i, r = i+1;
		double mid = 0;
		bool flag = true;
		while(abs(l-r) > 1e-6)
		{
			mid = (l+r)/2.0;
			if(func(l) * func(mid) <= 0)
				r = mid;
			else if(func(mid) * func(r) <= 0)
				l = mid;
			else
			{
				flag = false;
				break;
			}
		}
		
		if(!flag)
			continue;
		else
		{
			if(abs(ans[0]-mid)>1e-4 && abs(ans[1]-mid)>1e-4 && abs(ans[2]-mid)>1e-4)
				ans[++idx] = mid;
		}
		
		if(idx==3)
			break;
	}
	for(int i = 1 ; i <= idx ; i ++)
		cout << fixed << setprecision(2) << ans[i] << ' ';
}