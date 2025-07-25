// Problem: 你能回答这些问题吗
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/246/
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// Time: 2025-07-25 10:26:40

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;

int n, q;
int w[maxn];
struct Node
{
	int l, r;
	int sum, tmax, lmax, rmax;	
}tr[maxn * 4];

void tr_pushup(Node &u, Node &l, Node &r)
{
	u.sum = l.sum + r.sum;
	u.lmax = max(l.lmax, l.sum + r.lmax);
	u.rmax = max(r.rmax, r.sum + l.rmax);
	u.tmax = max(max(l.tmax, r.tmax), l.rmax + r.lmax);
}

void tr_pushup(int u)
{
	tr_pushup(tr[u], tr[u*2], tr[u*2+1]);
}

void tr_build(int u, int l, int r)
{
	if(l == r)
		tr[u] = {l, r, w[l], w[l], w[l], w[l]};
	else
	{
		tr[u] = {l, r};
		int mid = (l + r) / 2;
		tr_build(u*2, l, mid);
		tr_build(u*2+1, mid+1, r);
		tr_pushup(u);
	}
}

void tr_modify(int u, int x, int v)
{
	if(tr[u].l == x && tr[u].r == x)
		tr[u] = {x, x, v, v, v, v};
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

Node tr_query(int u, int l, int r)
{
	if(tr[u].l >= l && tr[u].r <= r)
		return tr[u];
	else
	{
		int mid = (tr[u].l + tr[u].r) / 2;
		if(r <= mid)
			return tr_query(u*2, l, r);
		else if(l > mid)
			return tr_query(u*2+1, l, r);
		else
		{
			auto left = tr_query(u*2, l, r);
			auto right = tr_query(u*2+1, l, r);
			Node res;
			tr_pushup(res, left, right);
			return res;
		}
	}
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> q;
	for(int i = 1 ; i <= n ; i ++)
		cin >> w[i];
	tr_build(1, 1, n);
	
	while(q--)
	{
		int opt, a, b;
		cin >> opt >> a >> b;
		if(opt == 1)
			cout << tr_query(1, min(a, b), max(a, b)).tmax << endl;
		else
			tr_modify(1, a, b);
	}
}