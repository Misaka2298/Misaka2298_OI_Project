// T3
// expect pts = 
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const double eps = 1e-7;

int T;
double a, b, c, A, B, C;

bool isequal(double x)
{
	return (fabs(a*x*x+b*x+c - (A*x+C)/B) > eps);
}

double twof(double x)
{
	return a*x*x + b*x + c;
}

double onef(double x)
{
	return (A*x+C) / B;
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	freopen("geometry.in", "r", stdin);
	freopen("geometry.out", "w", stdout);
	cin >> T;
	while(T--)
	{
		cin >> a >> b >> c >> A >> B >> C;
		
		double l = -1000, r = 1000;
		while(fabs(l-r) > eps)
		{
			double mid = (l+r) / 2;
			if(a > 0)
			{
				if(twof(mid-eps) > twof(mid+eps))
					l = mid;
				else
					r = mid;
			}
			else
			{
				if(twof(mid-eps) < twof(mid+eps))
					l = mid;
				else
					r = mid;
			}
		}
		
		double twomid = l;
		double ans1 = 0, ans2 = 0;
		if(isequal(twomid))
		{
			cout << "0.000000 (" << fixed << setprecision(6) << twomid << ',' << twof(twomid) << ")" << endl;
			continue;
		}
		{
			l = -1000, r = twomid;
			while(fabs(l-r) > eps)
			{
				double mid = (l+r) / 2;
				if(a > 0)
				{
					if(twof(mid) > onef(mid))
						l = mid;
					else
						r = mid;
				}
				else
				{
					if(twof(mid) < onef(mid))
						l = mid;
					else
						r = mid;
				}
			}
			ans1 = l;
			
			l = twomid, r = 1000;
			while(fabs(l-r) > eps)
			{
				double mid = (l+r) / 2;
				if(a > 0)
				{
					if(twof(mid) < onef(mid))
						l = mid;
					else
						r = mid;
				}
				else
				{
					if(twof(mid) > onef(mid))
						l = mid;
					else
						r = mid;
				}
			}
			ans2 = l;
			
			if(ans1 > ans2)
				swap(ans1, ans2);
				
			cout << "0.000000 (" << fixed << setprecision(6) << ans1 << "," << twof(ans1) << ") (";
			cout << fixed << setprecision(6) << ans2 << ',' << twof(ans2) << ")" << endl;
			//0.000000 (1.070368,6.507427) (-3.737034,40.159239)
		}
	}
}