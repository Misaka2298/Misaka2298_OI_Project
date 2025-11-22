// B
// expect pts = 100
// expect diff = orange

#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e4+10;

int n, m;
int e[maxn], ne[maxn], h[maxn], idx;
int ans;
bool st[maxn];
struct Node{
	int id, deg;
}nodes[maxn];

bool cmp(Node a, Node b)
{
	return a.deg < b.deg;
}

void addedge(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void fileio()
{
	freopen("tribe.in", "r", stdin);
	freopen("tribe.out", "w", stdout);
}

void init()
{
	fileio();
	
	cin >> n >> m;
	memset(h, -1, sizeof h);
	
	for(int i = 1 ; i <= n ; i ++)
		nodes[i].id = i;
	for(int i = 1 ; i <= m ; i ++)
	{
		int a, b;
		cin >> a >> b;
		addedge(a, b);
		addedge(b, a);
		nodes[a].deg ++; nodes[b].deg ++;
	}
	
	sort(nodes+1, nodes+1+n, cmp);
}

void outans()
{
	cout << ans << endl;
	for(int i = 1 ; i <= n ; i ++)
		cout << !st[i] << ' ';
}

void mark()
{
	for(int i = 1 ; i <= n ; i ++)
	{
		int id = nodes[i].id;
		
		if(st[id])
			continue;
		ans ++;
		
		for(int k = h[id] ; k != -1 ; k = ne[k])
		{
			int j = e[k];
			st[j] = 1;
		}
	}
}

void solve()
{
	mark();
	outans();
}

signed main()
{
	init();
	solve();
}