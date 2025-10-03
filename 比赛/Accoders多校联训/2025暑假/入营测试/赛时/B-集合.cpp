//T2
//expect pts = 0
#include <bits/stdc++.h>
using namespace std;
const int maxn = 35;

int n;
unsigned long long a[maxn];

signed main()
{
	freopen("set.in", "r", stdin);
	freopen("set.out", "w", stdout);
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];
	
	sort(a+1, a+1+n);
	
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= n ; j++)
			a[j] = a[j-1] + a[j];
			
	cout << a[n];
}
