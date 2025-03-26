#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e5+10;

long long n, arr[maxn];
long long stk[maxn], cnt;
long long tt;

signed main()
{
	cin >> n;
	for(long long i = 1 ; i <= n ; i++)
		cin >> arr[i];
	
	for(long long i = 1 ; i <= n ; i++)
	{
		while(tt != 0 && stk[tt] <= arr[i])
			tt--;
		cnt += tt;
		stk[++tt] = arr[i];
	}
	cout << cnt;
}