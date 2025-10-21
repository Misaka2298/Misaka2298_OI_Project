// Problem: P1832 A+B Problem（再升级）
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1832
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// Time: 2025-10-21 18:44:16

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+10;
typedef long long LL;

LL n;
vector<LL> primes;
bool st[maxn];
LL f[maxn];

void get_prime()
{
	for(int i = 2 ; i <= n ; i ++)
	{
		if(!st[i])
			primes.push_back(i);
		for(auto pri_j : primes)
		{
			if(i * pri_j > n) break;
			st[pri_j * i] = 1;
			if(i % pri_j == 0)
				break;
		}
			
	}
}

signed main()
{
	cin >> n;
	get_prime();
	
	//for(auto pri : primes)
		//cout << pri << endl;
	
	f[0] = 1;
	for(auto v : primes)
		for(int j = v ; j <= n ; j ++)
			f[j] += f[j-v];
	
	cout << f[n];
	
	
	
	
	
	
	
}