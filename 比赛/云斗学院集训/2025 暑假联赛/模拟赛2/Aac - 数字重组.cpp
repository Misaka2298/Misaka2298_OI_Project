// Problem: P5956 [POI 2017] Podzielno
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P5956
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// Time: 2025-08-14 20:27:29

#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;
typedef long long LL;

LL b, k, q;
LL sum[maxn], a[maxn];
LL digitsum, numbersum;

signed main()
{
	cin >> b >> q;
	for(int i = 0 ; i < b ; i ++)
	{
		cin >> a[i];
		numbersum += (a[i] * i);
		digitsum += a[i];
	}
	
	if(numbersum % (b-1))
		a[numbersum % (b-1)] --, digitsum --;
	sum[0] = a[0];
	for(int i = 1 ; i < b ; i ++)
		sum[i] = sum[i-1] + a[i];
	
	while(q--)
	{
		cin >> k;
		k ++;
		if(k > digitsum)
			cout << -1 << endl;
		else
			cout << lower_bound(sum, sum+b-1, k) - sum << endl;
	}
		
}