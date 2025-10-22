// D
// expect pts = 100
// expect diff = idk, 感觉我写麻烦了啊，但是应该能过完的。

#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6+10;
typedef long long LL;
typedef pair<int, pair<int, int>> PIII;

int n;
int e[maxn], ne[maxn], h[maxn], idx;
LL ans, sz[maxn];
int depth[maxn];
vector<PIII> road;

void addedge(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

int sol_size(int u, int fa)
{
	if(h[u] == -1)
	{
		sz[u] = 1;
		return 1;
	}
	
	for(int i = h[u] ; i != -1 ; i = ne[i])
	{
		int j = e[i];
		if(j == fa)
			continue;
		
		int jsz = sol_size(j, u);
		sz[u] += jsz;
	}
	sz[u] +=  1;
	return sz[u];
}

void sol_depth()
{
	queue<int> q;
	q.push(1);
	depth[1] = 1;
	
	while(q.size())
	{
		int t = q.front(); q.pop();
		for(int i = h[t] ; i != -1 ; i = ne[i])
		{
			int j = e[i];
			if(depth[j])
				continue;
			depth[j] = depth[t] + 1;
			q.push(j);
		}
	}
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	cin >> n;
	memset(h, -1, sizeof h);
	for(int i = 1 ; i < n ; i ++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		addedge(a, b); addedge(b, a);
		road.push_back({a, {b, c}});
	}
	
	// 一定是一颗树，所以两个点之间只有一条简单路径。
	
	sol_size(1, 0);// root
	sol_depth();
	
	// 相同深度的节点之间不可能有路
	
	for(auto r : road)
	{
		int x = r.first, y = r.second.first, w = r.second.second;
		if(depth[y] < depth[x])
			swap(x, y);// 保证x在上
		//cout << x << ' ' << y << ' ' << sz[y] << ' ' << sz[1]-sz[y] << endl;
		ans += (LL)abs(sz[y] - (sz[1] - sz[y])) * (LL)w;
	}
	
	cout << ans;
	
	
	
}