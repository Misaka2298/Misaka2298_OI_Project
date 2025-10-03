// T2 rand
#include <bits/stdc++.h>
using namespace std;

static mt19937 myrand(time(nullptr));

int getintrand(int l, int r)
{
    return uniform_int_distribution<int>(l, r)(myrand);
}

signed main()
{
	freopen("data.in", "w", stdout);
	cout << 1 << endl;
	cout << getintrand(1, 1000000000);
}