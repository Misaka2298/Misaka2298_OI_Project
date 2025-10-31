// Problem: P1057 [NOIP 2008 普及组] 传球游戏
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1057
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// Time: 2025-10-27 16:09:11

#include <bits/stdc++.h>
using namespace std;
const int maxn = 50;

int n, m;
int f[maxn][maxn];

signed main()
{
	freopen("box.in", "r", stdin);
	freopen("box.out", "w", stdout);
	cin >> n >> m;
	f[0][1] = 1;
	for(int i = 1 ; i <= m ; i ++)
		for(int j = 0 ; j < n ; j ++)
			f[i][j] = f[i-1][(j-1+n)%n] + f[i-1][(j+1)%n];
	
	cout << f[m][1];
}