// Problem: 货币系统
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1023/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Time: 2025-09-02 20:24:39

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
typedef long long LL;

int n, m;
int v[maxn];
LL f[maxn];

signed main()
{
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++)
		cin >> v[i];
	
	f[0] = 1;
	for(int i = 1 ; i <= n ; i ++)	
		for(int j = v[i] ; j <= m ; j ++)
			f[j] += f[j-v[i]];
	
	cout << f[m];
}