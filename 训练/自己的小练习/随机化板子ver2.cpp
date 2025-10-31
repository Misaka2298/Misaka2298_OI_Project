#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

random_device rd;
static mt19937_64 myrand(time(0));

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
	cout << getintrand(l, r) <<endl;
}