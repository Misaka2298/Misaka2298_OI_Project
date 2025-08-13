#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7+10;
const double eps = 0.995;

int n, arr[maxn];
int nowans, anspos = 1;
double nowt = 9000, endt = 1e-5;

static mt19937 myrand(time(0));

int getintrand(int l, int r)
{
	return uniform_int_distribution<int>(l, r)(myrand);
}

double getdoublerand(double l, double r)
{
	return uniform_real_distribution<double>(l, r)(myrand);
}

signed main()
{
	cin >> n;
	for(int i = 1; i <= n; i ++)
		cin >> arr[i];
	
	nowans = arr[1];
	while(nowt > endt)
	{
		int newpos = getintrand(max(1, anspos-100), min(n, anspos+100));
		int newans = arr[newpos]
		double delta = nowans - newans;
		if(delta <= 0)
		{
			nowans = newans;
			anspos = newpos;
		}
		else if(getdoublerand(0, 1) < exp((double)-delta/nowt))
		{
			nowans = newans;
			anspos = newpos;
		}
		nowt *= eps;
	}
	cout << nowans;
}