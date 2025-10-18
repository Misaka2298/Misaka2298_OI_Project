// E fixed
// expect pts = 100
// expect diff = orange
// 我的第一个AK的模拟赛要出现了吗
// 乔子健你牛波大了
// 不是兄弟这套题有点猎奇
// 这真是CSP模拟吗
// 不会给我最后放道黑吧

#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
typedef long long LL;
#define endl '\n'

int T;
int n;
int a[maxn];

// 构建一个从1开始的单调不降的序列，相邻差最大为1

signed main()
{
	freopen("monster.in", "r", stdin);
	freopen("monster.out", "w", stdout);
	cin >> T;
	while(T --)
	{
		cin >> n;
		for(int i = 1 ; i <= n ; i ++)
			cin >> a[i];
		sort(a+1, a+1+n);
		
		LL ans = 0;
		
		if(a[1] != 1 && a[1] != 0)
			ans += a[1] - 1, a[1] = 1;
		
		for(int i = 1 ; i < n ; i ++)
		{
			if(a[i+1] - a[i] == 1 || a[i+1] - a[i] == 0)
				continue;
			ans += a[i+1] - a[i] - 1;
			a[i+1] = a[i] + 1;
		}
		cout << ans << endl;
	}
}