// Problem: P3373 【模板】线段树 2
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3373
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// Time: 2025-11-15 13:33:32

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
typedef long long LL;

int n, m, mod;
LL a[maxn];
struct Node{
	LL l, r, sum, addtag, multag;
}tr[maxn*4];

void pushup(int u)
{
	tr[u].sum += tr[u*2].sum + tr[u*2+1].sum;
}

void pushdown(int u)
{
	
}

void build(int u, int l, int r)
{
	tr[u].l = l, tr[u].r = r;
	if(l == r)
	{
		tr[u].sum = a[l];
		return ;
	}
	
	int mid = (l + r) / 2;
	build(u*2, l, mid);
	build(u*2+1, mid+1, r);
	pushup(u);
}

void add(int u, int l, int r, LL c)
{
	
}

signed main()
{
	cin >> n >> m >> mod;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];
	
	build(1, 1, n);
}