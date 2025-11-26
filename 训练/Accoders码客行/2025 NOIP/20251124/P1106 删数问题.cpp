// Problem: P1106 删数问题
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1106
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// Time: 2025-11-24 13:07:51

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+10;

int lim;
int stk[maxn], tail;
string num;

void init()
{
	cin >> num >> lim;
}

void push_stk()
{
	int cnt = 0;
	for(int i = 0 ; i < num.size() ; i ++)
	{
		int u = num[i] - '0';
		
		while(stk[tail] > u && cnt < lim)
			tail --, cnt ++;
		stk[++tail] = u;
	}
	while(cnt < lim && stk[tail-1] != 0)
		tail --, cnt ++;
}

void out_stk()
{
	int sta = 1;
	for(int i = 1 ; i <= tail ; i ++)
		if(stk[i] != 0)
		{
			sta = i;
			break;
		}
	for(int i = sta ; i <= tail ; i ++)
		cout << stk[i];
}

void solve()
{
	push_stk();
	out_stk();
}

signed main()
{
	init();
	solve();
}