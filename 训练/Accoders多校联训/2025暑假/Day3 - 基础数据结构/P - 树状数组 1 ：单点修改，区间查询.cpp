// P
// Problem: P3374 【模板】树状数组 1
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3374
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Time: 2025-07-23 13:39:13

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
#define endl '\n'
#define int long long

int n, q;
int tree[maxn];

int lowbit(int x)
{
	return x & -x;
}

void change(int x, int k)
{
	while(x <= n)
	{
		tree[x] += k;
		x += lowbit(x);
	}
}

int query(int x)
{
	int sum = 0;
	while(x)
	{
		sum += tree[x];
		x -= lowbit(x);
	}
	return sum;
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> q;
	for(int i = 1 ; i <= n ; i ++)
	{
		int a;
		cin >> a;
		change(i, a);
	}
	while(q--)
	{
		int opt, x, y;
		cin >> opt >> x >> y;
		if(opt == 1)
			change(x, y);
		else
			cout << query(y) - query(x-1) << endl;
	}
}