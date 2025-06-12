#include <bits/stdc++.h>
using namespace std;
const int maxn = 110;

int a, n;

signed main()
{
	cin >> n;
	for(int i = 0 ; i < n ; i ++)
	{
		cin >> a;
		if(a < 2)
		{
			cout << "No" << endl;
			continue;
		}
		bool flag = true;
		for(int j = 2 ; j <= a/j ; j ++)
			if(a % j == 0)
				flag = false;
				
		if(flag) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}