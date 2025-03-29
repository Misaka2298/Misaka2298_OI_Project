#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+10;
typedef pair<int,int> PII;

int n, m, s;
int e[maxn], ne[maxn], idx, w[maxn], dist[maxn], h[maxn];
bool st[maxn];

void addedge(int a, int b, int c)
{
	e[idx] = b ,w[idx] = c, ne[idx]=h[a], h[a]=idx++;
}

void dijkstra_heap(int sta)
{
	priority_queue<PII,vector<PII>,greater<PII>>heap;
	memset(dist,0x3f,sizeof dist);
	dist[sta] = 0;
	heap.push({0,sta});
	
	while(heap.size())
	{
		auto t = heap.top();
		heap.pop();
		int tver = t.second, tdist = t.first;
		
		if(st[tver]) continue;
		st[tver] = true;
		
		for(int i = h[tver] ; i != -1 ; i = ne[i])
		{
			int j = e[i];
			if(dist[j] > tdist + w[i])
			{
				dist[j] = tdist + w[i];
				heap.push({dist[j], j});
			}
		}
	}
}



signed main()
{
	cin >> n >> m >> s;
	int a, b, c;
	memset(h, -1, sizeof h);
	for(int i = 0 ; i < m ; i++)
	{
		cin >> a >> b >> c;
		addedge(a, b, c);
	}
	
	dijkstra_heap(s);
	
	for(int i = 1 ; i <= n ; i++)
	{
		if(dist[i] != 0x3f3f3f3f) cout << dist[i] << ' ';
		else cout << INT_MAX << ' ';
	}
	
}