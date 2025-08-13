// T1
// 喜欢不给大样例的A_zjzj小朋友你好啊，我是Misaka2298
// 印章有可能大边界留白来诈骗 //solved
// expect pts = 50?

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+10;
typedef pair<int, int> PII;
#define endl '\n'

int T;
int n, m, a, b;
int gcnt;
bool g[maxn][maxn], s[maxn][maxn];
bool ink[maxn][maxn];

void init()
{
	char tmp;
	bool firstvis = false;
	PII fst, lst;
	bool havex[maxn];//col
	memset(havex, false, sizeof havex);
			
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= m ; j ++)
		{
			cin >> tmp;
			if(tmp == 'x')
			{
				havex[j] = true;
				if(!firstvis)
				{
					firstvis = 1;
					fst = {i, j};
				}
				lst = {i, j};
				gcnt ++;
				g[i][j] = 1;
			}
			else
				g[i][j] = 0;
		}
	for(int i = 1 ; i <= m ; i ++)
		if(havex[i])
		{
			fst.second = i;
			break;
		}
	for(int i = 1 ; i <= m ; i ++)
		if(havex[i])
			lst.second = i;
			
	for(int i = 1 ; i <= lst.first-fst.first+1 ; i ++)
		for(int j = 1 ; j <= lst.second-fst.second+1 ; j ++)
			g[i][j] = g[fst.first+i-1][fst.second+j-1];
	n = lst.first-fst.first+1;
	m = lst.second-fst.second+1;
	//cout << fst.first << ' ' << fst.second << ' ' << lst.first << ' ' << lst.second << endl;
	//cout << n << ' ' << m << endl;
	
	firstvis = false;
	memset(havex, false, sizeof havex);
	for(int i = 1 ; i <= a ; i ++)
		for(int j = 1 ; j <= b ; j ++)
		{
			cin >> tmp;
			if(tmp == 'x')
			{
				havex[j] = true;
				if(!firstvis)
				{
					firstvis = 1;
					fst = {i, j};
				}
				lst = {i, j};
				s[i][j] = 1;
			}
			else
				s[i][j] = 0;
		}
	for(int i = 1 ; i <= m ; i ++)
		if(havex[i])
		{
			fst.second = i;
			break;
		}
	for(int i = 1 ; i <= m ; i ++)
		if(havex[i])
			lst.second = i;
	
	for(int i = 1 ; i <= lst.first-fst.first+1 ; i ++)
		for(int j = 1 ; j <= lst.second-fst.second+1 ; j ++)
		{
			s[i][j] = s[fst.first+i-1][fst.second+j-1];
		}
			
	a = lst.first-fst.first+1;
	b = lst.second-fst.second+1;
	return;
}

bool solve()
{
	int inkcnt = 0;
	bool flag = true;
	queue<PII> q;
	for(int i = 1 ; i <= n-a+1 ; i ++)
		for(int j = 1 ; j <= m-b+1 ; j ++)
		{
			if(g[i][j] && !ink[i][j])
			{
				for(int ii = 1 ; ii <= a && flag ; ii ++)
					for(int jj = 1 ; jj <= b && flag ; jj ++)
					{
						int x = i+ii-1, y = j+jj-1;
						if(s[ii][jj] && g[x][y])
							q.push({x, y});
						if(s[ii][jj] && (ink[x][y] || !g[x][y]))
						{
							while(q.size()) q.pop();
							flag = false;
							break;
						}
					}
				inkcnt += q.size();
				while(q.size())
				{
					auto t = q.front(); q.pop();
					//cout << t.first << ' ' << t.second << endl;
					ink[t.first][t.second] = true;
				}
				flag = 1;
			}
			
		}
	//cout << inkcnt << ' ' << gcnt << endl;
	return (inkcnt == gcnt);
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	freopen("seal.in", "r", stdin);
	freopen("seal.out", "w", stdout);
	
	cin >> T;
	while(T --)
	{
		gcnt = 0;
		memset(ink, false, sizeof ink);
		cin >> n >> m >> a >> b;
		
		init();
		
		if(solve())
			cout << "TAK" << endl;
		else
			cout << "NIE" << endl;
		
 	}
 	return 0;
}
/*
		for(int i = 1 ; i <= n ; i ++)
		{
			for(int j = 1 ; j <= m ; j ++)
				cout << g[i][j];
			cout << endl;
		}
*/