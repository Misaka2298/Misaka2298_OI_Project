#include <bits/stdc++.h>
using namespace std;
const int maxn = 1145141, maxm = 1919810, maxk = 110;
#define endl '\n'
typedef pair<int, int> PII;

int n, k, addgas_w, return_w, addstat_w;
int e[maxn], ne[maxm], h[maxn], w[maxn], idx;
bool st[maxn];
int dist[maxn];
int superst, supered;

int get(int fl, int x, int y)
{
	return fl*n*n+((x-1)*n+y);
}

void addedge(int a, int b, int c)
{
	e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;	
}

int dijkstra()
{
	memset(dist, 0x3f, sizeof dist);
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	heap.push({0, superst});
	dist[superst] = 0;
	
	while(heap.size())
	{
		auto t = heap.top(); heap.pop();
		int tid = t.second, tdist = t.first;
		
		if(st[tid]) continue;
		st[tid] = true;
		
		for(int i = h[tid] ; i != -1 ; i = ne[i])
		{
			int j = e[i];
			if(dist[j] > tdist + w[i])
			{
				dist[j] = tdist + w[i];
				heap.push({dist[j], j});
			}
		}
	}
	return dist[supered];
}

signed main()
{
	cin >> n >> k >> addgas_w >> return_w >> addstat_w;
	
	memset(h, -1, sizeof h);
	
	superst = 0, supered = (k+1)*n*n + n * n + 1;
	addedge(superst, get(1, 1, 1), 0);
	for(int i = 2 ; i <= k+1 ; i++)
		addedge(get(i, n, n), supered, 0);
	

	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= n ; j++)
		{
			bool is_stat;
			cin >> is_stat;
			if(is_stat)
			{
				for(int fl = 2 ; fl <= k+1 ; fl++)
					addedge(get(fl,i,j), get(1,i,j), addgas_w);
				if(i > 1) addedge(get(1,i,j), get(2,i-1,j), return_w);
				if(j > 1) addedge(get(1,i,j), get(2,i,j-1), return_w);

				if(i < n) addedge(get(1,i,j), get(2,i+1,j), 0);
				if(j < n) addedge(get(1,i,j), get(2,i,j+1), 0);
			}
			
			else
				for(int fl = 1 ; fl <= k ; fl++)
				{
					if(i > 1) addedge(get(fl,i,j), get(fl+1,i-1,j), return_w);
					if(j > 1) addedge(get(fl,i,j), get(fl+1,i,j-1), return_w);
					if(i < n) addedge(get(fl,i,j), get(fl+1,i+1,j), 0);
					if(j < n) addedge(get(fl,i,j), get(fl+1,i,j+1), 0);
				}
				
			addedge(get(k+1,i,j),get(1,i,j),addstat_w+addgas_w);
		}
		
	cout << dijkstra();
			
	
}
