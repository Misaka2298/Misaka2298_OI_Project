// A
// expect pts = 100
// expect diff = orange

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+10;
//typedef pair<int, int> PII;

int n, m;
int a[maxn];
queue<pair<int, pair<int, int>>> q;

signed main()
{
	freopen("sugar.in", "r", stdin);
	freopen("sugar.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++)
	{
		int x;
		cin >> x;
		q.push({i, {x, 0}});
	}
	
	int ans = 0;
	while(q.size())
	{
		auto t = q.front(); q.pop();
		int u = t.first, goal = t.second.first, have = t.second.second;
		
		have += m;
		if(have >= goal)
		{
			ans = u;
			continue;
		}
		else
			q.push({u, {goal, have}});
			
	}
	cout << ans;
	return 0;
} 