// B
// expect pts = 20 ~ 50
// maybe 30
// em maybe 20.
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define endl '\n'
const int maxn = 1e6+10;

int T;
int n, m;
LL a[maxn];
LL req[maxn];
LL day, ans;

void init()
{
	memset(req, 0, sizeof req);
	day = ans = 0;
}

void special()
{
	ans = 0;
	for(int i = 1 ; i <= n ; i ++)
	{
		day ++;
		if(req[i] <= day)
		{
			ans ++;
			req[i] = day + a[i] + 1;
		}
	}
	for(int i = n-1 ; i >= 1 ; i --)
	{
		day ++;
		if(req[i] <= day)
		{
			ans ++;
			req[i] = day + a[i] + 1;
		}
	}
	cout << ans << ' ';
	ans = 0;
	for(int i = 1 ; i <= n ; i ++)
	{
		day ++;
		if(req[i] <= day)
		{
			ans ++;
			req[i] = day + a[i] + 1;
		}
	}
	for(int i = n-1 ; i >= 1 ; i --)
	{
		day ++;
		if(req[i] <= day)
		{
			ans ++;
			req[i] = day + a[i] + 1;
		}
	}
	for(int i = 1 ; i < m ; i ++)
		cout << ans << ' ';
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	freopen("collect.in", "r", stdin);
	freopen("collect.out", "w", stdout);
	cin >> T;
	while(T--)
	{
		init();
		cin >> n >> m;
		bool spe = true;
		for(int i = 1 ; i <= n ; i ++)
			cin >> a[i], spe = (a[i] <= 10);
			
		if(spe && n >= 1e4 && m >= 1e4)//expect:10
			special();
		else
			while(m--)//O(2nm),expect:20~40
			{
				ans = 0;
				for(int i = 1 ; i <= n ; i ++)
				{
					day ++;
					if(req[i] <= day)
					{
						ans ++;
						req[i] = day + a[i] + 1;
					}
				}
				for(int i = n-1 ; i >= 1 ; i --)
				{
					day ++;
					if(req[i] <= day)
					{
						ans ++;
						req[i] = day + a[i] + 1;
					}
				}
			cout << ans << ' ';
		}
		cout << endl;
		
	}
}