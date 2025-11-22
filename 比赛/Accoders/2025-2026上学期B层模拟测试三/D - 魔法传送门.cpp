// D - bf
// expect pts = 50
// expect diff = idk

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010, maxm = 1e6+10, mod = 998244353;
typedef long long LL;

int T;
int n;
int e[maxm], ne[maxm], h[maxn], w[maxm], idx;
int node_w[maxn];
LL ans;

void arr_clear()
{
	memset(node_w, 0, sizeof node_w);
	memset(e, 0, sizeof e);
	memset(ne, 0, sizeof ne);
	memset(h, -1, sizeof h);
	memset(w, 0, sizeof w);
	ans = idx = 0;
}

void addedge(int a, int b, int c)
{
	e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
}

void init()
{
	cin >> n;
	arr_clear();
	
	for(int i = 1 ; i <= n ; i ++)
		cin >> node_w[i];
	
	for(int i = 1 ; i < n ; i ++)
		for(int j = i+1 ; j <= n ; j ++)
		{
			int weight = __builtin_popcount(node_w[i] & node_w[j]);
			if(!weight)
				continue;
			addedge(i, j, weight);
		}
}

void dfs(int u, LL sum)
{
	if(u == n)
	{
		ans = (ans % mod + sum % mod) % mod;
		return ;
	}
	
	for(int i = h[u] ; i != -1 ; i = ne[i])
	{
		int j = e[i];
		dfs(j, (sum % mod * w[i] % mod) % mod);
	}
}

void solve()
{
	dfs(1, 1);
	cout << ans << endl;
}

void fileio()
{
	freopen("magic.in", "r", stdin);
	freopen("magic.out", "w", stdout);
}

signed main()
{
	fileio();
	cin >> T;
	while(T --)
	{
		init();
		
		solve();
	}
}