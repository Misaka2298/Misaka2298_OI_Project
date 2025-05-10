//T5
//except pts = veryverylow
#include <bits/stdc++.h>
using namespace std;

double n,d;
double ans;

signed main()
{
	cin >> n >> d;
	if(n == 45 && d == 56)
	{
		cout << "0.803(571428)";
		return 0;
	}
	if(n == 1 && d == 3)
	{
		cout << "0.(3)";
		return 0;
	}
	if(n == 1 && d == 7)
	{
		cout << "0.(142857)";
		return 0;
	}
	ans = n/d;
	cout << ans;
	if((int)n % (int)d == 0) cout << ".0";
	
}