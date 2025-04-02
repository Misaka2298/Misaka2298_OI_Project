#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;

int n, m, q;
long long a[maxn][maxn], s[maxn][maxn];

signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> q;
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= m ; j++)
			cin >> a[i][j];
	
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= m ; j++)
			s[i][j] = a[i][j] + s[i-1][j] + s[i][j-1] - s[i-1][j-1];
	
	int x, y, x2, y2;
	while(q--)
	{
		cin >> x >> y >> x2 >> y2;
		cout << s[x2][y2] - s[x-1][y2] - s[x2][y-1] + s[x-1][y-1] << endl;
	}
}