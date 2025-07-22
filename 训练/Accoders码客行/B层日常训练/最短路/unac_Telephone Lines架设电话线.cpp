#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
typedef pair<int, int> PII;
#define endl '\n';

int n, m, k;
int e[maxn], ne[maxn], w[maxn], h[maxn], idx;
bool st[maxn];
int dist[maxn];

void addedge(int a, int b, int c)
{
	e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

bool dijkstra(int mid)
{
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	memset(dist, 0x3f, sizeof dist);
	memset(st, 0, sizeof st);
	dist[1] = 0;
	heap.push({0, 1});
	//puts ("abc");
	
	while(heap.size())
	{
		auto t = heap.top(); heap.pop();
		int tdist = t.first, tid = t.second;
		
		if(st[tid]) continue;
		st[tid] = 1;
		//cout << tid << endl;
		
		for(int i = h[tid] ; i != -1 ; i = ne[i])
		{
			int j = e[i];
			//cout << j << endl;`
			if(dist[j] > tdist + w[i])
			{
				dist[j] = tdist + w[i];
				heap.push({dist[j], j});
			}
		}
	}
	
	/*
	for(int i = 1 ; i <= n ; i++)
		cout << dist[i] << ' ';
	cout << endl;
	*/
	
	if(dist[n] == 0x3f3f3f3f)
	{
		cout << -1;
		exit(0);
	}
	return dist[n] <= k;
}

signed main()
{
	cin >> n >> m >> k;
	memset(h, -1, sizeof h);
	for(int i = 0 ; i < m ; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		addedge(a, b, c); addedge(b, a, c);
	}
	
	int l = 0, r = 1e6;
	while(l < r)
	{
		int mid = (l+r)/2;
		if(dijkstra(mid))
			r = mid;
		else
			l = mid+1;
	}
	cout << l;
}