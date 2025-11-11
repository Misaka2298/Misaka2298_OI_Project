// Problem: 合并果子
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/150/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Time: 2025-11-11 19:10:50

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n;
priority_queue<LL, vector<LL>, greater<LL>> heap;
LL ans;

signed main()
{
	cin >> n;
	for(LL i = 1, x ; i <= n ; i ++)
		cin >> x, heap.push(x);
	
	while(heap.size() > 1)
	{
		LL a = heap.top(); heap.pop();
		LL b = heap.top(); heap.pop();
		heap.push(a + b);
		ans += a + b;
	}
	
	cout << ans;
}