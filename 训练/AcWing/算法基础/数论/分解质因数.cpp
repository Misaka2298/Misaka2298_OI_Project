//https://www.acwing.com/problem/content/869/
#include <bits/stdc++.h>
using namespace std;
int n, x;

void divide()
{
	for(int i = 2 ; i <= x/i ; i++)
	{
		if(x % i == 0)
		{
			int s = 0;
			while(x % i == 0)
			{
				x /= i;
				s++;
			}
			cout << i << ' ' << s << endl;
		}
	}
	if(x > 1) cout << x << ' '<< 1 << endl;
	cout << endl;
	return;
}

signed main()
{
	cin >> n;
	while(n --)
	{
		cin >> x ;
		divide();
	}
	return 0;
}