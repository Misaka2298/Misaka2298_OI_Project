#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;

int n, m, T, p[maxn], x, q;
int e[maxn], ne[maxn], idx, h[maxn], maxp;
bool st[maxn];

void addedge(int a, int b)
{
	e[idx] = b , ne[idx] = h[a] , h[a] = idx++;
}

int iloveccf(int pos, int love)
{
	if(love > maxp)
		return -1;
		
	if(love == p[pos])
		return 0;
		
		
	int dist = 0;
	queue<int>q;
	q.push(pos);
	st[pos] = true;
	
	while(q.size())
	{
		int t = q.front();
		q.pop();
		st[t] = false;
		dist ++;
		for(int i = h[t] ; i != -1 ; i = ne[i])
		{
			int j = e[i];
			if(p[j] >= love)
			{
				return dist;
			}
			else
			{
				//dist ++;
				if(!st[j])
				{
					q.push(j);
					st[j] = true;
				}
			}
		}
	}
	
}

signed main()
{
	cin >> n >> m >> T;
	maxp = -10000;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> p[i];
		maxp = max(maxp, p[i]);
	}
	int u, v;
	memset(h, -1, sizeof h);
	for(int i = 1 ; i <= m ; i++)
	{
		cin >> u >> v;
		addedge(u,v);addedge(v,u);
	}
	
	while(T--)
	{
		memset(st,false,sizeof st);
		cin >> x >> q;
		cout << iloveccf(x, q) << endl;
	}
}