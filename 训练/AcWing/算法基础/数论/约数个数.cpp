//https://www.acwing.com/problem/content/872/
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;

int n;

signed main()
{
	cin >> n;
	unordered_map<int,int>primes;
	while(n--)
	{
		int x;
		cin >> x;
		for(int i = 2 ; i <= x / i ; i++)
			while(x % i == 0)
			{
				x /= i;
				primes[i]++;
			}
		if(x > 1)primes[x]++;
	}
	
	long long res = 1;
	for(auto prime : primes) res =  res * (prime.second + 1) % mod;
	
	cout << res;
	return 0;
}