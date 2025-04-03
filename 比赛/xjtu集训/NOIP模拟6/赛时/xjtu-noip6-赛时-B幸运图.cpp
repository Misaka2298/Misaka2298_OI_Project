//T2
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10, maxm = 2e5+10;
typedef pair<int,int> PII;

int n, m, deg[maxn];
int e[maxm], ne[maxm], h[maxn], idx, id[maxm];
bool st[maxm];

void addedge(int a, int b, int c)
{
	id[idx] = c, e[idx] = b, ne[idx] = h[a] , h[a] = idx++;
}

void remedge(int a, int b)
{
	int pre = -1, cur = h[a];
	while(cur != -1)
	{
		if(e[cur] == b)
		{
			if(pre == -1)
				h[a] = ne[cur];
			else
				ne[pre] = ne[cur];
		}
		pre = cur;
		cur = ne[cur];
	}
}

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	memset(h, -1, sizeof h);
	for(int i = 1 ; i <= m ; i ++)
	{
		int a, b;
		cin >> a >> b;
		addedge(a, b, i); addedge(b, a, i);
		deg[b]++; deg[a]++;
	}
	
	/*
	for(int i = 1 ; i <= n ; i++)
		cout << deg[i] << ' ' ;
	cout << endl;
	*/
	
	queue<int>q;
	for(int i = 1 ; i <= n ; i++)
		if(deg[i] % 2 == 0)
			q.push(i);
	
	int anscnt = 0;
	queue<int>ans;
	while(q.size())
	{
		int t = q.front(); q.pop();
		if(deg[t] % 2 != 0) continue;
		
		for(int i = h[t] ; i != -1 ; i = ne[i])
		{
			int j = e[i], jid = id[j];
 			if(deg[j] % 2 == 0)
 			{
 				remedge(t, j); remedge(j, t);
 				deg[t]--; deg[j]--;
				if(deg[t] % 2 == 0 && deg[t] != 0) q.push(t);
				if(deg[j] % 2 == 0 && deg[j] != 0) q.push(j);
				anscnt++;
				ans.push(jid);
 			}
			
		}
	}
	
	/*
	for(int i = 1 ; i <= n ; i++)
		cout << deg[i] << ' ' ;
	cout << endl;
	*/
	
	int luk = 0;
	for(int i = 1 ; i <= n ; i++)
		if(deg[i] % 2 != 0)
			luk ++;
			
	cout << luk << endl << anscnt << endl;
	while(ans.size())
	{
		auto t = ans.front(); ans.pop();
		cout << t << ' ' ;
	}
}