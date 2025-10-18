// F
// expect pts = 100
// expect diff = yellow
// 真正的难题要来了吗！
// 好像就是一道双指针······
// 没有负数真的是太好了
// 好难调！！！
// 可能是对的吧。

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
typedef pair<int, int> PII;
typedef long long LL;

int n, d;
PII arr[maxn];

signed main()
{
	freopen("party.in", "r", stdin);
	freopen("party.out", "w", stdout);
	cin >> n >> d;
	for(int i = 1 ; i <= n ; i ++)
	{
		int a, b;
		cin >> a >> b;
		arr[i] = {a, b};
	}
	
	sort(arr+1, arr+1+n);
	
	LL ans = 0, sum = 0;
	int l = 1;
	for(int r = 1 ; r <= n ; r ++)
	{
		sum += arr[r].second;
		while(arr[r].first - arr[l].first > d)
		{
			sum -= arr[l].second;
			l ++;
		}
		ans = max(ans, sum);
	}
	
	cout << ans;
}