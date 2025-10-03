// Tree1-H
// Problem: P1827 [USACO3.4] 美国血统 American Heritage
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1827
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// Time: 2025-07-21 20:49:08

#include <bits/stdc++.h>
using namespace std;

string pre, in;
int rr;

void dfs(int l1, int r1, int l2, int r2)
{
	if(l1 > r1 || l2 > r2)
		return;
	int i = in.find(pre[l1]);
	int cnt = i - l2;
	
	dfs(l1+1, l1+cnt, l2, i-1);
	dfs(l1+cnt+1, r1, i+1, r2);
	cout << pre[l1];
}

signed main()
{
	cin >> in >> pre;
	rr= pre.size() - 1;
	
	dfs(0, rr, 0, rr);
}