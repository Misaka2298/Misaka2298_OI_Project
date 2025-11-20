// Problem: P9868 [NOIP2023] 词典
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P9868?contestId=145259
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Time: 2025-11-19 13:29:55

#include <bits/stdc++.h>
using namespace std;
const int maxn = 3010;

int n, m;
string mn[maxn], mx[maxn];

string mx_mn_lpre[maxn];
string mx_mn_rpre[maxn];

bool mncmp(char a, char b)
{
	return a < b;
}

bool mxcmp(char a, char b)
{
	return a > b;
}

void cmp_init()
{
	string now = "{";
	for(int i = 1 ; i <= n ; i ++)
	{
		if(now > mx[i])
			now = mx[i];
		mx_mn_lpre[i] = now;
	}
	now = "{";
	for(int i = n ; i >= 1 ; i --)
	{
		if(now > mx[i])
			now = mx[i];
		mx_mn_rpre[i] = now;
	}
	
	mx_mn_lpre[0] = mx_mn_lpre[n+1] = "{";
	mx_mn_rpre[0] = mx_mn_rpre[n+1] = "{";
}

void init()
{
	cin >> n >> m;
	if(n == 1)
	{
		cout << 1;
		exit(0);
	}
	
	for(int i = 1 ; i <= n ; i ++)
	{
		string str;
		cin >> str;
		sort(str.begin(), str.end(), mncmp);
		mn[i] = str;
		
		sort(str.begin(), str.end(), mxcmp);
		mx[i] = str;
	}
}

void solve()
{
	for(int i = 1 ; i <= n ; i ++)
	{
		if(mx_mn_lpre[i-1] > mn[i] && mx_mn_rpre[i+1] > mn[i])
			cout << 1;
		else
			cout << 0;
	}	
}

signed main()
{
	init();
	cmp_init();
	solve();
}