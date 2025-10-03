//T4
//expect pts = what f**k i know
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7+10;
#define endl '\n'
typedef pair<int, int> Pkk;

int n, m, k, q;
long long e[maxn], ne[maxn], h[maxn], idx;
long long dist[maxn];
int color;
bool st[maxn];

vector<long long> kq[45];

void addedge(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int getid(int x, int y)
{
	return x*1000+y;
}

void dijkstra(int sta)
{
	memset(dist, 0x3f, sizeof dist);
	memset(st, false, sizeof st);
	priority_queue<Pkk,vector<Pkk>,greater<Pkk>> heap;
	dist[sta] = 0;
	heap.push({0, sta});
	
	while(heap.size())
	{
		auto t = heap.top();
		heap.pop();
		int tid = t.second, tdist = t.first;
		
		if(st[tid]) continue;
		st[tid] = true;
		
		for(int i = h[tid] ; i != -1 ; i = ne[i])
		{
			int j = e[i];
			if(dist[j] > tdist + 1)
			{
				dist[j] = tdist + 1;
				heap.push({dist[j],j});
			}
		}
	}
}

signed main()
{
	freopen("superhero.in", "r", stdin);
	freopen("superhero.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	memset(h, -1, sizeof h);
	cin >> n >> m >> k;
	
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= m ; j ++)
		{
			cin >> color;
			kq[color].push_back(getid(i,j));
		}
			
	
	cin >> q;
	if(k == 1)
	{
		while(q--)
			cout << 0 << endl;
		exit(0);
	}
			
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= m ; j ++)
		{
			addedge(getid(i,j), getid(i-1, j));
			addedge(getid(i,j), getid(i+1, j));
			addedge(getid(i,j), getid(i, j+1));
			addedge(getid(i,j), getid(i, j-1));
			
			addedge(getid(i-1, j), getid(i,j));
			addedge(getid(i+1, j), getid(i,j));
			addedge(getid(i, j+1), getid(i,j));
			addedge(getid(i, j-1), getid(i,j));
		}
			
	if(!(k == n*m))
	{
		for(int kk = 1 ; kk <= k ; kk ++)
		{
			int len = kq[kk].size();
			for(int i = 0 ; i < len ; i ++)
				
		}
	}
	
	while(q--)
	{
		int stx, sty, edx, edy;
		cin >> stx >> sty >> edx >> edy;
		int sta = getid(stx,sty), ed = getid(edx,edy);
	
		dijkstra(sta);
		cout << dist[ed] << endl;
	}
}