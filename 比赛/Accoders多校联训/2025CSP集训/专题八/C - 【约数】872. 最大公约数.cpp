// C
// expect pts = 100
// expect diff = idk

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define endl '\n'

int T;
LL a, b;

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	freopen("gcd.in", "r", stdin);
	freopen("gcd.out", "w", stdout);
	cin >> T;
	while(T --)
	{
		cin >> a >> b;
		cout << __gcd(a, b) << endl;
	}
}