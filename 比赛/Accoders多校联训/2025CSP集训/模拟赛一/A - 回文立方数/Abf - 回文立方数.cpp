// A bf
// expect pts = 
// expect diff = 

/*
提高组不是不考数位dp吗
所以这不是数位dp。
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const double eps = 1e-9;

LL n;

void check(LL x)
{
	bool flag = true;
	
	string str = to_string(x);
	for(int i = 0 ; i < str.size() ; i ++)
		if(str[i] != str[str.size()-1-i])
		{
			flag = false;
			break;
		}
	if(!flag)
		return;
	/*
	flag = false;
	for(int i = 0 ; i <= x ; i ++)
		if(i*i*i == x)
		{
			cout << i << ' ' << x << endl;
			break;
		}
	*/
	
	long double dx = cbrt(x);
	LL lx = dx;
	if(dx - lx < eps)
		cout << x << endl;
	

}

signed main()
{
	freopen("Abf.in", "r", stdin);
	freopen("Abf.out", "w", stdout);
	cin >> n;
	for(LL i = 1 ; i <= n ; i ++)
		check(i);
}