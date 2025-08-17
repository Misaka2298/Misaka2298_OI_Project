// C
// expect pts = 10
// expect diff = idk
// 这怎么又像dp又不像dp的
// 我管你这个那个的，贪！
// 小贪拿小分，大贪拿大分！！！
// 吃大分去吧，Misaka2298!

// 数据该水的时候 应该会水一点吧

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;

int T, n;
int a;
int last2, last1;

signed main()
{
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	cin >> T;
	while(T --)
	{
		last2 = last1 = 0;
		cin >> n;
		int ans = 0;
		for(int i = 1 ; i <= n ; i ++)
		{
			cin >> a;
			if(last1 != a && last2 != a)
			{
				ans ++;
				last2 = last1;
				last1 = a;
			}
		}
		cout << ans << endl;
	}
}