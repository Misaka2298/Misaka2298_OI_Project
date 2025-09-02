// Problem: 买书
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1025/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Time: 2025-09-02 20:13:56

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;

int m, n = 4;
int v[] = {0, 10, 20, 50, 100};
int f[maxn];

signed main()
{
	cin >> m;
	
	f[0] = 1;
	for(int i = 1 ; i <= n ; i ++)
		for(int j = v[i] ; j <= m ; j ++)
			f[j] += f[j-v[i]];
	
	cout << f[m];
}