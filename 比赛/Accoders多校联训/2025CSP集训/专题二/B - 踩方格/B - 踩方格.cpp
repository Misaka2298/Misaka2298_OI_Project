// B
// expect pts = 100
// expect diff = orange

#include <bits/stdc++.h>
using namespace std;

int ans[] = {1, 3, 7, 17, 41, 99, 239, 577, 1393, 3363, 8119, 19601, 47321, 114243, 275807, 665857, 1607521, 3880899, 9369319, 22619537, 54608393};

int n;
signed main()
{
	freopen("grid.in", "r", stdin);
	freopen("grid.out", "w", stdout);
	cin >> n;
	cout << ans[n];
}