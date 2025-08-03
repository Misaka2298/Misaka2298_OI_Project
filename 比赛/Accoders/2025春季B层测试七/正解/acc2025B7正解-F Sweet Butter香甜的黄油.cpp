//T6another try
#include <bits/stdc++.h>
using namespace std;
const int maxn = 8010;
typedef pair<int, int> PII;

int cows[maxn], distsum[maxn];
int e[maxn*2], ne[maxn*2], w[maxn*2], h[maxn], idx;
int n, nodes, roads; 
bool st[maxn];
int dist[maxn];

inline void heap_dijkstra(register int init)
{
	for(register int i = 0 ; i <= nodes ; i ++) dist[i] = 0x3f3f3f3f;
	for(register int i = 0 ; i <= nodes ; i ++) st[i] = false;
	dist[init] = 0;
	priority_queue<PII,vector<PII>,greater<PII>>heap;
	heap.push({0, init});
	
	while(heap.size())
	{
		auto t = heap.top(); heap.pop();
		register int tdist = t.first, tid = t.second;
		
		if(st[tid]) continue;
		else st[tid] = true;
		
		for(register int i = h[tid] ; i != -1 ; i = ne[i])
		{
			register int j = e[i];
			if(dist[j] > tdist + w[i])
			{
				dist[j] = tdist +w[i];
				heap.push({dist[j],j});
			}
		}
	}
}

inline void addedge(register int a, register int b, register int c)
{
	e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

signed main()
{
	cin >> n >> nodes >> roads;
	memset(h, -1, sizeof h);
	for(register int i = 0 ; i < n ; i ++)
	{
		register int cow;
		scanf("%d", &cow);
		cows[cow] ++;
	}
	
	for(register int i = 0 ; i < roads ; i ++)
	{
		register int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		addedge(a, b, c);addedge(b, a, c);
	}
	
	int res = 0x3f3f3f3f;
	for(register int node = 1 ; node <= nodes ; node++)
	{
		register int sum = 0;
		heap_dijkstra(node);
		for(register int subnode = 1 ; subnode <= nodes ; subnode ++)
		{
			sum += dist[subnode] * cows[subnode];
		}
		res = min(sum, res);
	}
	
	cout << res;
}