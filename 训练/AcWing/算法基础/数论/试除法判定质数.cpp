//https://www.acwing.com/problem/content/868/
#include <bits/stdc++.h>
using namespace std;

int n;
long long val;

bool is_prime(long long x)
{
	if(x < 2) return false;
	for(int i = 2 ; i <= x / i; i ++)//如果i能整除a，那么a/i一定能整除a。故只需要循环到sqrt(a)
		if(x % i == 0) return false;
	return true;
}

signed main()
{
	cin >> n;
	for(int i = 0 ; i < n; i++)
	{
		cin >> val;
		if(is_prime(val)) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
