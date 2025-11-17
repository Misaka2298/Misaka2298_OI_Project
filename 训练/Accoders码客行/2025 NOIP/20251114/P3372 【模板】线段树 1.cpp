// Problem: P3372 【模板】线段树 1
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3372
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Time: 2025-11-15 10:53:33

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
typedef long long LL;

int n, m;
LL a[maxn];
struct Node{
	LL l, r, sum, tag;
}tr[maxn*4];

void pushup(int u)
{
	tr[u].sum = tr[u*2].sum + tr[u*2+1].sum;
}

void pushdown(int u)
{
	if(!tr[u].tag)
		return;
	
	tr[u*2].tag += tr[u].tag;
	tr[u*2+1].tag += tr[u].tag;
	
	tr[u*2].sum += (tr[u*2].r - tr[u*2].l + 1) * tr[u].tag;
	tr[u*2+1].sum += (tr[u*2+1].r - tr[u*2+1].l + 1) * tr[u].tag;
	
	tr[u].tag = 0;
	
}

void build(int u, int l, int r)
{
	tr[u].l = l, tr[u].r = r;
	if(l == r)
	{
		tr[u].sum = a[l];
		return;
	}
	int mid = (l+r) / 2;
	build(u*2, l, mid);
	build(u*2+1, mid+1, r);
	pushup(u);
}

void change(int u, int l, int r, LL c)
{
	if(tr[u].l >= l && tr[u].r <= r)
	{
		tr[u].sum += (tr[u].r - tr[u].l + 1) * c;
		tr[u].tag += c;
		return ;
	}
	if(tr[u].r < l || tr[u].l > r)
		return ;
	
	pushdown(u);
	change(u*2, l, r, c);
	change(u*2+1, l, r, c);
	pushup(u);
}

LL query(int u, int l, int r)
{
	if(tr[u].l >= l && tr[u].r <= r)
		return tr[u].sum;
	if(tr[u].l > r || tr[u].r < l)
		return 0;
	
	pushdown(u);
	return query(u*2, l, r) + query(u*2+1, l, r);
}

signed main()
{
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];
	build(1, 1, n);
	
	while(m --)
	{
		int opt, l, r;
		LL c;
		cin >> opt >> l >> r;
		if(opt == 1)
			cin >> c, change(1, l, r, c);
		else
			cout << query(1, l, r) << endl;
	}
	
}