//T2正解
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;

int n, depth[maxn], s[maxn];

signed main()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> depth[i];
		
	for(int i = 1 ; i <= n ; i ++)
		s[i] = depth[i] - depth[i-1];
	
	int ans = 0;
	for(int i = 1 ; i <= n ; i ++)
		if(s[i] > 0) ans += s[i];
	cout << ans;
}