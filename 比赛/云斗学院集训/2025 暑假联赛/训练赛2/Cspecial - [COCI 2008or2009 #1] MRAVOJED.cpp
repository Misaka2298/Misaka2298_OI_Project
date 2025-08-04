// T3-spe
#include <bits/stdc++.h>
using namespace std;
const int maxn = 200;
typedef pair<int, int> PII;

int n, m;
char g[maxn][maxn];
int xcnt;

bool isfirstx = true;
PII firstx;
bool st[maxn][maxn];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

int spebfs()
{
	memset(st, false, sizeof st);
	int cnt = 1;
	queue<PII> q;
	q.push(firstx);
	st[firstx.first][firstx.second] = 1;
	
	while(q.size())
	{
		auto t = q.front(); q.pop();
		int x = t.first, y = t.second;
		for(int i = 0 ; i < 4 ; i ++)
		{
			int newx = x+dx[i], newy = y+dy[i];
			if(!st[newx][newy] && g[newx][newy] == 'x')
			{
				st[newx][newy] = 1;
				cnt ++;
				q.push({newx, newy});
			}
		}
	}
	return cnt;
}

void spe_div()//建筑是独立的
{
	int len = 0;
	for(int i = firstx.second ; i <= m ; i ++)
	{
		if(g[firstx.first][i] == 'x')
			len ++;
		else
			break;
	}
	cout << firstx.first << ' ' << firstx.second << ' ' << len << endl;
	
	len = 0;
	PII secondx; bool flag = false;
	for(int i = 1 ; i <= n && !flag ; i ++)
		for(int j = 1 ; j <= m && !flag ; j ++)
			if(!st[i][j] && g[i][j] == 'x')
			{
				secondx.first = i, secondx.second = j;
				flag = true;
			}
	for(int i = secondx.second ; i <= m ; i ++)
	{
		if(g[secondx.first][i] == 'x')
			len ++;
		else
			break;
	}
	cout << secondx.first << ' ' << secondx.second << ' ' << len << endl;
	exit(0);
}

signed main()
{
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= m ; j ++)
		{
			cin >> g[i][j];
			if(isfirstx && g[i][j] == 'x')
			{
				firstx.first = i, firstx.second = j;
				isfirstx = false;
			}
			xcnt += (g[i][j] == 'x');
		}
	
	//if(spebfs() != xcnt)
	spebfs();
	spe_div();
	
			
}