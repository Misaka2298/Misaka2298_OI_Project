//T1
#include <bits/stdc++.h>
using namespace std;

int lis[13];
int now, mom;

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	for(int i = 1 ; i <= 12 ; i ++)
		cin >> lis[i];
		
	for(int i = 1 ; i <= 12 ; i ++)
	{
		now += 300;
		now -= lis[i];
		if(now < 0)
		{
			cout << "-" << i << endl;
			return 0;
		}
		mom += now - now % 100;
		now %= 100;
		
		//cout << now << ' ' << mom << endl;
	}
	cout << mom * 1.2 + now;
}