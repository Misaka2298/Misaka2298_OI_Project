#include <bits/stdc++.h>
using namespace std;
bool is_prime(int num)
{
	if(num==1||num==0) return false;
	for(int i=2;i*i<=num;i++)
	{
		if(num%i==0) return false;
	}
	return true;
}
int main()
{
	int n;
	cin >>n;
	int a[n]={0};
	for(int i=1;i<=n;i++)
	{
		cin >> a[i-1];
		if(is_prime(a[i-1])) cout << a[i-1]<<" ";
	}
	return 0;
	
}