#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long ans=0;
	int a , b;
	cin >> a >> b;
	for(int i = 1 ; i<=a ; i++) ans ++;
	for(int i = 1 ; i<=b ; i++) ans ++;
	cout << ans;
	return 0;
}