// C
// expect pts = 10
// expect diff = i d fk k
// 我认可你了 你真的是 NOIP 模拟赛
// 不是原来你这个 olc 区间长度可以是1啊。。。。。。。。。。
// 那我刚才在 debug 什么，回答我

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
#define endl '\n'

int T;
int n, k;
int a[maxn], b[maxn];

bool cmp(int aa, int bb)
{
	return aa > bb;
}

signed main()
{
	freopen("interval.in", "r", stdin);
	freopen("interval.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> T;
	for(int kk = 1 ; kk <= T ; kk ++)
	{
		cin >> n >> k;
		for(int i = 1 ; i <= n ; i ++)
			cin >> a[i];
		for(int i = 1 ; i <= n ; i ++)
			cin >> b[i];
		
		if(a[1] > k)
		{
			cout << -1 << endl;
			continue;
		}
		else
		{
			cout << 0 << endl;
		}
	}
}