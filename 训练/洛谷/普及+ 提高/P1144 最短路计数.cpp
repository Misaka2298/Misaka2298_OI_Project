#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10, maxm = 2e6+10, mod = 100003;
typedef pair<int,int> PII;

int n, m;
int e[maxm*2], ne[maxm*2], h[maxn], idx;
int dist[maxn], cnt[maxn];

void addedge(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
} 

void bfs()
{
	memset(dist, 0x3f, sizeof dist);
	queue<int>q;
	dist[1] = 0;
	cnt[1] = 1;
	q.push(1);
	while(q.size())
	{
		int t = q.front(); q.pop();
		
		for(int i = h[t] ; i != -1 ; i = ne[i])
		{
			int j = e[i];
			if (dist[j] > dist[t] + 1)
			{	
    		dist[j] = dist[t] + 1;
    		cnt[j] = cnt[t];
    		q.push(j);
			}
			else if (dist[j] == dist[t] + 1)
    			cnt[j] = (cnt[j] + cnt[t]) % mod;
		}
	}
}

/*
	for(int i = h[tid] ; i != -1 ; i = ne[i])
		{
			int j = e[i];
			if (dist[j] > dist[t] + 1)
			{	
    		dist[j] = dist[t] + 1;
    		cnt[j] = cnt[tid];
    		heap.push({dist[j], j});
			}
			else if (dist[j] == dist[t] + 1)
    			cnt[j] = (cnt[j] + cnt[tid]) % mod;
		}
*/

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	
	memset(h, -1, sizeof h);
	for(int i = 1 ; i <= m ; i++)
	{
		int x, y;
		cin >> x >> y;
		addedge(x, y); addedge(y, x);
	}
	bfs();
	for(int i = 1 ; i <= n ; i++)
		cout << cnt[i] << endl;
}