#include <bits/stdc++.h>
using namespace std;
const int maxn = 1;

string str;

signed main()
{
	cin >> str;
	if (str == "N") cout << "S";
	else if (str == "S") cout << "N";
	
	else if (str == "E") cout << "W";
	else if (str == "W") cout << "E";
	
	else if (str == "NE") cout << "SW";
	else if (str == "SW") cout << "NE";
	
	else if (str == "SE") cout << "NW";
	else if (str == "NW") cout << "SE";
	
	return 0; 
}