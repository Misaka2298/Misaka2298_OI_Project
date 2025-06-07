#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+10, maxm = 2e5+10;
#define endl '\n'

int n, m, q, fa[maxn], cnt;
struct edge{
	int a, b, w;
}preedges[maxm];
int e[maxn], ne[maxm], h[maxm], w[maxm], idx;
int cost[maxn], pre[maxn];
bool st[maxn];

bool edgecmp(edge a, edge b)
{
	return a.w > b.w;
}

int find(int x)
{
	if(fa[x] != x) return fa[x] = find(fa[x]);
	return fa[x];
}

void addedge(int a, int b, int c)
{
	e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

void kruskal()
{
	cnt = 0;
	memset(h, -1, sizeof h);
	for(int i = 0 ; i < m ; i++)
	{
		if(cnt == n-1)
			break;
		int a = preedges[i].a, b = preedges[i].b, ww = preedges[i].w;
		int ra = find(a), rb = find(b);
		
		if(ra != rb)
		{
			fa[ra] = rb;
			cnt++;
			addedge(a, b, ww); addedge(b, a, ww);
		}
	}
}


int dijkstra(int sta, int ed)
{
	for(int i = 0 ; i < maxn ; i++)
		cost[i] = INT_MIN;
	memset(st, false, sizeof st);
	memset(pre, 0, sizeof pre);
	//st[sta] = true;
	cost[sta] = 0;
	
	for(int i = 1 ; i <= n ; i++)
	{
		int t = -1;
		for(int j = 1 ; j <= n ; j++)
			if(!st[j] && (t==-1 || cost[t] < cost[j]))
				t = j;
		st[t] = true;
		
		for(int j = h[t] ; j != -1 ; j = ne[j])
		{
			int k = e[j];
			if(cost[k] < cost[t] + w[j])
			{
				cost[k] = cost[t] + w[j];
				pre[k] = t;
			}
		}
	}
	
	int now = ed, ans = INT_MAX;
	
	while(now != sta)
	{
		ans = min(ans, w[now]);
		now = pre[now];
	}
	
	return ans;
}


signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> m;
	for(int i = 0 ; i < m ; i ++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		preedges[i] = {a, b, c};
	}
	
	sort(preedges, preedges+m, edgecmp);
	
	for(int i = 1 ; i <= n ; i++)
		fa[i] = i;
			
	kruskal();
	/*
	for(int i = 1 ; i <= n ; i ++)
		cout << fa[i] << endl;
	*/
	
	
	cin >> q;
	while(q--)
	{
		int sta, ed;
		cin >> sta >> ed;
		cout << dijkstra(sta, ed) << endl;
	}
	
}