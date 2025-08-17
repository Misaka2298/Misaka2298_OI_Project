// B
// expect pts = 25 ~ 80?
// may 50, 菊花图会被狠狠的卡, 希望数据跟三字学会一样水
// std maybe is dp on tree, but wo bu hui

// 我的电脑好像能草过O(n^2)，有点搞。
// AMD Ryzen7 8845HS神力。
// 还好对拍出来了，我菊花图的结论是错的
// 对拍神力。
#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5+10;
typedef long long LL;

int n;
int e[maxn], ne[maxn], h[maxn], idx;
int w[maxn];
int deg[maxn];
bool st[maxn], haveans;
inot ans = 0;

void addedge(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void bfs(int sta)
{
	queue<int> q;
	q.push(sta);
	st[sta] = true;
	int gcd = w[sta], sz = 1, j, nowgcd, t;
	while(!q.empty())
	{
		t = q.front(); q.pop();
		for(int i = h[t] ; i != -1 ; i = ne[i])
		{
			j = e[i];
			if(st[j]) continue;
			nowgcd = __gcd(gcd, w[j]);
			if(nowgcd == 1) continue;
			st[j] = true;
			gcd = nowgcd;
			haveans = 1;
			sz ++;
			q.push(j);
		}
	}
	ans = max(ans, sz);
}

signed main()
{
	freopen("gcd.in", "r", stdin);
	freopen("gcd.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	memset(h, -1, sizeof h);
	cin >> n;
	
	for(int i = 1 ; i <= n ; i ++)
		cin >> w[i], haveans = (w[i] != 1);
	
	for(int i = 1 ; i < n ; i ++)
	{
		int a, b;
		cin >> a >> b;
		deg[a] ++, deg[b] ++;
		addedge(a, b); addedge(b, a);
	}
	
	for(int i = 1 ; i <= n ; i ++)
	{
		memset(st, false, sizeof st);
		bfs(i);
		if(ans == n)
			break;
	}
	
	if(haveans) cout << ans;
	else cout << 0;
	return 0;
}