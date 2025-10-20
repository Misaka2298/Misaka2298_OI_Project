// E fixed

#include <bits/stdc++.h>
using namespace std;

int n;
string str;

void del(char x)
{
	for(int i = 0 ; i < str.size() ; i ++)
		if(str[i] == x)
		{
			str.erase(i, 1);
			break;
		}
}

void insert(char goal, string chr)
{
	for(int i = str.size()-1 ; i >= 0 ; i --)
		if(str[i] == goal)
		{
			str.insert(i, chr);
			break;
		}
}

void change(char x, char y)
{
	for(int i = 0 ; i < str.size() ; i ++)
		if(str[i] == x)
			str[i] = y;
}

signed main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	getline(cin, str);
	cin >> n;
	while(n --)
	{
		char opt, x;
		string y;
		char z;
		cin >> opt >> x;
		if(opt == 'D')
			del(x);
		if(opt == 'I')
			cin >> y, insert(x, y);
		if(opt == 'R')
			cin >> z, change(x, z);
	}
	cout << str;
}