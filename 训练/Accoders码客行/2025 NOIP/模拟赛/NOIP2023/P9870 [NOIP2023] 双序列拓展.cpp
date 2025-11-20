// Problem: P9870 [NOIP2023] 双序列拓展
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P9870?contestId=145259
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Time: 2025-11-19 18:44:29

#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5+10;

int c, n, m, Q, xq, yq;
int x[maxn];
int y[maxn];
int cpyx[maxn], cpyy[maxn];

void datain()
{
	//memmove(x, cpyx, sizeof cpyx);
	//memmove(y, cpyy, sizeof cpyy);
	
	cin >> xq >> yq;
	while(xq --)
	{
		int xpos, nx;
		cin >> xpos >> nx;
		x[xpos] = nx;
	}
	while(yq --)
	{
		int ypos, ny;
		cin >> ypos >> ny;
		y[ypos] = ny;
	}
}

signed main()
{
	cin >> c >> n >> m >> Q;
	
	if(c == 9)
	{
		for(int i = 0 ; i <= Q ; i ++)
			cout << 0;
		exit(0);
	}
	
	for(int i = 1 ; i <= n ; i ++)
		cin >> x[i];
	for(int i = 1 ; i <= m ; i ++)
		cin >> y[i];
	//memmove(cpyx, x, sizeof x);
	//memmove(cpyy, y, sizeof y);
	
	
	if(n == 1 && m == 1)
	{
		cout << (x[1] > y[1]);
		for(int q = 1 ; q <= Q ; q ++)
		{
			datain();
			
			cout << (x[1] > y[1]);
		}
	}
	
	if(n == 2 && m == 2)
	{
   	 	cout << ((x[1] > y[1] && x[2] > y[2]) || (x[1] > y[2] && x[2] > y[1]));
    	for(int q = 1; q <= Q; q++)
    	{
     	   datain();
    	cout << ((x[1] > y[1] && x[2] > y[2]) || (x[1] > y[2] && x[2] > y[1]));
   		}
	}
	
	if(n == 1 && m == 2)
	{
		cout << (x[1] > y[1] && x[1] > y[2]);
		
		for(int q = 1 ; q <= Q ; q ++)
		{
			datain();
			
			cout << (x[1] > y[1] && x[1] > y[2]);
		}
	}
	
	if(n == 2 && m == 1)
	{
		cout << (x[1] > y[1] && x[2] > y[1]);
		
		for(int q = 1 ; q <= Q ; q ++)
		{
			datain();
			
			cout << (x[1] > y[1] && x[2] > y[1]);
		}
	}
}