#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;

int n;
bool st[maxn];

int get_prime(int x)
{
	int ans = 0;
	for(int i = 2 ; i <= n ; i++)
	{
		if(st[i]) continue;//prune
		for(int j = 2 ; i*j <= n ; j++)
			st[i*j] = true;
	}
	for(int i = 2 ; i <= n ; i++)
		if(!st[i]) ans ++;
	return ans;
}

signed main()
{
	cin >> n;
	int cnt = get_prime(n);
	cout << cnt;
	return 0;
}