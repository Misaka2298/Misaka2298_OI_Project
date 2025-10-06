#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

static mt19937 myrand(time(nullptr));

LL getLLrand(LL l, LL r)
{
    return uniform_int_distribution<LL>(l, r)(myrand);
}

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
	LL l, r;
	cin >> l >> r;
	cout << getLLrand(l, r);
}