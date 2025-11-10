// Problem: #10006. 「一本通 1.1 练习 2」数列分段
// Contest: LibreOJ
// URL: https://loj.ac/p/10006
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Time: 2025-11-10 20:16:29

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;

int n, lim;
int a[maxn];
int ans;

signed main()
{
	cin >> n >> lim;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];
	a[n+1] = 0x3f3f3f3f;
	
	int sum = 0;
	for(int i = 1 ; i <= n ; i ++)
	{
		sum += a[i];
		if(sum + a[i+1] > lim)
		{
			sum = 0;
			ans ++;
		}	
	} 
	cout << ans;
}