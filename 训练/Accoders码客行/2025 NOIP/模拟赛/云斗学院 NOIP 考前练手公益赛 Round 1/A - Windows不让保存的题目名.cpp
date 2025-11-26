// A
// expect pts = 

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
typedef long long LL;

int n, m;
LL a[maxn];
LL st[maxn];
int cnt;

void init()
{
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];
	
}

void sol_nsub1()
{
	LL ans = n;// 0 -> n
	LL mxdis = 0, mndis = 0x3f3f3f3f;
	bool is_haven = 1;
	for(int i = 1 ; i <= n ; i ++)
	{
		if(i == n && cnt >= m)
		{
			is_haven = 0;
			break;
		}
		if(a[i] <= n)st[a[i]] ++;
		cnt ++;
		mxdis = max(mxdis, a[i]);
		mndis = min(mndis, a[i]);
		if(st[i])
		{
			cnt -= st[i];
			st[i] = 0;
		}
	}
	
	//如果都没有可以下车的，车上装不下 n，就只能先把他们往后运, 把最近的那个放下之后回来接 n, 然后往最远的跑
	//cout << is_haven << endl;
	if(!is_haven)
	{
		ans += (mndis-n) * 2;
		mxdis = max(mxdis, a[n]);
		ans += (mxdis-(n+1)) * 2;
	}
	else
	{
		ans += (mxdis-(n+1)) * 2;
	}
	cout << ans + 1;
}

void sol_n()
{
	LL mxdis = 0;
	for(int i = 1 ; i <= n ; i ++)
		mxdis = max(mxdis, a[i]);
	LL backdis = mxdis - (n+1);
	cout << mxdis + backdis;
}

void sol_1()
{
	//cout << n + 1;
	LL ans = 0;
	LL pos = 0;
	for(int i = 1 ; i <= n ; i ++)
	{
		ans += abs(i - pos);// go
		ans += abs(a[i] - i);// to
		pos = a[i];// upd
	}
	ans += abs(pos - (n+1));
	cout << ans;
}

void solve()
{
	if(m == n)
		sol_n();
	if(m == n-1)
		sol_nsub1();
	if(m == 1)
		sol_1();
}

signed main()
{
	init();
	solve();
}