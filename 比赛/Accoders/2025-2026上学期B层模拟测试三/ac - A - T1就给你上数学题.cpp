// A
// expect pts = 100
// expect diff = orange

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int T;
int a, b;

void init()
{
	cin >> a >> b;
}

void solve()
{
	if(a == b)
	{
		cout << 0 << endl;
		return ;
	}
	
	if(a < b)
	{
		if(a%2 != b%2)
			cout << 1 << endl;
		else
		{
			if(((b - a) / 2) % 2 == 0)
				cout << 3 << endl;
			else
				cout << 2 << endl;
		}
	}
	
	if(a > b)
	{
		if(a%2 == b%2)
			cout << 1 << endl;
		else
			cout << 2 << endl;
	}
}

void fileio()
{
	freopen("math.in", "r", stdin);
	freopen("math.out", "w", stdout);
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	fileio();
	cin >> T;
	while(T --)
	{
		init();
		
		solve();
	}
}