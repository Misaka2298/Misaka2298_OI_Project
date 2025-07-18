//T1
#include <bits/stdc++.h>
using namespace std;

int a, b;
string stra, strb;

signed main()
{
	cin >> a >> b;
	if(a > 0)
		stra = "North";
	else
		stra = "South";
	
	if(b>0)
		strb = "East";
	else
		strb = "West";
	
	cout << stra << strb;
}