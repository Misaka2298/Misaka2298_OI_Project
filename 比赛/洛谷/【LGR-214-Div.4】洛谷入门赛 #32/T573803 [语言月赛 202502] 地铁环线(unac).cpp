#include <bits/stdc++.h>
using namespace std;

long long n, x, y;

signed main()
{
	cin >> n >> x >> y;
	if(x>y) swap(x,y);
	
	if(y-x < n-y+x) cout << "Clockwise Loop";
	if(y-x > n-y+x) cout << "Counter-clockwise Loop";
	
	if(y-x == n-y+x) printf("\"Wonderful\"");
	if(x==y) printf("\"Wonderful\"");
	
	return 0;
}