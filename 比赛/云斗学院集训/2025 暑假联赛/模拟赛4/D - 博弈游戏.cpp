// D
// expect pts = 10
// expect diff = idk;

// 小兵步枪 已严肃启动
// 报告强老师，今天也有在认真的摸鱼，完全没有在打模拟赛

#include <bits/stdc++.h>
using namespace std;

int T, n;

signed main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	cin >> T;
	while(T--)
	{
		cin >> n;
		if(n <= 9)
			cout << n << endl;
		else
			cout << 0 << endl;
	}
}