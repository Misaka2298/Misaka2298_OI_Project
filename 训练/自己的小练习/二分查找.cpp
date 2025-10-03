// Problem: 数的范围
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/791/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// Time: 2025-09-23 19:11:47

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;

int n, q;
int arr[maxn];

signed main()
{
	cin >> n >> q;
	for(int i = 1 ; i <= n ; i ++)
		cin >> arr[i];
	
	while(q--)
	{
		int check;
		cin >> check;
		int l = 1, r = n, ans = 0;
		while(l <= r)
		{
			int mid = (l + r) / 2;
			if(arr[mid] >= check)
				ans = mid, r = mid - 1;
			else
				l = mid + 1;
		}
		if(arr[ans] == check)
			cout << ans-1 << ' ';
		else
			cout << -1 << ' ';
		
		l = 1, r = n, ans = 0;
		while(l <= r)
		{
			int mid = (l + r) / 2;
			if(arr[mid] <= check)
				ans = mid, l = mid + 1;
			else
				r = mid - 1;
		}
		if(arr[ans] == check)
			cout << ans-1 << endl;
		else
			cout << -1 << endl;
	}
}