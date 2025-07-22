//A
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
#define endl '\n'

int n, q;
int num[maxn];

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> q;
	for(int i = 0 ; i < n ; i ++)
		cin >> num[i];
	
	while(q--)
	{
		int goal;
		cin >> goal;
		
		int l = 0 , r = n-1 , ans = -1;
		while(l <= r)
		{
			int mid = (l+r) / 2;
			if(num[mid] >= goal)
			{
				ans = mid;
				r = mid - 1;
			}
			else
				l = mid + 1;
		}
		cout << ans << ' ';
		if(ans == -1)
		{
			cout << -1 << endl;
			continue;
		}
		
		l = 0 , r = n-1 , ans = -1;
		while(l <= r)
		{
			int mid = (l+r) / 2;
			if(num[mid] <= goal)
			{
				ans = mid;
				l = mid + 1;
			}
			else
				r = mid - 1;
		} 
		cout << ans << endl;
	}
}