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

/*
#pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1000010], tr[1001000], n;
inline int lowbit(int x) {//卡常！
	return x & -x;
}
inline void update(int v, int p) {
	for (int i = p; i <= n; i += lowbit(i)) {
		tr[i] += v;
	}
}
inline int query(int x) {
	int res = 0;
	for (int i = x; i > 0; i -= lowbit(i)) res += tr[i];
	return res;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		update(a[i] - a[i - 1], i);
	}
	for (int i = 1; i <= q; i++) {
		char op;
		int l, r, x;
		cin >> op;
		if (op == '1') {
			cin >> l >> r >> x;
			update(x, l);
			update(-x, r + 1);
		} else {
			cin >> x;
			cout << query(x) << '\n';
		}
	}
}
*/