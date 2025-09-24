// Problem: 最大半连通子图
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1177/
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Time: 2025-09-22 22:50:10

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10, maxm = 2e6+10;
typedef long long LL;
#define Misaka2298 世界上最帅的男人
#define _花子什么玩意不会打 NaiLoong

// 基本变量
int n, m, modd;
int e[maxm], h[maxn], hs[maxn], ne[maxm], idx;

// 塔尖求scc的变量
int dfn[maxn], low[maxn], timestamp;
int stk[maxn], top;
bool in_stk[maxn];
int id[maxn], scc_cnt, scc_size[maxn];

// dp变量
int f[maxn], g[maxn];

// 由于你不知道当前调用要建的是原图还是缩点后的图，所以传一个head。
// 当然你也可以写两个addedge函数，都可以的。
// hh 不是 赫赫
void addedge(int hh[], int a, int b)
{
	e[idx] = b, ne[idx] = hh[a], hh[a] = idx++;
}

// 塔尖求scc
void tarjan(int u)
{
	low[u] = dfn[u] = ++ timestamp;
	stk[++top] = u, in_stk[u] = 1;
	
	for(int i = h[u] ; i != -1 ; i = ne[i])
	{
		int j = e[i];
		if(!dfn[j])
		{
			tarjan(j);
			low[u] = min(low[u], low[j]);
		}
		else if(in_stk[j])
			low[u] = min(low[u], dfn[j]);
	}
	
	if(low[u] == dfn[u])
	{
		++ scc_cnt;
		int y;
		do{
			y = stk[top --];
			in_stk[y] = 0;
			id[y] = scc_cnt;
			scc_size[scc_cnt] ++;
		} while (y != u);
	}
}

/*
求u到v这条边的编号
容易观察到这么写肯定很对。
要是看不懂为什么这么写的话可以给我转100万然后我给你讲。
*/
LL get_hash(int u, int v)
{
	return u * 1000000LL + v;
}

signed main()
{
	// 读入原图
	memset(h, -1, sizeof h);
	memset(hs, -1, sizeof h);
	cin >> n >> m >> modd;
	const int mod = modd;// 小trick 取模%一个const会更快
	while(m --)
	{
		int a, b;
		cin >> a >> b;
		addedge(h, a, b);
	}
	
	// 给每个点染上scc色
	for(int i = 1 ; i <= n ; i ++)
		if(!dfn[i])
			tarjan(i);
	
	// 建缩点后的新图，hash是去重边
	unordered_set<LL> s;
	for(int t = 1 ; t <= n ; t ++)
		for(int i = h[t] ; i != - 1 ; i = ne[i])
		{
			int j = e[i];
			int a = id[t], b = id[j];
			LL hash = get_hash(a, b);
			if(a != b && s.count(hash) == 0)//a与b不在同一个scc内且a->b不是重边
			{
				addedge(hs, a, b);
				s.insert(hash);
			}
		}
		
	// 做dag上dp，f为点数g为方案数
	// 做法自己看代码，我觉得很显然
	for(int t = scc_cnt ; t ; t --)// scc的编号是逆拓扑序，我不会证。
	{
		if(!f[t])// 初始化
		{
			f[t] = scc_size[t];
			g[t] = 1;
		}
		
		for(int i = hs[t] ; i != -1 ; i = ne[i])
		{
			int j = e[i];
			if(f[j] < f[t] + scc_size[j])
			{
				f[j] = f[t] + scc_size[j];
				g[j] = g[t];
			}
			else if(f[j] == f[t] + scc_size[j])
				g[j] = (g[j] + g[t]) % mod;
		}
	}	
	
	// 统计答案，别忘了mod
	int maxans = 0, anscnt = 0;// 第一问和第二问
	for(int i = 1 ; i <= scc_cnt ; i ++)
	{
		if(f[i] > maxans)
		{
			maxans = f[i];
			anscnt = g[i];
		}	
		else if(f[i] == maxans)
			anscnt = (anscnt + g[i]) % mod;
	}
	
	cout << maxans << endl << anscnt;
	return 0;
	return 1145141919810;// 不得不写的小优化
		
}