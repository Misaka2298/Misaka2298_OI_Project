#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;

int n, m;
long long a[maxn];

struct node{
    int l,r;
    long long sum,lazy;
}t[maxn * 4];

void update(int i)
{
    t[i].sum = t[i*2].sum + t[i*2+1].sum;
}

void pushdown(int i)
{
    if(t[i].
    lazy == 0)
        return;
    t[i*2].lazy += t[i].lazy;
    t[i*2+1].lazy += t[i].lazy;
    t[i*2].sum += (t[i*2].r - t[i*2].l+1) * t[i].lazy;
    t[i*2+1].sum += (t[i*2+1].r - t[i*2+1].l+1) * t[i].lazy;
    t[i].lazy = 0;
}

void buildtree(int i,int l,int r)
{
    t[i].l = l;
    t[i].r = r;
    if(l==r)
    {
        t[i].sum = a[l];
        return;
    }

    int mid = (l+r)>>1;
    buildtree(i*2, l, mid);
    buildtree(i*2+1, mid+1, r);
    update(i);
}

void change(int i,int l,int r,int x)
{
    if(l<=t[i].l && t[i].r <= r)
    {
        t[i].sum += (t[i].r-t[i].l+1) * x;
        t[i].lazy += x;
        return;
    }
    if(t[i].l > r || t[i].r < l)
        return ;
    pushdown(i);
    change(i*2, l, r, x);
    change(i*2+1, l, r, x);
    update(i);
}

int query(int i,int l,int r)
{
    if(l<=t[i].l && t[i].r <= r)
        return t[i].sum;
    if(t[i].l > r || t[i].r < l)
        return 0;
    pushdown(i);
    return query(i*2, l, r) + query(i*2+1, l, r);
}

signed main()
{
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i++)	
		cin >> a[i];
	buildtree(1, 1, n);
	
	long long opt, l, r, k;
	while(m--)
	{
		cin >> opt >> l >> r;
		if(opt == 1)
		{
			cin >> k;
			change(1, l, r, k);
		}
		else
			cout << query(1, l, r) << endl;
	}
}