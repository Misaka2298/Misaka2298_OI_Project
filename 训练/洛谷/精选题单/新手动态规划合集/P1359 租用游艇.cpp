// Problem: P1359 租用游艇
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1359
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// Time: 2025-10-20 18:02:21

#include <bits/stdc++.h>
using namespace std;
const int maxn = 500;

int n;
int r[maxn][maxn];
int f[maxn];

signed main()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		for(int j = i+1 ; j <= n ; j ++)
			cin >> r[i][j];
	
	//cout << r[2][3] << endl;
	
	memset(f, 0x3f, sizeof f);
	f[1] = r[1][1];
	for(int i = 1 ; i <= n ; i ++)
		for(int j = i-1 ; j >= 1 ; j --)
			f[i] = min(f[i], f[i-j]+r[i-j][i]);
	
	cout << f[n];
	
	
	
}