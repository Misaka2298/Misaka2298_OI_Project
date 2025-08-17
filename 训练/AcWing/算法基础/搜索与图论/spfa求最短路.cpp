	#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;

int n , m;
int e[maxn], ne[maxn], h[maxn], w[maxn], idx;
int dist[maxn];
bool st[maxn];

void addedge(int a, int b, int c)
{
	e[idx] = b , w[idx] = c , ne[idx] = h[a] , h[a] = idx++;
}

void spfa()
{
	queue<int>q;
	q.push(1);
	st[1] = true;
	memset(dist,0x3f,sizeof dist);
	dist[1] = 0;
	
	while(q.size())
	{
		int t = q.front();
		q.pop();
		
		st[t] = false;
		
		for(int i = h[t] ; i != -1 ; i = ne[i])
		{
			int j = e[i];
			if(dist[j] > dist[t] + w[i])
			{
				dist[j] = dist[t] + w[i];
				if(!st[j])
				{
					st[j] = true;
					q.push(j);
				}
			}
		}
	}
	
	if(dist[n] > 0x3f3f3f3f/2) cout << "impossible";
	else cout << dist[n];
	return;
}

signed main()
{
	cin >> n >> m;
	int a , b , c;
	memset(h,-1,sizeof h);
	for(int i = 0 ; i < m ; i++)
	{
		cin >> a >> b >> c;
		addedge(a,b,c);
	}
	spfa();
	
	return 0;
}