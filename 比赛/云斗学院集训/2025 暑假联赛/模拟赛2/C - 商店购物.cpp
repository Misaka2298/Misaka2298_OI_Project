// C
// expect pts = 10
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
typedef long long LL;
typedef pair<LL, LL> PLL;
#define endl '\n'

int T;
int n, m;
LL buy[maxn], sol[maxn], rew[maxn];//买入价，售出价，差价
PLL pir[maxn];

void spe1() //m == 0
{
	LL mx = -1e9;
	for(int i = 1 ; i <= n ; i ++)
		mx = max(mx, rew[i]);
	cout << mx << endl;
}

void spe2() //Ai == Bi
{
	cout << 0 << endl;
}

bool cmp(PLL a, PLL b)
{
	return a.first > b.first;
}

signed main()
{
	freopen("shop.in", "r", stdin);
	freopen("shop.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> T;
	while(T--)
	{
		cin >> n >> m;
		bool spe = true;
		for(int i = 1 ; i <= n ; i ++)
		{
			cin >> buy[i] >> sol[i];
			if(buy[i] != sol[i])
				spe = false;
			rew[i] = sol[i] - buy[i];
			pir[i] = {rew[i], buy[i]};
		}
		if(m == 0)
			spe1();
		else if(spe)
			spe2();
		else
		{
			sort(pir+1, pir+1+n, cmp);
			LL nowans = 0, ans = 0;
			for(int i = 1 ; i <= m ; i ++)
			{
				ans = max(ans, nowans);
				nowans += pir[i].first;
				nowans -= pir[i].second;
				
			}
			ans = max(ans, nowans);
			if(ans < 0)
				cout << 0 << endl;
			else
				cout << ans << endl;
		}
		
	}
}