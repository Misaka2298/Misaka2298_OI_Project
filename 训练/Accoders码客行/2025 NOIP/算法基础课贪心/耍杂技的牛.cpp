// Problem: 耍杂技的牛
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/127/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Time: 2025-11-11 19:22:46

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
typedef long long LL;

int n;
LL pre[maxn];
struct Cow{
	LL w, s;
}cows[maxn];

LL ans = -2e9;

bool cmp(Cow a, Cow b)
{
	return a.w+a.s < b.w+b.s;
}

signed main()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> cows[i].w >> cows[i].s;
		
	sort(cows+1, cows+1+n, cmp);
	for(int i = 1 ; i <= n ; i ++)
		pre[i] = cows[i].w + pre[i-1];
	
	for(int i = 1 ; i <= n ; i ++)
		ans = max(pre[i-1] - cows[i].s, ans);
	cout << ans;
}