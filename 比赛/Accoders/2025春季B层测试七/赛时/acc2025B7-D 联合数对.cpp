//T4
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;

int n, a[maxn], b[maxn];
long long ans;

signed main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i = 0 ; i < n ; i++)
		cin >> a[i];
	for(int i = 0 ; i < n ; i++)
		cin >> b[i];
	
	for(int j = 0 ; j < n ; j++)
		for(int i = 0 ; i < j ; i++)
			if(a[i] + a[j] > b[i] + b[j])
				ans++;
	cout << ans;
}