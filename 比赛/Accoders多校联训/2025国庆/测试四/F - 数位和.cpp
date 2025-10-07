// F
// expect pts = 100
// expect diff = orange
// 你还敢出得再简单点吗

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
typedef long long LL;

int n, k;
LL a[maxn], s[maxn];

LL get(LL x)
{
	LL ans = 0;
	while(x)
	{
		ans += x % 10;
		x /= 10;
	}
	return ans;
}

signed main()
{
	freopen("digit.in", "r", stdin);
	freopen("digit.out", "w", stdout);
	cin >> n >> k;
	for(int i = 1 ; i <= 1000000 ; i ++)
		a[i] = get(i);
	
	for(int i = 1 ; i <= 1000000 ; i ++)
		s[i] = s[i-1] + a[i];
	
	for(int i = 1 ; i <= 1000000 - k + 1 ; i ++)
		if(s[i+k] - s[i-1] == n)
		{
			cout << i << endl;
			break;
		}
}