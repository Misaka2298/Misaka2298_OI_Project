// T3
// expect pts = 100?
// expect diff = yellow
// 你最好真的是 NOIP 模拟

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+10;
#define endl '\n'
typedef pair<int, int> PII;

int n, m;
PII ne[maxn];
bool sta[maxn], ed[maxn];
vector<int> stas;

void solve(int st)
{
	int ans = 0x3f3f3f3f;
	
	int u = st;
	while(!ed[u])
	{
		ans = min(ans, ne[u].second);
		u = ne[u].first;
	}
	cout << st << ' ' << u << ' ' << ans << endl;
}

signed main()
{
	freopen("water.in", "r", stdin);
	freopen("water.out", "w", stdout);
	cin >> n >> m;
	memset(sta, 1, sizeof sta);
	memset(ed, 1, sizeof ed);
	for(int i = 1 ; i <= m ; i ++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		ne[a] = {b, c};
		ed[a] = 0;
		sta[b] = 0;
	}
	
	for(int i = 1 ; i <= n ; i ++)
		if(sta[i])
			stas.push_back(i);
	cout << stas.size() << endl;
	
	for(auto x : stas)
		solve(x);
	
	
}