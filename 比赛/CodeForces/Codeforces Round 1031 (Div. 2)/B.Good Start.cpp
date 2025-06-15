#include <bits/stdc++.h>
using namespace std;

int T;
int n, m, a, b;
int x1, y1, x2, y2;

signed main()
{
	cin >> T;
	while(T--)
	{
		cin >> n >> m >> a >> b >> x1 >> y1 >> x2 >> y2;
		
		if(x1 == x2 && y1 > y2)
		{
			y2 += (b-1);	
		}
		else if(x1 == x2 && y2 > y1)
		{
			y1 += (b-1);
		}
		else if(x1 < x2 && y1 == y2)
		{
			x1 += (a-1);
		}
		else if(x2 < x1 && y1 == y2)
		{
			x2 += (a-1);
		}
		else if(x1 < x2 && y1 < y2)
		{
			x1 += (a-1);
			y1 += (b-1);
		}
		else if(x2 < x1 && y2 < y1)
		{
			x2 += (a-1);
			y2 += (b-1);
		}
		else if(x1 < x2 && y1 > y2)
		{
			x1 += (a-1);
			y2 += (b-1);
		}
		else if(x2 < x1 && y2 > y1)
		{
			x2 += (a-1);
			y1 += (b-1);
		}
		
		if(x1 > x2 && y1 > y2)
			swap(x1, x2), swap(y1, y2);
		if(abs(x2-x1) < a || abs(y2-y1) < b)
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}
}