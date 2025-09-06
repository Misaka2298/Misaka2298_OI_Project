//https://www.acwing.com/problem/content/870/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;

int n, idx;
bool st[maxn];
vector<int> prime;

int get_prime()
{
	for(int i = 2 ; i <= n ; i++)
	{
		if(!st[i]) prime.push_back(i);
		for(auto pri_j : prime)	
		{
			if(i * pri_j > n) break;
			st[i * pri_j] = true;
			if(i % pri_j == 0) break;
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