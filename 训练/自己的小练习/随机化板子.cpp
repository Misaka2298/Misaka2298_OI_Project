#include <bits/stdc++.h>
using namespace std;

static mt19937 myrand(time(nullptr));

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
	int l, r;
	cin >> l >> r;
	cout << getintrand(l, r);
}