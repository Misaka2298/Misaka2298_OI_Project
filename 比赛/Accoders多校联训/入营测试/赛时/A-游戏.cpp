//T1
//expect pts = 100???
//idk the true algorithm.
//but it's true????????????
//why??????????
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;

long long n, num[maxn];
long long a[maxn];

signed main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> num[i];
		
	for(int i = 1 ; i <= n ; i ++)
		a[i] = a[i-1] + num[i];
	
	long long res = 0;
	for(int i = 2 ; i <= n ; i++)
		if(a[i] > 0)
			res += a[i];
	cout << res;
}
 