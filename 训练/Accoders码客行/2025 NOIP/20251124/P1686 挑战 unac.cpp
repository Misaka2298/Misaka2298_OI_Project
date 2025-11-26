// Problem: P1686 挑战
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1686
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// Time: 2025-11-24 19:03:24

#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5+10;

int n;
struct Node{
	int n, e, w, s;
}pre[maxn];
struct Ans{
	int len, sta, ed;
}ans;

void init()
{
	cin >> n;
	string str;
	cin >> str;
	for(int i = 1 ; i <= n ; i ++)
	{
		char u = str[i-1];
		pre[i] = pre[i-1];
		if(u == 'N')
			pre[i].n ++;
		if(u == 'E')
			pre[i].e ++;
		if(u == 'W')
			pre[i].w ++;
		if(u == 'S')
			pre[i].s ++;
	}
	for(int i = 1 ; i <= n ; i ++)
		printf("%d N%d S%d W%d E%d\n", i, pre[i].n, pre[i].s, pre[i].w, pre[i].e);
}

void solve()
{
	
}

signed main()
{
	init();
	solve();
}