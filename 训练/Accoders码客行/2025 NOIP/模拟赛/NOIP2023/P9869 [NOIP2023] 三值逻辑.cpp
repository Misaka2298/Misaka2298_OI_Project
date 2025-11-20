// Problem: P9869 [NOIP2023] 三值逻辑
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P9869?contestId=145259
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Time: 2025-11-19 15:25:55

#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;

int c, T;
int n, m;
int fa[maxn], sz[maxn];
bool isrev[maxn];
char val[maxn];
int ans = 0;

void init()
{
	for(int i = 1 ; i <= n ; i ++)
		fa[i] = i, sz[i] = 1;
	memset(val, 0, sizeof val);
	memset(isrev, 0, sizeof isrev);
	ans = 0;
}

int find(int x)
{
	if(x != fa[x])
		return fa[x] = find(fa[x]);
	return fa[x];
}

void addans(int u)
{
	u = find(u);
	ans += sz[u];
	val[u] = 'U'; 
}

char rev(char value)
{
	if(value == 'T')
		return 'F';
	else if(value == 'F')
		return 'T';
	else if(value == 'U')
		return 'U';
}

void dsu_union(int a, int b)
{
	fa[b] = a;
	sz[a] += sz[b];
	if(val[a] == 'U')
		val[b] = 'U';
	if(val[b] == 'U')
		val[a] = 'U';
}

void sol_ans()
{
	for(int i = 1 ; i <= n ; i ++)
	{
		int ri = find(i);
		if(val[ri] == 'U')
			ans ++;
	}
}

void sol()
{
	for(int M = 1 ; M <= m ; M ++)
		{
			char opt;
			int a, b;
			cin >> opt >> a;
			if(opt != '+' && opt != '-')
			{
				if(opt == 'U' || (val[a] && val[a] != opt && val[a] != 'U'))
					a = find(a), val[a] = 'U';//addans(a);
				else
					val[a] = opt;
			}
			else
			{
				cin >> b;
				int ra = find(a), rb = find(b);
				
				if(opt == '-')
				{
					if(ra == rb)
					{
						//illegal
						if(!isrev[a])
							val[ra] = 'U';
					}
					else
					{
						if(!isrev[a])
							isrev[rb] = 1;
						dsu_union(ra, rb);
					}
				}
				else
				{
					if(ra == rb)
					{
						if(isrev[a])
						{
							val[ra] = 'U';
						}
							
					}
					else
					{
						if(isrev[a])
							isrev[rb] = 1;
						dsu_union(ra, rb);
					}
				}
			}
		}
		sol_ans();
		cout << ans << endl;
}

void TFU()
{
	for(int i = 1 ; i <= m ; i ++)
	{
		char opt;
		int a;
		cin >> opt >> a;
		if(val[a] && val[a] != opt && val[a] != 'U')
			val[a] = 'U';
		else if(val[a] != 'U')
			val[a] = opt;
	}
	for(int i = 1 ; i <= n ; i ++)
		if(val[i] == 'U')
			ans ++;
	cout << ans << endl;
}

void uplus()
{
	for(int M = 1 ; M <= m ; M ++)
	{
		char opt;
		int a, b;
		cin >> opt >> a;
		if(opt == '+')
		{
			cin >> b;
			int ra = find(a), rb = find(b);
			if(ra != rb)
			{
				if(sz[ra] > sz[rb])
					swap(ra, rb);
				fa[ra] = rb;
				if(val[ra] == 'U')
					val[rb] = 'U';
				if(val[rb] == 'U')
					val[ra] = 'U';
				//sz[rb] += ra;
			}
		}
		else
		{
			int ra = find(a);
			val[ra] = 'U';
		}
	}
	for(int i = 1 ; i <= n ; i ++)
		if(val[find(i)] == 'U')
			ans ++;
	cout << ans << endl;
}

signed main()
{
	cin >> c >> T;
	for(int t = 1 ; t <= T ; t ++)
	{
		cin >> n >> m;
		init();
		
		if(c == 3 || c == 4)
			TFU();
		else if(c == 5 || c == 6)
			uplus();
		else
			sol();
	}
}