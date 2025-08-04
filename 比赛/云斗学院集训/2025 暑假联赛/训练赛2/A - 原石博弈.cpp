// T1
// F**k Nim-Game
#include <bits/stdc++.h>
using namespace std;

int n, m;
int T;

signed main()
{
	cin >> T;
	while(T--)
	{
		cin >> n >> m;
		if(m > n)
			swap(m, n);
		if(n - m == 1 && m == 0)
			cout << "Bob" << endl;
		else 
			cout << "Alice" << endl;
	}
	return 0;
}
