// Problem: P2512 [HAOI2008] 糖果传递
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2512
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// Time: 2025-11-11 16:19:42

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
typedef long long LL;

int n;
LL a[maxn], c[maxn], cpyc[maxn];
LL ave;

signed main()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i], ave += a[i];
		
	ave /= n;
	
	for(int i = 1 ; i <= n ; i ++)
		c[i] = c[i-1] + ave - a[i-1];
	
	memcpy(cpyc, c, sizeof c);
	sort(cpyc+1, cpyc+1+n);
	LL x1 = cpyc[(n+1)/2];
	
	LL ans = 0;
	for(int i = 1 ; i <= n ; i ++)
		ans += abs(x1 - c[i]);
	cout << ans;
	
}