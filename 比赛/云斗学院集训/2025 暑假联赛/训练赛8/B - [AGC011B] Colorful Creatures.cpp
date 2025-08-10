// B
// Problem: AT_agc011_b [AGC011B] Colorful Creatures
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/AT_agc011_b
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Time: 2025-08-09 14:18:45

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
typedef long long LL;

int n;
LL sz[maxn];
LL s[maxn];

signed main()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> sz[i];
	sort(sz+1, sz+n+1);
	
	for(int i = 1 ; i <= n ; i ++)
		s[i] = s[i-1] + sz[i];
	
	/*
	for(int i = 1 ; i <= n ; i ++)
		cout << s[i] << ' ';
	cout << endl;
	for(int i = 1 ; i <= n ; i ++)
		cout << sz[i] << ' ';
	cout << endl;
	*/
		
	LL ans = 0;
	for(int i = 1 ; i < n ; i ++)
	{
		if(s[i]*2 >= sz[i+1])
			ans ++;
		else
			ans = 0;
	}
	cout << ans+1;
}