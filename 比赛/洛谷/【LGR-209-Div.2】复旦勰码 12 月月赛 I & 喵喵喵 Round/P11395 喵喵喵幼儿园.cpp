#include <bits/stdc++.h>
using namespace std;

string a , b , c;
int n;


void coutc()
{
	int len = c.length();
	for(int i = 0 ; i < len-1 ; i ++)
		cout << c[i];
	cout << endl;
	return;
}

signed main()
{
	cin >> n;
	while(n--)
	{
		cin >> a >> b >> c;
		if(a == "eat" && c == "eat?") cout << "or" << endl;
		else if(a == "eat" && c != "eat?") coutc();
		else if(c == "eat?" && a != "eat") cout << a << endl;
		else cout << a << endl;
	}
	return 0;
}