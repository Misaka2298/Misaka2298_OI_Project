#include <bits/stdc++.h>
using namespace std;

long long ve,vm,vt,e,m,t;

signed main()
{
	cin >> ve >> vm >> vt >> e >> m >> t;
	long long v = e*ve + m*vm;
	long long sum;
	if(v%vt != 0) sum = v/vt+1;
	else sum = v/vt;
	//cout << v << ' ' << sum << endl;
	if(sum%t != 0) cout << sum/t+1;
	else cout << sum/t;
	return 0;
}