// Problem: 最大数
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1277/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Time: 2025-07-23 16:17:56

#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
#define endl '\n'

int n, q, p;
struct Node
{
	int l, r;
	int mx;
}tr[maxn*4];

void tr_pushup(int u)
{
	tr[u].mx = max(tr[u*2].mx, tr[u*2+1].mx);
}

void tr_build(int u, int l, int r)
{
	tr[u] = {l, r};
	if(l == r)
		return;
	int mid = (l+r) / 2;
	tr_build(u*2, l, mid);
	tr_build(u*2+1, mid+1, r);
}

int tr_query(int u, int l, int r)
{
	if(tr[u].l >= l && tr[u].r <= r)
		return tr[u].mx;
	
	int mid = (tr[u].l + tr[u].r) / 2;
	int mx = 0;
	
	if(l <= mid)
		mx = tr_query(u*2, l, r);
	if(r > mid)
		mx = max(mx, tr_query(u*2+1, l, r));
	
	return mx;
}

void tr_modify(int u, int x, int v)
{
	if(tr[u].l == x && tr[u].r == x)
		tr[u].mx = v;
	else
	{
		int mid = (tr[u].l + tr[u].r) / 2;
		if(x <= mid)
			tr_modify(u*2, x, v);
		else
			tr_modify(u*2+1, x, v);
		tr_pushup(u);
	}
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> q >> p;
	int last = 0;
	tr_build(1, 1, q);
	
	while(q--)
	{
		char opt;
		int x;
	
		cin >> opt >> x;
		if(opt == 'A')
		{
			tr_modify(1, n+1, ((long long)last + x) % p);
			n ++;
		}
		else
		{
			last = tr_query(1, n-x+1, n);
			cout << last << endl;
		}
	}
}