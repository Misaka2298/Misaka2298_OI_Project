// Problem: P3619 魔法
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3619
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// Time: 2025-11-24 10:44:46

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
typedef long long LL;

int T, n;
LL nowt;
struct Node{
	int t, delta;
}nodes[maxn];
vector<int> udelta, ddelta;

void init_clear()
{
	udelta.clear();
	ddelta.clear();
}

bool cmp1(int a, int b)
{
	return nodes[a].t < nodes[b].t;
}
bool cmp2(int a, int b)
{
	return nodes[a].delta+nodes[a].t > nodes[b].delta+nodes[b].t;
}


void init()
{
	init_clear();
	cin >> n >> nowt;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> nodes[i].t >> nodes[i].delta;
		if(nodes[i].delta >= 0)
			udelta.push_back(i);
		else
			ddelta.push_back(i);
	}
	sort(udelta.begin(), udelta.end(), cmp1);
	sort(ddelta.begin(), ddelta.end(), cmp2);
}

bool check(int opt)
{
	int len;
	if(opt == 1)
		len = udelta.size();
	else
		len = ddelta.size();
	
	for(int i = 0 ; i < len ; i ++)
	{
		int t, delta;
		if(opt == 1)
			t = nodes[udelta[i]].t, delta = nodes[udelta[i]].delta;
		else
			t = nodes[ddelta[i]].t, delta = nodes[ddelta[i]].delta;
		
		if(nowt <= t)
			return false;
		nowt += delta;
		if(nowt <= 0)
			return false;
	}
	return true;
}

void solve()
{
	if(!check(1))
	{
		cout << "-1s" << endl;
		return;
	}
	if(!check(2))
	{
		cout << "-1s" << endl;
		return;
	}
	cout << "+1s" << endl;
}

signed main()
{
	cin >> T;
	while(T --)
	{
		init();
		solve();
	}
}