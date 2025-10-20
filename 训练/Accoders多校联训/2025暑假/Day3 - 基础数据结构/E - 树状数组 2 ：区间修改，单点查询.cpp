// E
// Problem: P3368 【模板】树状数组 2
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3368
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// Time: 2025-07-23 13:59:34

#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6+10;
#define endl '\n'
#define int long long 

int n, q;
long long tree[maxn];
long long a[maxn];

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
		cin >> a[i];
		
	while(q--)
	{
		int opt, x, y, k;
		cin >> opt >> x;
		if(opt == 1)
		{
			cin >> y >> k;
			change(x, k);
			change(y+1, -k);
		}
		else
			cout << a[x] + query(x) << endl;
	}
}
