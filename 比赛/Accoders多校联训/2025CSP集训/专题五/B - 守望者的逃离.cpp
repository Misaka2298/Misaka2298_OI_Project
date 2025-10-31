// B
// expect pts = 
// expect difff = yellow

#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5+10;
typedef long long LL;

LL m, s, t;
LL f[maxn];

signed main()
{
	freopen("run.in", "r", stdin);
	freopen("run.out", "w", stdout);
	cin >> m >> s >> t;
	LL nowt = 0, nowpos = 0, needjump = (s+59)/60;
	nowpos += (m/10) * 60;
	nowt += (m/10);
	m /= 10;
	
	while(1)
	{
		if(nowt + (m+3)/4 >= t || nowpos >= s)
			break;
		 m += 4;
		 nowt += 1;
		 if(m >= 10)
		{
			nowpos += 60;
			nowt += 1;
			m /= 10;
		}
	}
	
	if(nowpos+((t-nowt) * 17) < s)
	{
		cout << "No" << endl << nowpos+((t-nowt) * 17);
		exit(0);
	}
	
	//cout << nowt << endl;
		
	cout << "Yes" << endl;
	
	while(nowpos < s)
	{
		nowt += 1;
		nowpos += 17;
	}
	
	cout << nowt;
	
	
	
}