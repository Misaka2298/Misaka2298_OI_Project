// Problem: P14520 【MX-S11-T1】战争游戏
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P14520?contestId=287508
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Time: 2025-11-25 18:57:12

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
#define endl '\n'
typedef long long LL;

int n, T;
LL sold[maxn], pre[maxn];

void init()
{
	memset(pre, 0, sizeof pre);
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> sold[i], pre[i] = pre[i-1] + sold[i];
}

LL get(int l, int r)
{
	return pre[r] - pre[l-1];
}

//(get(1, i+1) > get(i+2, n))

void solve()
{
	for(int i = 1 ; i < n ; i ++)
	{
		if(sold[i] > sold[i+1])
		{
			if(sold[i+2] >= sold[i] + sold[i+1])
				cout << (get(1, i) > get(i+1, n));
			else
				cout << (get(1, i+1) > get(i+2, n));
		}
		else
			cout << (get(1, i) > get(i+1, n));
	}
	cout << endl;
}

signed main()
{
	cin >> T;
	while(T --)
	{
		init();
		solve();
	}
}