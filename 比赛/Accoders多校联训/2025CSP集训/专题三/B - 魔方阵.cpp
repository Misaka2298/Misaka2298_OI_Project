// B
// expect pts = 100
// expect diff = orange

#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
const int maxn = 10;
#define endl '\n';

int a[maxn], st[maxn];
int g[maxn];
long long cnt;

bool check(int &goal)
{
	bool flag = 1;
	goal = g[1] + g[2] + g[3];
	
	flag = (g[1]+g[2]+g[3] == goal) && flag;
	flag = (g[4]+g[5]+g[6] == goal) && flag;
	flag = (g[7]+g[8]+g[9] == goal) && flag;
	
	flag = (g[1]+g[5]+g[9] == goal) && flag;
	flag = (g[3]+g[5]+g[7] == goal) && flag;
	
	flag = (g[1]+g[4]+g[7] == goal) && flag;
	flag = (g[2]+g[5]+g[8] == goal) && flag;
	flag = (g[3]+g[6]+g[9] == goal) && flag;
	
	return flag;
}

void out(int goal)
{
	//cout << goal << endl;
	for(int i = 1 ; i <= 9 ; i ++)
	{
		cout << g[i] << ' ';
		if(!(i % 3))
			cout << endl;
	}
	cout << endl;
	exit(0);
}

void dfs(int u)
{
	if(u == 10)
	{
		int goal;
		if(check(goal))
			out(goal);
		return;
	}
	
	for(int i = 1 ; i <= 9 ; i ++)
	{
		if(st[i])
			continue;
		st[i] = 1;
		g[u] = a[i];
		dfs(u+1);
		st[i] = 0;
		
	}
}

signed main()
{
	freopen("magicq.in", "r", stdin);
	freopen("magicq.out", "w", stdout);
	//freopen("a.out", "w", stdout);
	for(int i = 1 ; i <= 9 ; i ++)
		cin >> a[i];
	sort(a+1, a+10);
	dfs(1);
}