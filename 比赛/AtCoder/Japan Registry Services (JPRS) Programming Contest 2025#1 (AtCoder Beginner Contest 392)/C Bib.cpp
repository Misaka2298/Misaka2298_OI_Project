#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5+10;

int n;
int val[maxn], bu[maxn], match[maxn];

signed main()
{
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
		cin >> val[i];
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> bu[i];
		match[bu[i]] = i;
	}
		
		
	for(int i = 1 ; i <= n ; i++)
		cout << bu[val[match[i]]] << ' ';
		
	return 0;
}