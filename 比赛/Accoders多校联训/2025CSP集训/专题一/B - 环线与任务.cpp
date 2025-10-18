// B
// expect pts = 100
// expect diff = orange
// 新来的小孩模拟赛打游戏吗  很神人了

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
typedef long long LL;

int n, m;
int a[maxn];

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	freopen("circle.in", "r", stdin);
	freopen("circle.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= m ; i ++)
		cin >> a[i];
	
	int pos = 1;
	LL ans = 0;
	for(int i = 1 ; i <= m ; i ++)
	{
		int goal = a[i];
		ans += (goal - pos + n) % n;
		pos = goal;
	}
	cout << ans;
}