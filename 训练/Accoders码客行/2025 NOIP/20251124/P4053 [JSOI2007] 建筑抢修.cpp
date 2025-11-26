// Problem: P4053 [JSOI2007] 建筑抢修
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4053
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// Time: 2025-11-24 09:02:02

#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
typedef long long LL;

int n;
struct Node{
	int t, lim;
}nodes[maxn];
int ans;
priority_queue<int> heap;

bool cmp(Node a, Node b)
{
	return a.lim < b.lim;
}

void init()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> nodes[i].t >> nodes[i].lim;
	sort(nodes+1, nodes+1+n, cmp);
}

void solve()
{
	LL sum = 0;
	for(int i = 1 ; i <= n ; i ++)
	{
		int t = nodes[i].t, lim = nodes[i].lim;
		sum += t;
		heap.push(t);
		
		if(sum <= lim)
			ans ++;
		else
		{
			sum -= heap.top();
			heap.pop();
		}
	}
	cout << ans;
}

signed main()
{
	init();
	
	solve();
}