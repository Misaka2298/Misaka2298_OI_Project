#include <bits/stdc++.h>
using namespace std;

string str;
int n;

signed main()
{
	cin >> n;
	cin >> str;
	int len = n/3;
	for(int i = len ; i < len*2 ; i++)
		cout << str[i];
	for(int i = 0 ; i < len ; i++)
		cout << str[i];
	for(int i = len*2 ; i < n ; i++)
		cout << str[i];
	return 0;
}