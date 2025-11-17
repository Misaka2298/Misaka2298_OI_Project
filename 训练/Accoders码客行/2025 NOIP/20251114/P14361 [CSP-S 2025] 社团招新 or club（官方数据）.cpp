// Problem: P14361 [CSP-S 2025] 社团招新 / club（官方数据）
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P14361
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Time: 2025-11-15 14:53:13

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;

int T, n;
struct Human{
	int a, b, c, sub, mx, mx2, mxpos;
}humans[maxn];

struct cmp{
	bool operator()(const Human& a, const Human& b) const{
		return a.sub > b.sub;
	}
};

signed main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T --)
	{
		cin >> n;
		for(int i = 1 ; i <= n ; i ++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			int mx = max({a, b, c}), mxpos;
			int mx2;
			if(mx == a) mx2 = max(b, c), mxpos = 1;
			if(mx == b) mx2 = max(a, c), mxpos = 2;
			if(mx == c) mx2 = max(a, b), mxpos = 3;
			humans[i] = {a, b, c, mx-mx2, mx, mx2, mxpos};
		}
		
		priority_queue<Human, vector<Human>, cmp> heap[4];
		int ans = 0;
		for(int i = 1 ; i <= n ; i ++)
		{
			int pos = humans[i].mxpos;
			ans += humans[i].mx;
			heap[pos].push(humans[i]);
		}
		
		for(int i = 1 ; i <= 3 ; i ++)
			while(heap[i].size() > n / 2)
			{
				auto t = heap[i].top(); heap[i].pop();
				ans -= t.sub;
			}
		
		cout << ans << endl;	
	}
}