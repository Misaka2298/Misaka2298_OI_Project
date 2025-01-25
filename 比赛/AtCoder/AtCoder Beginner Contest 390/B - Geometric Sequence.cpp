#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;
long long  n, a[maxn];

signed main()
{
	cin >> n;
	for(int i = 0 ; i < n ;i++)
		cin >> a[i];
	
	
	
	if(n == 2)
	{
		cout << "Yes";
		return 0;
	}
	
	
	bool flag = true;
	
	for(int i = 0 ; i < n-2 ;i++)
	{
		if(a[i+1] * a[i+1] != a[i] * a[i+2]) flag = false;
	}
	
	/*
	long double x = a[1] / a[0];
	cout << x << endl;
	for(int i = 0 ; i < n-1 ;i++)
	{
		int sol1 = a[i] * x;
		int sol2 = a[i+1];
		if(sol1 != sol2) flag = false;
	}
	*/
	
	if(flag) cout << "Yes";
	else cout << "No";
	return 0;
}