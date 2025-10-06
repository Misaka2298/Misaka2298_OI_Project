// C - baoli
// expect pts = 60
// expect diff = green?

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
typedef long long LL;

int n;
LL k;
int a[maxn], b[maxn];
int cpya[maxn];
LL ans;

bool check()
{
	for(int i = 1 ; i <= n ; i ++)
		if(a[i] != i)	
			return false;
	return true;
}

signed main()
{
	//freopen("arrang.in", "r", stdin);
	//freopen("arrang.out", "w", stdout);
	freopen("data.in", "r", stdin);
	freopen("bf.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> k;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> b[i];
		cpya[i] = a[i] = i;
	}
	for(LL kk = 1 ; kk <= k ; kk ++)
	{
		//memcpy(b, a, sizeof a);
		for(int i = 1 ; i <= n ; i ++)
			cpya[i] = a[b[i]];
		memcpy(a, cpya, sizeof cpya);
		if(check())
		{
			ans ++;
		}
	}
	cout << ans;
}