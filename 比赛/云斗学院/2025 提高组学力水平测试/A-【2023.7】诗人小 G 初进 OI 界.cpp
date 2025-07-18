//T1
//expect pts = 100?
//5min09s
//except diff: orange
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
typedef long long LL;

int n;
LL a[maxn], s[maxn];

signed main()
{
	ios::sync_with_stdio(false);cin.tie(nullptr);
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
		cin >> a[i];
	for(int i = 1 ; i <= n ; i++)
		cin >> s[i];
		
	cout << (s[2]-a[2]) / a[1];
		
}
/*
(s[2]-a[2])/a[1]?
*/