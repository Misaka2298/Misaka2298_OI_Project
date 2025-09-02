// Problem: 怪盗基德的滑翔翼
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1019/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Time: 2025-08-29 15:25:14

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;

int T;
int n, a[maxn];
int f[maxn], rf[maxn];

signed main()
{
	cin >> T;
	while(T --)
	{
		cin >> n;
		for(int i = 1 ; i <= n ; i ++)
			cin >> a[i];
		memset(f, 0, sizeof f);
		memset(rf, 0, sizeof rf);
		
		for(int i = 1 ; i <= n ; i ++)
		{
			f[i] = 1;
			for(int j = 1 ; j < i ; j ++)
				if(a[j] < a[i])
					f[i] = max(f[i], f[j] + 1);
		}
		
		for(int i = n ; i >= 1 ; i --)
		{
			rf[i] = 1;
			for(int j = n ; j > i ; j --)
				if(a[j] < a[i])
					rf[i] = max(rf[i], rf[j] + 1);
		}
		
		int ans = 0;
		for(int i = 1 ; i <= n ; i ++)
			ans = max(ans, f[i]);
		for(int i = 1 ; i <= n ; i ++)
			ans = max(ans, rf[i]);
		cout << ans << endl;
	}
}