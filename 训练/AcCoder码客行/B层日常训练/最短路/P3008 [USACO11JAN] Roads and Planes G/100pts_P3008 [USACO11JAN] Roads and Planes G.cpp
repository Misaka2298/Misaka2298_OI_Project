#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
#define endl '\n'

int n, m1, m2, sta, dist[maxn];
int e[maxn], ne[maxn*2], h[maxn], w[maxn*2], idx;
bool inq[maxn];

void addedge(int a, int b, int c)
{
	e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}  

void spfa()
{
	deque<int> q;
	q.push_back(sta);
	inq[sta] = true;
	memset(dist, 0x3f, sizeof dist);
	dist[sta] = 0;
	
	while(q.size())
	{
		int t = q.front(); q.pop_front();
		inq[t] = false;
		
		for(int i = h[t] ; i != -1 ; i = ne[i])
		{
			int j = e[i];
			if(dist[j] > dist[t] + w[i])
			{
				dist[j] = dist[t] + w[i];
				if(!inq[j])
				{
					if(!q.empty() && dist[t] >= dist[q.front()]) 
						q.push_back(j);
					else
						q.push_front(j);
					
					inq[j] = true;
				}
			}
		}
	}
}

signed main()
{
	memset(h, -1, sizeof h);
	cin >> n >> m1 >> m2 >> sta;
	for(int i = 0 ; i < m1 ; i ++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		addedge(a, b, c); addedge(b, a, c);
	}
	for(int i = 0 ; i < m2 ; i ++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		addedge(a, b, c);
	}
	spfa();
	
	for(int i = 1 ; i <= n ; i++)
	{
		if(dist[i] > 0x3f3f3f3f/2) cout << "NO PATH" << endl;
		else cout << dist[i] << endl;
	}
}