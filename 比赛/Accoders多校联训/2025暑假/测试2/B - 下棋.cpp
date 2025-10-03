//T2
//expect pts = 50;
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e4+10;
#define endl '\n'
typedef pair<int, int> PII;

int n, m;
char g[maxn][maxn];

void bfs()
{
	queue<PII> q;
	q.push({1, 1});
	
	while(q.size())
	{
		PII t = q.front(); q.pop();
		cout << g[t.first][t.second];// << t.first << ' ' << t.second << endl;
		if(t.first == n && t.second == m)
			break;
		if(t.first == n)
		{
			for(int i = t.second+1 ; i <= m ; i ++)
				cout << g[n][i];
			break;
		}
		else if(t.second == m)
		{
			for(int i = t.first+1 ; i <= n ; i ++)
				cout << g[i][m];
			break;
		}
		else
		{
			if(g[t.first+1][t.second] > g[t.first][t.second+1])
				q.push({t.first, t.second+1});
			else
				q.push({t.first+1, t.second});
		}
	}
}

signed main()
{
	freopen("pohlepko.in", "r", stdin);
	freopen("pohlepko.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m;
	char tmp;
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= m ; j ++)
		{
			cin >> tmp;
			g[i][j] = tmp;
		}
		
	/*	
	for(int i = 1 ; i <= n ; i ++)
	{
		for(int j = 1 ; j <= m ; j ++)
			cout << (char)g[i][j];
		cout << endl;
	*/
		
	bfs();
	//cout << char(g[9][5]);
	//9 6 
}