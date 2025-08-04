// T2
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
typedef pair<int, int> PII;

int n, m;
bool st[maxn];
vector<int> to[maxn];
PII cnt[maxn];

bool cmp(PII a, PII b)
{
	return a.first > b.first;	
}

signed main()
{
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++)
		cnt[i].second = i;
	for(int i = 0 ; i < m ; i ++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		to[a].push_back(b);
		to[b].push_back(a);
		cnt[a].first ++;
		cnt[b].first ++;
	}
	sort(cnt+1, cnt+1+n, cmp);
	
	int ans = 0, count = 0, idx = 1;
	while(idx != n)
	{
		PII t = cnt[idx++];
		int id = t.second;
		st[id] = true; count ++;
		for(int i = 0 ; i < to[id].size() ; i ++)
			if(!st[to[id][i]])
			{
				count ++;
				st[to[id][i]] = true;
			}
		ans ++;
	}
	cout << ans;
}