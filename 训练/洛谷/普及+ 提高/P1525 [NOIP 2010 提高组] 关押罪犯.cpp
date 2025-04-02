#include <bits/stdc++.h>
using namespace std;
const int maxn = 20010, maxm = 100010;

int n, m, b[maxn];
int fa[maxn];

struct ang{
	int a, b, c;
}angs[maxm];

bool cmp(ang A, ang B)
{
	return A.c > B.c;
}

int find(int x)
{
	if(x != fa[x]) fa[x] = find(fa[x]);
	return fa[x];
}

void ad(int x, int y)
{
	x = find(x);
	y = find(y);
	fa[x] = y;
}

bool check(int x, int y)
{
	x = find(x);
	y = find(y);
	if(x == y) return true;
	else return false;
}

signed main()
{
	cin >> n >> m;
	
	for(int i = 1 ; i <= n ; i++)
		fa[i] = i;
	
	for(int i = 0 ; i < m ; i ++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		angs[i] = {a, b, c};
	}
	
	sort(angs, angs+m, cmp);
	
	for(int i = 0 ; i <= m ; i++)
	{
		int x = angs[i].a, y = angs[i].b, c = angs[i].c;
		if(check(x, y))
		{
			cout << c;
			break;
		}
			
		if(!b[x]) b[x] = y;
		else ad(b[x], y);
		if(!b[y]) b[y] = x;
		else ad(b[y], x);
	}
}