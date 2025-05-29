#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
#define endl '\n';
typedef pair<int, int> PII;

int n, m, k;
int e[maxn], ne[maxn], h[maxn], w[maxn], idx;
int dist[maxn];
bool st[maxn];
queue<int>q;

void addedge(int a, int b, int c)
{
	e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

bool isLessthanK(int check)
{
	memset(dist, 0x3f, sizeof dist);
	while(q.size()) q.pop();
	q.push(1);
	memset(st, false, sizeof st);
	dist[1] = 0;
	st[1] = true;
	
	while(q.size())
	{
		int t = q.front(); q.pop();
		st[t] = 0;
		
		for(int i = h[t] ; i != -1 ; i = ne[i])
		{
			int j = e[i];
			int cpyw = w[i];
			if(cpyw <= check) cpyw = 0; 
			else cpyw = 1;
			if(dist[j] > dist[t] + cpyw)
			{
				dist[j] = dist[t] + cpyw;
				if(!st[j]) st[j] = 1, q.push(j); 
			}
		}
	}
	
	return dist[n] <= k;
}

signed main()
{
	cin >> n >> m >> k;
	int l = 1, r = 0;
	memset(h, -1, sizeof h);
	for(int i = 0 ; i < m ; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		addedge(a, b, c); addedge(b, a, c);
		r += c;
	}
	
	int ans = -1;
	while(l <= r)
	{
		int mid = (l+r)/2;
		if(isLessthanK(mid))
		{
			ans = mid;
			r = mid - 1;
		}
		else 
			l = mid + 1;
	}
	
	if (l > 1e6 || ans == -1) cout << -1;
	else cout << ans;
}