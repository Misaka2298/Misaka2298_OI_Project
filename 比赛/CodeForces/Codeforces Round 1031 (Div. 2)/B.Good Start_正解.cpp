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
		
		if(y1 == y2)
		{
			if(abs(x2-x1) % a == 0)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
		else if(x1 == x2)
		{
			if(abs(y1-y2) % b == 0)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
		else
		{
			if(abs(y1-y2)%b==0 || abs(x1-x2)%a==0)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
		
	}
}