// B data
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
	cout << "10000" << endl;
	for(int i = 1 ; i <= 1e4 ; i ++)
		cout << getintrand(1, 1e6) << ' ';
	cout << endl;
	cout << 4 << ' ' << getintrand(1, 1e6);
}