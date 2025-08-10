// A
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;

LD x, y;
LD powxy;

signed main()
{
	cin >> x >> y;
	powxy = x * y;
	
	
	LL llx = x, lly = y;
	/*
	if(sqrt(x) / sqrt(llx) != 1 || sqrt(y) / sqrt(lly) != 1)
	{
		cout << 0;
		exit(0);
	}
	*/
	
	bool flag = 0;
	for(LL i = 2 ; i*i <= powxy ; i ++)
	{
		if(((x/i) / (llx/i) == 1.0) && ((y/i) / (lly/i) == 1.0))
		{
			flag = 1;
			cout << (LL)powxy / (i*i);
			break;
		}
	}
	
	if(!flag)
		cout << 0;
	return 0;
}