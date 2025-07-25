#include <bits/stdc++.h>
using namespace std;
const int maxn = 310;

int n, f[maxn][maxn], s[maxn];

signed main()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> s[i], s[i] += s[i-1];
	
	for(int len = 2 ; len <= n ; len++)
		for(int i = 1 ; i+len-1 <= n ; i++)
		{
			int j = i+len-1;
			f[i][j] = 1e8;
			for(int k = i ; k < j ; k++)
				f[i][j] = min(f[i][j], f[i][k] + f[k+1][j] + s[j] - s[i-1]);
		}
	
	cout << f[1][n];
			
}