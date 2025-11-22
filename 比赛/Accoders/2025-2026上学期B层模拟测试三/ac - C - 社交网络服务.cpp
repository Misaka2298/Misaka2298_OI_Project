// C

#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5+10;
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
int e[maxn], ne[maxn], h[maxn], idx;
LL ans;
bool st[maxn];
LL edgecnt, nodecnt;
map<PII, bool> mp;

void addedge(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void fileio()
{
	freopen("sns.in", "r", stdin);
	freopen("sns.out", "w", stdout);
}

void init()
{
	cin >> n >> m;
	memset(h, -1, sizeof h);
	for(int i = 1 ; i <= m ; i ++)
	{
		int a, b;
		cin >> a >> b;
		if(mp[{a, b}] || mp[{b, a}])
			continue;
		mp[{a, b}] = 1;
		mp[{b, a}] = 1;
		addedge(a, b);
		addedge(b, a);
	}
}

void dfs(int u)
{
	nodecnt ++;
	for(int i = h[u] ; i != -1 ; i = ne[i])
	{
		int j = e[i];
		if(j > u)edgecnt ++;
		if(st[j])
			continue;
		st[j] = 1;
		
		dfs(j);
	}
}

void addans(int u)
{
	edgecnt = nodecnt = 0;
	st[u] = 1;
	dfs(u);
	ans += nodecnt * (nodecnt-1) / 2 - edgecnt;
}

void solve()
{
	for(int i = 1 ; i <= n ; i ++)
		if(!st[i])
			 addans(i);
	cout << ans << endl;
}

signed main()
{
	fileio();
	init();
	
	solve();
}