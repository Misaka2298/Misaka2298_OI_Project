// T3
// expect pts = 50?

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e8+5e7;// tanxin !!!!

long long n, target;
bool st[maxn];

signed main()
{
	freopen("prime.in", "r", stdin);
	freopen("prime.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	st[1] = true;
	while(n--)
	{
		int a;
		cin >> a;
		for(int i = 1 ; i * a < maxn ; i ++)
			st[i*a] = true;
	}
	cin >> target;
	long long cnt = 0;
	for(int i = 1 ; i < maxn ; i ++)
	{
		if(st[i])
			cnt++;
		if(cnt == target)
		{
			cout << i;
			break;
		}
	}
	return 0;
}