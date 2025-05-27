#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
typedef pair<int, int> PII;
#define endl '\n';

int n, m, x;
int e[maxn], ne[maxn], h[maxn], idx, w[maxn];
int dist[maxn], rdist[maxn];
int a[maxn], b[maxn], c[maxn];
bool st[maxn];

void addedge(int a, int b, int c)
{
	e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

void dijkstra()
{
	memset(dist, 0x3f, sizeof dist);
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	dist[x] = 0;
	heap.push({0, x});
	
	while(heap.size())
	{
		auto t = heap.top(); heap.pop();
		int tdist = t.first, tid = t.second;	
		
		if(st[tid]) continue;
		st[tid] = 1;
		
		for(int i = h[tid] ; i != -1 ; i = ne[i])
		{
			int j = e[i];
			if(dist[j] > tdist + w[i])
			{
				dist[j] = tdist + w[i];
				heap.push({dist[j],j});
			}
		}
	}
}
 
void rdijkstra()
{
	memset(rdist, 0x3f, sizeof rdist);
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	rdist[x] = 0;
	heap.push({0, x});
	
	while(heap.size())
	{
		auto t = heap.top(); heap.pop();
		int tdist = t.first, tid = t.second;	
		
		if(st[tid]) continue;
		st[tid] = 1;
		
		for(int i = h[tid] ; i != -1 ; i = ne[i])
		{
			int j = e[i];
			if(rdist[j] > tdist + w[i])
			{
				rdist[j] = tdist + w[i];
				heap.push({rdist[j],j});
			}
		}
	}
}

signed main()
{
	cin >> n >> m >> x;
	memset(h, -1, sizeof h);
	for(int i = 0 ; i < m ; i++)
	{
		int aa, bb, cc;
		cin >> aa >> bb >> cc;
		a[i] = aa, b[i] = bb, c[i] = cc;
		addedge(bb, aa, cc);
	}
	
	dijkstra();
	memset(e, 0, sizeof e); memset(h, -1, sizeof h); memset(ne, 0, sizeof ne); memset(w, 0, sizeof w);
	memset(st, false, sizeof st);
	idx = 0;
	for(int i = 0 ; i < m ; i++)
		addedge(a[i], b[i], c[i]);
	rdijkstra();
	
	int ans = -1;
	for(int i = 1 ; i <= n ; i ++)
	{
		ans = max(ans, dist[i] + rdist[i]);
		//cout << dist[i] << ' ' << rdist[i] << endl;
	}
	
	cout << ans;
}