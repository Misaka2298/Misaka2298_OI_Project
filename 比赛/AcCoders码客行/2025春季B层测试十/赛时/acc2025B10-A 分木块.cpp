//T1
//expect pts = 100
#include <bits/stdc++.h>
using namespace std;
const int maxn = 55;

long long n, wood;
long long ans100, ans10, ans1;


signed main()
{
	cin >> n;
	for(int i = 0 ; i < n ; i ++)
	{
		cin >> wood;
		//cout << wood/100 << ' ' << wood%100 << "  ";
		ans100 += wood / 100;
		wood %= 100;
		//cout << wood/10 << ' ' << wood % 10 << endl;
		ans10 += wood / 10;
		wood %= 10;
		ans1 += wood;
	}
	cout << ans100 << endl << ans10 << endl << ans1;
}