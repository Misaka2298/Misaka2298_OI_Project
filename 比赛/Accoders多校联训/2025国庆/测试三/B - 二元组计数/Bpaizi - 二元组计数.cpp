// B&C paizi
#include <bits/stdc++.h>
using namespace std;
#include <windows.h>

int ans;
signed main()
{
	while(1)
	{
		system("data.exe");
		system("my.exe");
		system("bf.exe");
		if(!system("fc my.out bf.out"))
			cout << "ac" << endl;
		else
		{
			cout << "wa";
			break;
		}
	}
}