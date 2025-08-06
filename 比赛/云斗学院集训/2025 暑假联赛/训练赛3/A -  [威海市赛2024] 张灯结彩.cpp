//T1
//C0ns1st is NaiLoong
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4+10;

#define int long long //look this

int a[maxn];

signed main()
{
	a[2] = 3;
	for(int i = 3 ; i <= maxn-1 ; i ++)
		a[i] = a[i-1] + 6;
	for(int i = 1 ; i <= maxn-1 ; i ++)
		a[i] = a[i-1] + a[i];
	
	int T;
	cin >> T;
	while(T--)
	{
		int b;
		cin >> b;
		cout << a[b] + (2*b-2) << endl;
	}
	return 0;
}