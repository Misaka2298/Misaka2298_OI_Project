// Problem: P8818 [CSP-S 2022] 策略游戏
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P8818?contestId=90216
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Time: 2025-11-20 09:33:18

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010, maxm = 1e5+10;
typedef long long LL;

int n, m, q;
LL x[maxn], y[maxn];
struct Node{
	int l, r;
	LL mn;
}tr[maxn][maxn*4];

void init()
{
	cin >> n >> m >> q;
	for(int i = 1 ; i <= n ; i ++)
		cin >> x[i];
	for(int i = 1 ; i <= m ; i ++)
		cin >> y[i];
}

void pushup(int layer, int u)
{
	tr[layer][u].mn = min(tr[layer][u*2].mn, tr[layer][u*2+1].mn);
}

void build(int layer, int u, int l, int r)
{
	tr[layer][u].l = l, tr[layer][u].r = r;
	if(l == r)
	{
		tr[layer][u].mn = x[layer] * y[l];
		return ;
	}
	
	int mid = (l + r) / 2;
	build(layer, u*2, l, mid);
	build(layer, u*2+1, mid+1, r);
	pushup(layer, u);
}

LL query(int layer, int u, int l, int r)
{
	if(tr[layer][u].l >= l && tr[layer][u].r <= r)
		return tr[layer][u].mn;
	
	if(tr[layer][u].r < l || tr[layer][u].l > r)
		return 1e18+10;
	
	return min(query(layer, u*2, l, r), query(layer, u*2+1, l, r));
}

void solve()
{
	for(int Q = 1 ; Q <= q ; Q ++)
	{
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		
		LL ans = -(1e18+10);
		
		for(int i = l1 ; i <= r1 ; i ++)
			ans = max(query(i, 1, l2, r2), ans);
		cout << ans << endl;
	}
}

signed main()
{
	init();
	
	for(int i = 1 ; i <= n ; i ++)
		build(i, 1, 1, m);
	
	solve();
	
}