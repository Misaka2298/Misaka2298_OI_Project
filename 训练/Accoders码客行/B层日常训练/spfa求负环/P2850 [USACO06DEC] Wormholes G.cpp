#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;

int T;
int n, m, qq;
int e[maxn], ne[maxn], h[maxn], idx, w[maxn];
int cnt[maxn], dist[maxn];
bool inq[maxn];

void addedge(int a, int b, int c)
{
	e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

bool spfa()
{
	deque<int> q;
	for(int i = 1 ; i <= n ; i++)
	{
		q.push_back(i);
		inq[i] = true;
	}
	
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
				cnt[j] = cnt[t] + 1;
				if(cnt[j] >= n)
					return true;
				if(!inq[j])
				{
					if (q.size() && dist[q.front()] > dist[j])
					     q.push_front(j);
					else
					     q.push_back(j);
					inq[j] = true;
				}
				
			}
		}
	}
	return false;
	
}

void init()
{
	memset(e, 0, sizeof e);
	memset(h, -1, sizeof h);
	memset(w, 0, sizeof w);
	memset(ne, 0, sizeof ne);
	memset(cnt, 0, sizeof cnt);
	memset(inq, false, sizeof inq);
	memset(dist, 0, sizeof dist);
	idx = 0;
}

signed main()
{
	cin >> T;
	while(T--)
	{
		init();
		cin >> n >> m >> qq;
		for(int i = 0 ; i < m ; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			addedge(a, b, c); addedge(b, a, c);
		}
		for(int i = 0 ; i < qq ; i ++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			addedge(a, b, -c); //addedge(b, a, -c);
		}
		
		if(spfa()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}