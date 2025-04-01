//T1
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+10;
typedef pair<int, int> PII;

int id, n, m, k, c;
long long cnt[maxn][maxn], res[maxn];
bool g[maxn][maxn];
queue<PII>q;

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	cin >> id >> n >> m >> k >> c;
	for(int i = 0 ; i < c ; i ++)
	{
		int x, y;
		cin >> x >> y;
		q.push({x, y});
		g[x][y] = true;
	}//边界为1~x/1~y
	
	while(q.size())
	{
		auto t = q.front(); q.pop();
		int tx = t.first, ty = t.second;
		
		
		int xinit, yinit, xend, yend;
		if(tx-k >= 1) xinit = tx - k;
		else xinit = 1; 
		if(ty-k >= 1) yinit = ty - k;
		else yinit = 1;
		if(tx+k <= n) xend = tx + k;
		else xend = n;
		if(ty+k <= m) yend = ty + k;
		else yend = m;
		
		for(int i = xinit ; i <= xend ; i++)
			for(int j = yinit; j <= yend ; j++)
				if(!g[i][j])
					cnt[i][j] ++;
	}
	
	/*
	for(int i = 1 ; i <= n ; i ++)
	{
		for(int j = 1 ; j <= m ; j++)
		{
			if(!g[i][j]) cout << cnt[i][j] << ' ';
			else cout << 'a' << ' ';
		}	
		cout << endl;
	}//debug
	cout << endl;
	*/
	
	
	long long ma = -1e9;
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= m ; j++)
			if(!g[i][j])
			{
				res[cnt[i][j]] ++;
				ma = max(ma, cnt[i][j]);
			}
	
	for(int i = 1 ; i <= ma ; i++)
		cout << res[i] << ' ';
		
}
/*
像二维差分，可惜我不会。
*/