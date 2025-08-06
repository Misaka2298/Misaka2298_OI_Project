// Problem: AT_abc413_c [ABC413C] Large Queue
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/AT_abc413_c
// Memory Limit:  MB
// Time Limit: 2000 ms
// Time: 2025-08-06 08:05:39

#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
typedef long long LL;
typedef pair<LL, LL> PII;

int n;

signed main()
{
	cin >> n;
	deque<PII> dq;
	LL opt, a, b;
	LL ans = 0;
	while(n--)
	{
		 cin >> opt >> a;
		 if(opt == 1)
		 {
		 	cin >> b;
		 	dq.push_back({a, b});
		 }
		 else
		 {
		 	ans = 0;
		 	while(a > 0)
		 	{
		 		PII t = dq.front(); dq.pop_front();
		 		LL tcnt = t.first, tval = t.second;
		 		if(tcnt < a)
		 		{
		 			a -= tcnt;
		 			ans += tcnt * tval;
		 		}
		 		else
		 		{
		 			ans += a * tval;
		 			tcnt -= a;
		 			dq.push_front({tcnt, tval});
		 			a = 0;
		 		}
		 	}
		 	cout << ans << endl;
		 }
	}
}