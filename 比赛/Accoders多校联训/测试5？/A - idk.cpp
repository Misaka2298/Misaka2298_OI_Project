// T1
// expect pts = 100
// water。。。
#include <bits/stdc++.h>
using namespace std;

string a, b;

signed main()
{
	cin >> a >> b;
	for(int i = 0 ; i < a.size() ; i ++)
		if(isupper(a[i]))
			a[i] = a[i] + 32;
	for(int i = 0 ; i < b.size() ; i ++)
		if(isupper(b[i]))
			b[i] = b[i] + 32;
	
	if(a > b)
		cout << 1;
	else if(b > a)
		cout << -1;
	else
		cout << 0;
	return 0;
}

