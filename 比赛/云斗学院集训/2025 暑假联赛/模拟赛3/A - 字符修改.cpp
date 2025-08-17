// A
// expect pts = 100
// 20min solved, 感觉不太对，noip怎么这么简单？
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+10;
typedef long long LL;

int n, m;
char str[maxn][maxn];
LL cnt[27];
LL ans;

signed main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= m ; j ++)
			cin >> str[i][j];
	
	for(int j = 1 ; j <= m ; j ++)
	{
		memset(cnt, 0, sizeof cnt);
		for(int i = 1 ; i <= n ; i ++)
			cnt[str[i][j] - 'a'] ++;
		
		LL mx = 0;
		int mxpos = 0;
		for(int i = 0 ; i < 26 ; i ++)
			if(mx < cnt[i])
				mx = cnt[i], mxpos = i;
		for(int i = 0 ; i < 26 ; i ++)
			if(mxpos != i)
				ans += cnt[i];
	}
	cout << ans;
	return 0;
	
}