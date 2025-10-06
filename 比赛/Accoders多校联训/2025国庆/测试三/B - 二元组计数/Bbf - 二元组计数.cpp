// B - baoli
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;

int n;
int a[maxn];
int opt, x;

signed main()
{
	freopen("data.in", "r", stdin);
	freopen("bf.out", "w", stdout);
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];
	cin >> opt >> x;
	
	int ans = 0 ;
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= n ; j ++)
			if(i != j && a[i] / a[j] == x)
				ans ++;
	
	cout << ans;
}