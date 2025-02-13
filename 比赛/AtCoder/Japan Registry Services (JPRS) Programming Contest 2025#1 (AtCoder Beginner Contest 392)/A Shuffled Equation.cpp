#include <bits/stdc++.h>
using namespace std;

int val[3];

signed main()
{
	for(int i = 0 ; i < 3 ; i++)
		cin >> val[i];
		
	sort(val,val+3);
	if(val[0] * val[1] == val[2]) cout << "Yes";
	else cout << "No";
	return 0;
}