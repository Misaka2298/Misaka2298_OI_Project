// Problem: 你能回答这些问题吗
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/246/
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// Time: 2025-10-23 18:13:12

#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+50;

int n, m;
int a[maxn];

struct SegTree{
	int l, r;
	int maxr, maxl, sum, mx;
}t[maxn*4];

struct Node{
	int maxl, maxr, sum, mx;
};

void pushup(int u)
{
	int l = u*2, r = u*2+1;
	t[u].maxl = max(t[l].maxl, t[l].sum + t[r].maxl);
    t[u].maxr = max(t[r].maxr, t[r].sum + t[l].maxr);
    t[u].mx = max({t[l].mx, t[r].mx, t[l].maxr+t[r].maxl});
	t[u].sum = t[l].sum + t[r].sum;
}

void build(int u, int l, int r)
{
	t[u].l = l, t[u].r = r;
	if(l == r)
	{
		t[u].maxr = t[u].maxl = t[u].sum = t[u].mx = a[l];
		return ;
	}
	
	int mid = (l+r) / 2;
	build(u*2, l, mid);
	build(u*2+1, mid+1, r);
	pushup(u);
}

void change(int u, int x, int y)
{
	if(t[u].l == t[u].r && t[u].l == x)
	{
		t[u].sum = t[u].maxl = t[u].maxr = t[u].mx = y;
		return;
	}
	if(t[u].l > x || t[u].r < x)
		return;
	
	int mid = (t[u].l + t[u].r) / 2;
	if(x <= mid)change(u*2, x, y);
	else change(u*2+1, x, y);
	pushup(u);
}

Node query(int u, int l, int r)
{
	if(t[u].l >= l && t[u].r <= r)
		return {t[u].maxl, t[u].maxr, t[u].sum, t[u].mx};
	int mid = (t[u].l+t[u].r) / 2;
	if(r <= mid)
		return query(u*2, l, r);
	if(l > mid)
		return query(u*2+1, l, r);
	
	Node L = query(u*2, l, r);
	Node R = query(u*2+1, l, r);
	return {max(L.maxl, L.sum+R.maxl), max(R.maxr, R.sum+L.maxr), L.sum+R.sum, max({L.mx, R.mx, L.maxr+R.maxl})};
}

signed main()
{
	cin >> n >> m;
	
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];
	
	build(1, 1, n);
	while(m --)
	{
		int opt, x, y;
		cin >> opt >> x >> y;
		if(opt == 1)
			cout << query(1, min(x, y), max(x, y)).mx << endl;	
		else
			change(1, x, y);
		
	}
}