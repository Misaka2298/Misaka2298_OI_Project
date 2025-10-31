// G
// expect pts = 100
// expect diff = idk

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int T;

int exgcd(int a, int b, int &x, int &y)
{
	if(b == 0)
	{
		x = 1, y = 0;
		return a;
	}
	
	int x0 = x, y0 = y;
	int gcd = exgcd(b, a%b, x0, y0);
	
	x = y0, y = x0 - a / b * y0;
	return gcd;
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	freopen("euclid.in", "r", stdin);
	freopen("euclid.out", "w", stdout);
	cin >> T;
	
	while(T --)
	{
		int a, b, x, y;
		cin >> a >> b;
		exgcd(a, b, x, y);
		cout << x << ' ' << y << endl;
	}
	
	
	
	
	
	
}