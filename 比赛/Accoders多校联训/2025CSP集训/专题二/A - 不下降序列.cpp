// A 
// expect pts = 100 
// expect diff = orange

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;

int n;
int a[maxn];

bool check()
{
	for(int i = 1 ; i < n ; i ++)
		if(a[i+1] < a[i])
			return false;
	return true;
}

signed main()
{
	freopen("ulist.in", "r", stdin);
	freopen("ulist.out", "w", stdout);
	cin >> n;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];
	a[n+1] = 0x3f3f3f3f;
	
	if(n == 1)
	{
		cout << "YES";
		exit(0);
	}
	
	for(int i = 1 ; i < n ; i ++)
	{
		if(a[i+1] < a[i])
		{
			int mn = 0x3f3f3f3f, pos = 0;
			for(int j = i+1 ; j <= n ; j ++)
				if(a[j] >= a[i-1] && a[j] <= mn && a[i] >= a[j-1] && a[i] <= a[j+1])
					mn = a[j], pos = j;
			if(pos)swap(a[pos], a[i]);
			break;
		}		
	}
	
	/*
	for(int i = 1 ; i <= n ; i ++)
		cout << a[i] << ' ';
	cout << endl;
	*/
	
	if(check())
		cout << "YES";
	else
		cout << "NO";
	
	
	
	
	
	
}