// Problem: CF1592B Hemose Shopping
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1592B
// Memory Limit: 250 MB
// Time Limit: 1000 ms
// Time: 2025-10-28 19:17:20

#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
#define endl '\n'

int T;
int n, k;
int a[maxn], b[maxn];

bool check(int l, int r)
{
	for(int i = 1 ; i <= n ; i ++)
		b[i] = a[i];
	sort(b+1, b+1+n);
	for(int i = l ; i <= r ; i ++)
		if(a[i] != b[i])
			return false;
	return true;
}

signed main()
{
	cin >> T;
	while(T --)
	{
		cin >> n >> k;
		for(int i = 1 ; i <= n ; i ++)
			cin >> a[i];
		
		if(n/2 >= k)
		{
			cout << "YES" << endl;
			continue;
		}
		int l = n-k+1, r = k;
		if(check(l, r))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}