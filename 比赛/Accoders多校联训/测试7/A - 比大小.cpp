// T1
// expect pts = 100
// water。。。
#include <bits/stdc++.h>
using namespace std;

string a, b;

signed main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr);
	//freopen("lexi.in", "r", stdin);
	//freopen("lexi.out", "w", stdout);
	cin >> a >> b;
	for(int i = 0 ; i < a.size() ; i ++)
		if(isupper(a[i]))
			a[i] = tolower(a[i]);
	for(int i = 0 ; i < b.size() ; i ++)
		if(isupper(b[i]))
			b[i] = tolower(b[i]);
	
	if(a > b)
		cout << 1;
	else if(b > a)
		cout << -1;
	else
		cout << 0;
	return 0;
}

