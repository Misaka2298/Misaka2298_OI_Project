#include <bits/stdc++.h>
using namespace std;

int n, l, k;

signed main()
{
	cin.tie(0);
	cin >> n >> l >> k;
	int arr[n+10];
	
	for(int i = 0 ; i < n ; i ++)
		cin >> arr[i];
		
	sort(arr, arr+n);
	
	if(arr[0] > l)//special
	{
		cout << 0;
		return 0;
	}
	
	int ans = 0;
	for(int i = 0 ; i < n ; i++)
	{
		if(arr[i] <= l)
		{
			ans ++;
			l += k;
		}
		else break;
	}
	cout << ans;
}