#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;

int n, times[maxn];

signed main()
{
	cin >> n;
	for(int i = 0 ; i < n ; i++)
		cin >> times[i];
	
	sort(times, times + n);
	
	long long ans = 0;
	
	for(int i = 0 ; i < n ; i++)
		ans += times[i] *(n-i-1);
		
	cout << ans;
}