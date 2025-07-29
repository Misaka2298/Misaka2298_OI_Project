// T3
// expect pts = f**k
// 哥咱别唠了呗。。。考试呢
// 考试的时候原来是允许下地走动跟同桌交流甚至看他代码的吗。。。
#include <bits/stdc++.h>
using namespace std;
const int maxn = 45;

int T;
int n, m;
int ans, initlive;
bool rbh[maxn][maxn];//reverse_BlackHole

int deltax[] = {-1, 0, 1, 0};
int deltay[] = {0, 1, 0, -1};

void init()
{
	memset(rbh, false, sizeof rbh);
	initlive = 0;
	ans = 0;
}

void dfs(bool live[maxn][maxn])
{
	int livecnt = 0;
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= m ; j ++)
			if(live[i][j])
			 	livecnt ++;
	
	if(livecnt == 1)
	{
		ans ++;
		return;
	}
	if(livecnt == 0)
		return ;
	
	for(int k = 0 ; k < 4 ; k ++)
	{
		for(int i = 1 ; i <= n ; i ++)
			for(int j = 1 ; j <= m ; j ++)
			{
				if(!live[i][j])
					continue;
				int newx = i + deltax[k], newy = j + deltay[k];
				live[i][j] = false;
				if(rbh[newx][newy])
					live[newx][newy] = true;
			}
			
		//string kk = to_string(k);
		dfs(live);
	}
	//return;
}

signed main()
{
	freopen("blackhole.in", "r", stdin);
	freopen("blackhole.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> T;
	while(T--)
	{
		init();
		cin >> n >> m;
		for(int i = 1 ; i <= n ; i ++)
			for(int j = 1 ; j <= m ; j ++)
			{
				char a;
				cin >> a;
				if(a == '.')
					rbh[i][j] = true, initlive ++;
			}
		if(initlive == 1)
		{
			cout << 1 << endl;
			continue;
		}
		/*	
		for(int i = 1 ; i <= n ; i ++)
		{
			for(int j = 1 ; j <= m ; j ++)
				cout << rbh[i][j];
			cout << endl;
		}
		*/
			
		bool live[maxn][maxn];
		for(int i = 1 ; i <= n ; i ++)
			for(int j = 1 ; j <= m ; j ++)
				live[i][j] = rbh[i][j];
		dfs(live);
		cout << ans << endl;
		
		}
}