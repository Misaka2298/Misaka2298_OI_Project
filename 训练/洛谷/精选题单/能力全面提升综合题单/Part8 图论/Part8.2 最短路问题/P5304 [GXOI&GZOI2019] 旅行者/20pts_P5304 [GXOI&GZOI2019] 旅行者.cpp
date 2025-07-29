#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10, maxm = 6e5+10;
#define endl '\n'
typedef pair<int, int> PII;

int T;
int n, m, k, ed[maxn];
int e[maxm], ne[maxm], h[maxn], w[maxm], idx;
long long dist[maxn];
bool st[maxn], is_ed[maxn];

long long ans = 0x3f3f3f3f3f3f3f3f;

void addedge(int a, int b, int c)
{
	e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

void init()
{
	memset(e, 0, sizeof e);
	memset(h, -1, sizeof h);
	memset(ne, 0, sizeof ne);
	memset(w, 0, sizeof w);
	memset(is_ed, 0, sizeof is_ed);
	memset(ed, 0, sizeof ed);
	idx = 0;
	ans = 0x3f3f3f3f3f3f3f3f;
}

void heap_dijkstra(int sta)
{
	memset(dist, 0x3f, sizeof dist);
	memset(st, false, sizeof st);
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	dist[sta] = 0;
	heap.push({0, sta});
	
	while(heap.size())
	{
		auto t = heap.top(); heap.pop();
		int tid = t.second, tdist = t.first;
		
		if(st[tid]) continue;
		st[tid] = true;
		
		if(tid != sta && is_ed[tid])
		{
			ans = min(ans, dist[tid]);
			break;
		}
		
		for(int i = h[tid] ; i != -1 ; i = ne[i])
		{
			int j = e[i];
			if(dist[j] > w[i] + tdist)
			{
				dist[j] = w[i] + tdist;
				heap.push({dist[j], j});
			}
		}
	}
	
	//for(int i = 1 ; i <= n ; i++)
		//if(i != sta && is_ed[i])ans = min(ans, dist[i]);
}

signed main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> T;
	while(T--)
	{
		init();
		cin >> n >> m >> k;
		for(int i = 0 ; i < m ; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			addedge(a, b, c);
		}
		for(int i = 0 ; i < k ; i++)
		{
			cin >> ed[i];
			is_ed[ed[i]] = true;
		}
		
		for(int i = 0 ; i < k ; i++)
			heap_dijkstra(ed[i]);
			
		cout << ans << endl;
	}
}

/*
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10, maxm = 6e5+10;
#define endl '\n'
typedef pair<int, int> PII;

int T;
int n, m, k, ed[maxn];
int e[maxn], ne[maxm], h[maxn], w[maxm], idx;
int dist[maxn];
bool st[maxn], is_ed[maxn];

int ans = 0x3f3f3f3f;

void addedge(int a, int b, int c)
{
	e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

void init()
{
	memset(e, 0, sizeof e);
	memset(h, -1, sizeof h);
	memset(ne, 0, sizeof ne);
	memset(w, 0, sizeof w);
	memset(is_ed, 0, sizeof is_ed);
	memset(ed, 0, sizeof ed);
	idx = 0;
	ans = 0x3f3f3f3f;
}

void heap_dijkstra(int sta)
{
	memset(dist, 0x3f, sizeof dist);
	memset(st, false, sizeof st);
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	dist[sta] = 0;
	heap.push({0, sta});
	
	while(heap.size())
	{
		auto t = heap.top(); heap.pop();
		int tid = t.second, tdist = t.first;
		
		if(st[tid]) continue;
		st[tid] = true;
		
		for(int i = h[tid] ; i != -1 ; i = ne[i])
		{
			int j = e[i];
			if(dist[j] > w[i] + tdist)
			{
				dist[j] = w[i] + tdist;
				heap.push({dist[j], j});
			}
		}
	}
	
	for(int i = 1 ; i <= n ; i++)
		if(i != sta && is_ed[i])ans = min(ans, dist[i]);
}

signed main()
{
	cin >> T;
	while(T--)
	{
		init();
		cin >> n >> m >> k;
		for(int i = 0 ; i < m ; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			addedge(a, b, c);
		}
		for(int i = 0 ; i < k ; i++)
		{
			cin >> ed[i];
			is_ed[ed[i]] = true;
		}
		
		for(int i = 0 ; i < k ; i++)
			heap_dijkstra(ed[i]);
			
		cout << ans << endl;
	}
}
*/