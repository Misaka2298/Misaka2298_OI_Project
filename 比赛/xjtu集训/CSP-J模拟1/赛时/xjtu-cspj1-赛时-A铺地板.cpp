//T1
#include <bits/stdc++.h>
using namespace std;

unsigned long long T, x, y, s, s4, s2;

signed main()
{
	cin.tie(0);
	cin >> T;
	while(T--)
	{
		s2 = 0; s4 = 0;
		unsigned long long ans = 0;
		cin >> x >> y;
		s = x * y;
		if(s % 2 != 0)
		{
			cout << "N" << endl << -1 << endl;
			continue;
		}
		if(x % 2 != 0 && y % 2 == 0)
		{
			x -= 1;
			s4 = x * y;
			ans += s4 / 4;
			s2 = y;
			ans += s2 / 2;
			cout << "Y" << endl << ans << endl;	
			continue;
		}
		if(x % 2 == 0 && y % 2 != 0)
		{
			y -= 1;
			s4 = x * y;
			ans += s4 / 4;
			s2 = x;
			ans += s2 / 2;
			cout << "Y" << endl << ans << endl;	
			continue;
		}
		/*
		if(x % 2 != 0 && y % 2 != 0)
		{
			cout << "wwwww" << endl;
			y -= 1; x -= 1;
			s4 = x * y;
			ans += s4 / 4;
			s2 = y + x + 1;
			ans += s2 / 2;
			cout << "Y" << endl << ans << endl;	
			continue;
		}
		*/
		ans = s / 4;
		cout << "Y" << endl << ans << endl;	 
	}
}