//https://www.acwing.com/problem/content/870/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;

int n, prime[maxn], idx;
bool st[maxn];

int get_prime()
{
	for(int i = 2 ; i <= n ; i++)
	{
		if(!st[i]) prime[++idx] = i;
		for(int j = 1 ; 1ll*i*prime[j] <= n ; j++)
		{
			st[i*prime[j]] = true;
			if(i % prime[j] == 0) break;
		}
	}
	int ans = 0;
	for(int i = 2 ; i <= n ; i++)
		if(!st[i]) ans++;
	return ans;
}

signed main()
{
	cin >> n;
	int ans = get_prime();
	cout << ans;
	return 0;
}