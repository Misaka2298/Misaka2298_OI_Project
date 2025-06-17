#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;

int n, m, sta;
int e[maxn], ne[maxn], w[maxn], h[maxn], idx;
int dist[maxn], cnt[maxn];
bool inq[maxn];

void addedge(int a, int b, int c)
{
	e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

bool spfa1()
{
	queue<int> q;
	for(int i = 1 ; i <= n ; i++)
	{
		q.push(i);
		inq[i] = true;
	}
	while(q.size())
	{
		int t = q.front(); q.pop();
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
					q.push(j);
					inq[j] = true;
				}
			}
		}
	}
	return false;
}

void spfa2()
{
	memset(dist, 0x3f, sizeof dist);
	memset(inq, false, sizeof inq);
	
	queue<int> q;
	q.push(sta);
	inq[sta] = true;
	dist[sta] = 0;
	
	while(q.size())
	{
		int t = q.front(); q.pop();
		inq[t] = false;
		for(int i = h[t] ; i != -1 ; i = ne[i])
		{
			int j = e[i];
			if(dist[j] > dist[t] + w[i])
			{
				dist[j] = dist[t] + w[i];
				if(!inq[j])
				{
					q.push(j);
					inq[j] = true;
				}
			}
		}
	}
}

signed main()
{
	memset(h, -1, sizeof h);
	cin >> n >> m >> sta;
	for(int i = 0 ; i < m ; i ++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		addedge(a, b, c);
	}
	
	if(spfa1())
		cout << "-1";
	else
	{
		spfa2();
		for(int i = 1 ; i <= n ; i++)
		{
			if(dist[i] > 0x3f3f3f3f/2)
				cout << "NoPath" << endl;
			else
				cout << dist[i] << endl;
		}
	}
	
}