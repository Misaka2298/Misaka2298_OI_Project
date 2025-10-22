// F
// expect pts = 100
// expect diff = yellow

#include <bits/stdc++.h>
using namespace std;
const int maxn = 20010;
const double eps = 1e-4;
typedef pair<int, int> PII;

int height, n;
int e[maxn], ne[maxn], h[maxn], idx;
PII stones[maxn];
int dist[maxn];
int ans = 0x3f3f3f3f;
bool st[maxn];

double getdis(double x, double y, double nx, double ny)
{
	if(y == 0.0)
		return ny;
	if(ny == 0.0)
		return y;
	return sqrt((x-nx)*(x-nx) + (y-ny)*(y-ny));
}

void addedge(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void bfs()
{
	queue<int> q;
	q.push(0);
	st[0] = 1;
	while(q.size())
	{
		int t = q.front(); q.pop();
		int x = stones[t].first, y = stones[t].second;
		for(int i = h[t] ; i != -1 ; i = ne[i])
		{
			int j = e[i];
			if(st[j])
				continue;
			st[j] = 1;
			dist[j] = dist[t] + 1;
			if(stones[j].second + 1000 >= height)
				ans = min(ans, dist[j]);
			q.push(j);
		}
	}
}

signed main()
{
	freopen("rock.in", "r", stdin);
	freopen("rock.out", "w", stdout);
	cin >> height >> n;
	memset(h, -1, sizeof h);
	
	for(int i = 1 ; i <= n ; i ++)
	{
		int x, y;
		cin >> x >> y;
		stones[i] = {x, y};
	}
	
	for(int i = 1 ; i <= n ; i ++)
		if(getdis(0, 0, stones[i].first, stones[i].second) - 1000.0 < eps)
		{
			addedge(0, i);
			addedge(i, 0);
		}
	
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= n ; j ++)
			if(i != j && getdis(stones[i].first, stones[i].second, stones[j].first, stones[j].second) - 1000.0 < eps)
			{
				addedge(i, j);
				addedge(j, i);
			}
	
	bfs();
	
	cout << ans;
}