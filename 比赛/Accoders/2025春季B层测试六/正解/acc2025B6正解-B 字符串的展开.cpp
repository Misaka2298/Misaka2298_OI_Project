//T2正解
#include <bits/stdc++.h>
using namespace std;

int p1, p2, p3;
string str, waitcout;

bool isSameType(int i)
{
	char l = str[i-1], r = str[i+1];
	if((isalpha(l) && isalpha(r)) || (isdigit(l) && isdigit(r)))
		return true;
	else return false;
}

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> p1 >> p2 >> p3 >> str;
	
	int strlen = str.length();
	for(int i = 0 ; i < strlen ; i++)
	{
		if(str[i] != '-') cout << str[i];
		else
		{
			if(i == 0 || i == strlen-1 || str[i-1] >= str[i+1] || !isSameType(i))
			{
				cout << str[i];
				continue;
			}
			char l = str[i-1], r = str[i+1];
			if(p1 == 1 && isupper(l) && isupper(r))
				l = tolower(l), r = tolower(r);
			if(p1 == 2 && islower(l) && islower(r))
				l = toupper(l), r = toupper(r);
				
			for(char j = l+1 ; j < r ; j++)
			{
				char chr = (p1 == 3)? '*' : j;
				waitcout += string(p2, chr);
			}
			if(p3 == 2)
				reverse(waitcout.begin(), waitcout.end());
			cout << waitcout;
			waitcout = "";
		}
	}
}
/*
我再也不写模拟题了。
字符串科技太神奇了，stirng门。
*/