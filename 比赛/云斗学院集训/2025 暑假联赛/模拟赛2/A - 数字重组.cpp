// A
// expect pts = 40

#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e6+10;
typedef long long LL;

int b, m;
int a[maxn];

void spe()
{
	LL sum = a[0] + a[1];
	while(m--)
	{
		LL k;
		cin >> k;
		if(k >= sum)
			cout << -1 << endl;
		else if(k >= a[0])
			cout << 1 << endl;
		else
			cout << 0 << endl;
	}
	exit(0);
}

signed main()
{
	freopen("digit.in", "r", stdin);
	freopen("digit.out", "w", stdout);
	cin >> b >> m;
	for(int i = 0 ; i < b ; i ++)
		cin >> a[i];
	if(b == 2)
		spe();
	else
	{
		while(m--)
		{
			cout << -1 << endl;
		}
	}
}