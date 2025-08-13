// T2
// expect pts = idk, maybe 30?
// i hate LCA...
#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+10, maxm = 1e6+10, maxk = 18, mod = 1e9+7;

int n, m, root = 1;
int e[maxn], ne[maxn], h[maxn], w[maxn], idx;
int depth[maxn], fa[maxn][maxk+1], dist[maxn];
bool isline1[maxn], isline2[maxn];
int under1, under2;

int ans;

bool spe_is_line;

bool vis[maxn];
vector<int> underset;

void addedge(int a, int b, int c)
{
	e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

void LCA_init()
{
	memset(depth, 0x3f, sizeof depth);
	memset(dist, 0x3f, sizeof dist);
	queue<int> q;
	depth[0] = 0, depth[root] = 1;
	dist[root] = 0;
	q.push(root);
	
	while(q.size())
	{
		int t = q.front(); q.pop();
		for(int i = h[t] ; i != -1 ; i = ne[i])
		{
			int j = e[i];
			if(depth[j] > depth[t] + 1)
			{
				depth[j] = depth[t] + 1;
				q.push(j);
				dist[j] = dist[t] + w[i];
				fa[j][0] = t;
				for(int k = 1 ; k < maxk ; k ++)
					fa[j][k] = fa[fa[j][k-1]][k-1];
			}
			
		}
	}
}

int lca(int a, int b)
{
	if(depth[b] > depth[a])
		swap(a, b);
	
	for(int k = maxk-1 ; k >= 0 ; k --)
		if(depth[fa[a][k]] >= depth[b])
			a = fa[a][k];
	
	if(a == b)
		return a;
	
	for(int k = maxk-1 ; k >= 0 ; k --)
		if(fa[a][k] != fa[b][k])
		{
			a = fa[a][k];
			b = fa[b][k];
		}
	
	return fa[a][0];
}

void getunder(int u, int fa)
{
	bool flag = false;
	for(int i = h[u] ; i != -1; i = ne[i])
	{
		int j = e[i];
		if(vis[j])
			continue;
		vis[j] = true;
		
		if(j != fa)
			flag = true;
		getunder(j, u);
		//cout << j << ' ';
	}
	
	if(!flag)
		underset.push_back(u);
		
}

void underinit()
{
	int mx = 0;
	for(int under : underset)
		if(dist[under] > mx)
		{
			mx = dist[under];
			under1 = under;
		}
	mx = 0;
	for(int under : underset)
		if(dist[under] > mx && under != under1)
		{
			mx = dist[under];
			under2 = under;
		}
	isline1[under1] = 1; isline1[root] = 1;
	isline2[under2] = 1; isline2[root] = 1;
	memset(vis, false, sizeof vis);
	for(int i = h[under1] ; i != -1 && e[i] != root ; i = ne[i])
	{
		int j = e[i];
		if(vis[j]) continue;
		vis[j] = 1;
		isline1[j] = 1;
	}
		
	memset(vis, false, sizeof vis);
	for(int i = h[under2] ; i != -1 && e[i] != root ; i = ne[i])
	{
		int j = e[i];
		if(vis[j]) continue;
		vis[j] = 1;
		isline2[j] = 1;
	}
	
}

int dis(int a, int b, int LCA)
{
	return dist[a] + dist[b] - 2 * dist[LCA];
}

int getspeans(int a, int b)//这里的a一定是小于b的
{
	if(a > b)
		swap(a, b);
	int anc = lca(a, b);
	return max(dis(a,b,anc), min(dis(b,under1,b), dis(a,root,root)));
}

int getans(int a, int b)
{
	if(spe_is_line)
		return getspeans(a, b);
	if(isline1[a] && isline1[b])
	{
		int anc = lca(a, b);
		return max(dis(a, b, anc), min(dis(a, under2, 1), dis(b, under2, 1)));
	}
	else if(isline2[a] && isline2[b])
	{
		int anc = lca(a, b);
		return max(dis(a, b, anc), min(dis(a, under1, 1), dis(b, under1, 1)));
	}
	else if((isline1[a]&&isline2[b]) || (isline2[a]&&isline2[b]))
		return dis(a, b, 1);
	else
	{
		int anc = lca(a, b);
		return max(dis(a, b, anc), min(dis(a, under1, 1), dis(b, under1, 1)));
	}
}
signed main()
{
	freopen("railroad.in", "r", stdin);
	freopen("railroad.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	//underset.resize(maxn/2);
	memset(h, -1, sizeof h);
	m = n - 1;
	for(int i = 1 ; i <= m ; i ++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		addedge(a+1, b+1, c);
		addedge(b+1, a+1, c);
	}
	
	LCA_init();
	
	//memset(vis, false, sizeof vis);
	getunder(root, root);
	underinit();
	
	if(under2 == 0)//是一条链 特判
		spe_is_line = true;
	
	for(int i = 1 ; i <= n ; i ++)
		for(int j = i ; j <= n ; j ++)
			if(i != j)
				ans = (ans + getans(i, j)) % mod;
	
	ans = (ans * 2) % mod;
	cout << ans;
	return 0;
	
}