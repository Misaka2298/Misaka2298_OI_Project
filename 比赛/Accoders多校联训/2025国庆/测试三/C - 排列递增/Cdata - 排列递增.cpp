// C data
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;

static mt19937 myrand(time(nullptr));

long long getintrand(long long l, long long r)
{
    return uniform_int_distribution<long long>(l, r)(myrand);
}

int n = 1e3;
int a[maxn];

signed main()
{
	freopen("data.in", "w", stdout);
	cout << 1e3 << ' ' << getintrand(1e3, 1e4) << endl;
	srand(time(0));
	for(int i = 1 ; i <= 1e3 ; i ++)
		a[i] = i;
	random_shuffle(a+1, a+n+1);
	for(int i = 1 ; i <= n ; i ++)
		cout << a[i] << ' ';
}