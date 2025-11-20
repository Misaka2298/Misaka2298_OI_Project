// Problem: P11362 [NOIP2024] 遗失的赋值
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P11362
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Time: 2025-11-19 20:25:58

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mod = 1e9+10, maxn = 1e5+10;

int T;
LL n, m, v;
LL ans;
struct Lim{
	int pos, goal;
}lim[maxn];

struct Range{
	int l, r;
}ranges[maxn];
int idx;

LL qmi(LL a, LL b)
{
	LL res = 1 % mod;
	while(b)
	{
		if(b & 1)
			res = (res % mod * a % mod) % mod;
		a = (a % mod * a % mod) % mod;
		b >>= 1;
	}
	return res;
}

bool cmp(Lim a, Lim b)
{
	return a.pos < b.pos;
}

void init()
{
	memset(lim, 0, sizeof lim);
	memset(ranges, 0, sizeof ranges);
	ans = idx = 0;
	
	cin >> n >> m >> v;
	for(int i = 1 ; i <= m ; i ++)
		cin >> lim[i].pos >> lim[i].goal;
	
	sort(lim+1, lim+1+m, cmp);
}


bool conflict_test()//检查冲突
{
	bool haveans = 1;
	for(int i = 1 ; i < m ; i ++)
	{
		if(lim[i].pos == lim[i+1].pos && lim[i].goal != lim[i+1].goal)
		{
			cout << 0 << endl;
			haveans = 0;
			break;
		}
	}
	
	return haveans;
}

void init_ranges()//初始化所有lim区间
{
	ranges[1].l = ranges[1].r = lim[1].pos;
	idx = 1;
	for(int i = 1 ; i <= m ; i ++)
	{
		if(lim[i].pos == ranges[idx].r)
			continue;
		else if(lim[i].pos == ranges[idx].r+1)
			ranges[idx].r = lim[i].pos;
		else
			ranges[++idx].l = ranges[idx].r = lim[i].pos;
	}
}

void sub()//减掉被影响的v^2
{
	if(ranges[1].l == 1)
		ans = (ans % mod - ((ranges[1].r - ranges[1].l + 1) + mod % mod * v % mod * v % mod) % mod) % mod;
	else
		ans = (ans % mod - ((ranges[1].r - ranges[1].l + 2) + mod % mod * v % mod * v % mod) % mod) % mod;
	
	if(ranges[idx].r == n)
		ans = (ans % mod - ((ranges[idx].r - ranges[idx].l + 1) + mod % mod * v % mod * v % mod) % mod) % mod;
	else
		ans = (ans % mod - ((ranges[idx].r - ranges[idx].l + 2) + mod  % mod * v % mod * v % mod) % mod) % mod;
		
	for(int i = 2 ; i < idx ; i ++)
		ans = (ans % mod - ((ranges[i].r - ranges[i].l + 2) % mod * v % mod * v % mod) % mod) % mod;
}

void add()//加上被改变的方案数
{
	if(ranges[1].l == 1)
		ans = (ans % mod + (ranges[1].r - ranges[1].l) % mod + v % mod) % mod;
	else
		ans = (ans % mod + (ranges[1].r - ranges[1].l) % mod + v % mod + v % mod) % mod;
		
	if(ranges[idx].r == n)
		ans = (ans % mod + (ranges[idx].r - ranges[idx].l) % mod + v % mod) % mod;
	else
		ans = (ans % mod + (ranges[idx].r - ranges[idx].l) % mod + v % mod + v % mod) % mod;
		
	for(int i = 2 ; i < idx ; i ++)
		ans = (ans % mod + (ranges[i].r - ranges[i].l) % mod + v % mod + v % mod) % mod;
}

signed main()
{
	cin >> T;
	for(int t = 1 ; t <= T ; t ++)
	{
		init();
		
		if(!conflict_test())
			continue;
		
		LL b = (2 % mod * ((n % mod - 1 % mod) % mod)) % mod;
		ans += qmi(v, b);
		
		init_ranges();
		
		if(idx)
		{
			sub();
			add();
		}
		
		
		cout << ans << endl;
	}
}