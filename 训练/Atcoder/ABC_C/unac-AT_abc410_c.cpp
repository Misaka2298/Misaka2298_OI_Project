// Problem: AT_abc410_c [ABC410C] Rotatable Array
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/AT_abc410_c
// Memory Limit:  MB
// Time Limit: 2000 ms
// Time: 2025-08-07 08:52:55

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
typedef long long LL;

int n, q;
int arr[maxn];
LL delta;

LL getpos(int x)
{
	return (x - delta + n) % n;
}

signed main()
{
	cin >> n >> q;
	for(int i = 1 ; i <= n ; i ++)
		arr[i] = i;
	while(q--)
	{
		int opt, a, b;
		cin >> opt;
		if(opt == 1)
		{
			cin >> a >> b;
			a = getpos(a);
			arr[a] = b;
		}
		if(opt == 2)
		{
			cin >> a;
			cout << arr[getpos(a)] << endl;
		}
		if(opt == 3)
		{
			cin >> a;
			delta += a;
		}
	}
}