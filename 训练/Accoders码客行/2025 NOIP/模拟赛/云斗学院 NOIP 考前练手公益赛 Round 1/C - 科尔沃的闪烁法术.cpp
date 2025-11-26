// C
// expect pts = 10

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 320, maxm = 15;

int n, m;
int b[maxm], l[maxm], r[maxm];
bool mst[maxm], nst[maxn];
LL ans;

void init()
{
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++)
		cin >> b[i] >> l[i] >> r[i];
}

bool check(int u)
{
	bool backnst[maxn];
	memmove(backnst, nst, sizeof nst);
	bool can = 0;
	for(int i = l[u] ; i <= r[u] ; i ++)
		if(nst[i] == 0)
		{
			can = 1;
			nst[i] = 1;
		}
	if(!can)
	{
		memmove(nst, backnst, sizeof backnst);
		return false;
	}
	return true;
}

void dfs(int u, LL sum)
{
	if(u == m+1)
	{
		ans = max(ans, sum);
		return ;
	}
	
	bool innerbkp[maxn];
	for(int i = 1 ; i <= m ; i ++)
	{
		if(mst[i])
			continue;
		memmove(innerbkp, nst, sizeof nst);
		if(!check(i))
			continue;
		mst[i] = 1;
		dfs(u+1, sum + b[i]);
		memmove(nst, innerbkp, sizeof innerbkp);
		mst[i] = 0;
		ans = max(ans, sum + b[i]);
	}
}

void solve()
{
	dfs(1, 0);
	cout << ans;
}

signed main()
{
	init();
	solve();
	
}