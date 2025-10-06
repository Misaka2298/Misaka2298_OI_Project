// Problem: CF1651D Nearest Excluded Points
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1651D
// Memory Limit: 250 MB
// Time Limit: 4000 ms
// Time: 2025-10-05 10:15:54

#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
typedef long long LL;
typedef pair<int, int> PII;
#define endl '\n'

int n;
LL timestamp;
LL visx[maxn], visy[maxn];
bool stx[maxn], sty[maxn];
PII a[maxn];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

PII bfs(PII sta)
{
	queue<PII> q;
	q.push(sta);
	timestamp ++;
	visx[sta.first] = timestamp;
	visy[sta.second] = timestamp;
	
	while(q.size())
	{
		auto t = q.front(); q.pop();
		int x = t.first, y = t.second;
		for(int i = 0 ; i < 4 ; i ++)
		{
			int nx = x+dx[i], ny = y+dy[i];
			if(visx[nx] != timestamp && visy[ny] != timestamp)
			{
				visx[nx] = timestamp;
				visy[ny] = timestamp;
				if(!stx[nx] && !sty[ny])
					return {nx, ny};
				q.push({nx, ny});
			}
		}
	}
}

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
	{
		cin >> a[i].first >> a[i].second;
		stx[a[i].first] = 1;
		sty[a[i].second] = 1;
	}
	
	for(int i = 1 ; i <= n ; i ++)
	{
		PII ans = bfs(a[i]);
		cout << ans.first << ' ' << ans.second << endl;
	}
	
	
}