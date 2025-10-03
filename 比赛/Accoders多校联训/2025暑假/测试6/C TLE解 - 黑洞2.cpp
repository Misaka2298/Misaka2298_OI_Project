// T3
// expect pts = f**k
// 哥咱别唠了呗。。。考试呢
// 考试的时候原来是允许下地走动跟同桌交流甚至看他代码的吗。。。
#include <bits/stdc++.h>
using namespace std;
const int maxn = 45;
#define endl '\n'

int T;
int n, m;
int ans, initlive;
bool rbh[maxn][maxn];//reverse_BlackHole，是否“没有黑洞”

int deltax[] = {-1, 0, 1, 0};
int deltay[] = {0, 1, 0, -1};

unordered_set<string> vis;

string state2str(bool live[maxn][maxn])
{
	string s;
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= m ; j ++)
			s += live[i][j] ? '1' : '0';
	return s;
}

void init()
{
	memset(rbh, false, sizeof rbh);
	initlive = 0;
	ans = 0;
}

void dfs(bool live[maxn][maxn])//, string opt)
{
	int livecnt = 0;
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= m ; j ++)
			if(live[i][j])
			 	livecnt ++;
	
	if(livecnt == 1)
	{
		ans ++;
		//cout << opt << endl;
		return;
	}
	if(livecnt == 0)
		return ;
		
	string s = state2str(live);
	if(vis.count(s)) return;
	vis.insert(s);
	
	for(int k = 0 ; k < 4 ; k ++)
	{
		bool nextlive[maxn][maxn];
		memset(nextlive, false, sizeof nextlive);
		for(int i = 1 ; i <= n ; i ++)
			for(int j = 1 ; j <= m ; j ++)
			{
				if(!live[i][j])
					continue;
				int newx = i + deltax[k], newy = j + deltay[k];
				//nextlive[i][j] = false;
				if(rbh[newx][newy])
					nextlive[newx][newy] = true;
			}
			
		//string kk = to_string(k);
		dfs(nextlive);//, opt + kk);
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
		dfs(live);//, "");
		cout << ans << endl;
		
		}
}