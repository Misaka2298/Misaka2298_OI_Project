#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010, maxm = 200010;
typedef long long ll;

int n, m, step[maxn];
vector<ll>e[maxn], reve[maxn];
bool precan[maxn], can[maxn];
int st, ed;
queue<ll>q;

signed main()
{
	cin >> n >> m;
	for(int i = 0 ; i < m ; i ++)
	{
		int a, b;
		cin >> a >> b;
		e[a].push_back(b); reve[b].push_back(a);
	}
	
	cin >> st >> ed;
	q.push(ed);
	precan[ed] = 1;
	while(q.size())
	{
		int node = q.front(); q.pop();
		for(int i = 0 ; i < reve[node].size() ; i ++)
			if(!precan[reve[node][i]])
			{
				precan[reve[node][i]] = 1;
				q.push(reve[node][i]);
			}
	}
	
	for(int i = 1 ; i <= n ; i++)
		if(precan[i])
		{
			can[i] = 1;
			for(int j = 0 ; j < e[i].size() ; j++)
				if(!precan[e[i][j]])
				{
					can[i] = 0;
					break;
				}
		}
	
	while(q.size()) q.pop();
	if(can[ed]) q.push(st);
	while(q.size())
	{
		int node = q.front(); q.pop();
		if(node == ed)
		{
			cout << step[node];
			exit(0);
		}
		for(int i = 0 ; i < e[node].size() ; i++)
			if(!step[e[node][i]] && can[e[node][i]])
			{
				q.push(e[node][i]);
				step[e[node][i]] += step[node] + 1;
			}
	}
	cout << -1;
}
