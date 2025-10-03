// Problem: P1541 [NOIP 2010 提高组] 乌龟棋
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1541
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// Time: 2025-10-03 20:18:16

#include <bits/stdc++.h>
using namespace std;
const int maxn = 360, maxm = 130;

int n, m;
int g[5];
int nums[maxn];
int f[maxm][maxm][maxm][maxm];

signed main()
{
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++)
		cin >> nums[i];
	for(int i = 1, x ; i <= m ; i ++)
		cin >> x, g[x] ++;
	
	f[0][0][0][0] = nums[1];
	for(int i = 0 ; i <= g[1] ; i ++)
		for(int j = 0 ; j <= g[2] ; j ++)
			for(int k = 0 ; k <= g[3] ; k ++)
				for(int l = 0 ; l <= g[4] ; l ++)
				{
					int pos = i + j*2 + k*3 + l*4 + 1;
					if(i) f[i][j][k][l] = max(f[i][j][k][l], f[i-1][j][k][l] + nums[pos]);
					if(j) f[i][j][k][l] = max(f[i][j][k][l], f[i][j-1][k][l] + nums[pos]);
					if(k) f[i][j][k][l] = max(f[i][j][k][l], f[i][j][k-1][l] + nums[pos]);
					if(l) f[i][j][k][l] = max(f[i][j][k][l], f[i][j][k][l-1] + nums[pos]);
				}
	
	cout << f[g[1]][g[2]][g[3]][g[4]];
}
