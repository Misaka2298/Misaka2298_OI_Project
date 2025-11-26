// Problem: P1090 [NOIP 2004 提高组] 合并果子
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1090
// Memory Limit: 125 MB
// Time Limit: 800000 ms
// Time: 2025-11-24 13:06:09

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7+10;
typedef long long LL;

int n;
priority_queue<LL, vector<LL>, greater<LL>> heap;
LL ans;

void init()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
	{
		int x;
		cin >> x;
		heap.push(x);
	}
}

void solve()
{
	while(heap.size() > 1)
	{
		LL a = heap.top(); heap.pop();
		LL b = heap.top(); heap.pop();
		heap.push(a+b);
		ans += a+b;
	}
	cout << ans;
}

signed main()
{
	init();
	solve();
}