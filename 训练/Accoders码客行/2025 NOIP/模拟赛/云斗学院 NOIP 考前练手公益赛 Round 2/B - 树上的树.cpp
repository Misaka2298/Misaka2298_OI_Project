// Problem: B. 树上的树
// Contest: Yun Dou Xue Yuan
// URL: https://yundouxueyuan.com/p/5417?tid=691f87efb213ea989e32092d
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// Time: 2025-11-27 12:13:38

// expect pts = 10

#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
#define endl '\n'

int T;
int n;
int e[maxn], ne[maxn], h[maxn], idx;
bool st[maxn];
double w[maxn];
double ans;
int ans_sel;

void init_clear()
{
	memset(e, 0, sizeof e);
	memset(ne, 0, sizeof ne);
	memset(h, -1, sizeof h);
	memset(w, 0, sizeof w);
	ans = 0, ans_sel = 0;
}

void addedge(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void init()
{
	init_clear();
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> w[i];
	for(int i = 1 ; i < n ; i ++)
	{
		int a, b;
		cin >> a >> b;
		addedge(a, b);
		addedge(b, a);
	}
}

void sol_sel(int sel)
{
	int cnt = 0;
	while(sel)
	{
		if(sel & 1)
			st[n-cnt] = 1;
		else
			st[n-cnt] = 0;
		cnt ++;
		sel >>= 1;
	}
}

void check(int sel)
{
	sol_sel(sel);
	
	double res = 0;
	for(int i = 1 ; i <= n ; i ++)
	{
		if(!st[i])
			continue;
		double x = w[i];
		int cnt = 1;
		for(int k = h[i] ; k != -1 ; k = ne[k])
		{
			int j = e[k];
			if(st[j])
				cnt ++;
		}
		res += (x / cnt);
	}
	
	if(res > ans)
	{
		//cout << res << ' ' << sel << endl;
		ans = res;
		ans_sel = sel;
	}
}

void outans()
{
	cout << fixed << setprecision(6) << ans << endl;
	sol_sel(ans_sel);
	for(int i = 1 ; i <= n ; i ++)
		cout << st[i];
	cout << endl;
}

void solve()
{
	for(int i = 0 ; i < (1 << n) ; i ++)
		check(i);
	st[1] = 0;
	outans();
	
}

void fstio()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
}

signed main()
{
	fstio();
	cin >> T;
	while(T --)
	{
		init();
		solve();
	}
}