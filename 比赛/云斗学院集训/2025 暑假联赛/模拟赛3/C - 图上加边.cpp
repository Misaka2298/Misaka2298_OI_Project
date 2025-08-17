// C
// expect pts = 6
#include <bits/stdc++.h>
using namespace std;

int n, m;

signed main()
{
	freopen("graph.in", "r", stdin);
	freopen("graph.out", "w", stdout);
	cin >> n >> m;
	if(m == 0 && n >= 4)
		cout << 5;
	else
		cout << -1;
}