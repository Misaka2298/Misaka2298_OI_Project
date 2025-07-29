// Problem: CF1292B Aroma's Search
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1292B
// Memory Limit: 250 MB
// Time Limit: 1000 ms
// Time: 2025-07-28 20:49:59
// expect pts = 

#include <bits/stdc++.h>
using namespace std;
//#define max(a, b) a > b ? a : b
const int maxn = 100;
typedef long long LL;

LL ax, ay, bx, by;
LL xs, ys, t;
LL x[maxn], y[maxn];
LL ans, n;

LL dist(LL x1, LL y1, LL x2, LL y2)
{
	return llabs(x1 - x2) + llabs(y1 - y2);
}

signed main()
{
	cin >> x[0] >> y[0] >> ax >> ay >> bx >> by;
	cin >> xs >> ys >> t;
	
	while(++n)
	{
		x[n] = ax * x[n-1] + bx;
		y[n] = ay * y[n-1] + by;
		if(x[n] > xs && y[n] > ys && dist(xs, ys, x[n], y[n]) > t)
			break;
	}
	
	for(int i = 0 ; i <= n ; i ++)
	{
		LL tans = 0, tt = t;
		if(dist(x[i], y[i], xs, ys) <= tt)
			tans ++, tt -= dist(x[i], y[i], xs, ys);
		else
		{
			ans = max(ans, tans);
			continue;
		}
		
		for(int j = i ; j > 0 ; j --)
		{
			if(dist(x[j], y[j], x[j-1], y[j-1]) <= tt)
				tt -= dist(x[j], y[j], x[j-1], y[j-1]), tans ++;
			else
				break;
		}
		for(int j = 1 ; j <= n ; j ++)
		{
			if(dist(x[j], y[j], x[j-1], y[j-1]) <= tt)
				tt -= dist(x[j], y[j], x[j-1], y[j-1]), tans += j > i;
			else break;
		}
		ans = max(ans, tans);
	}
	cout << ans;
}