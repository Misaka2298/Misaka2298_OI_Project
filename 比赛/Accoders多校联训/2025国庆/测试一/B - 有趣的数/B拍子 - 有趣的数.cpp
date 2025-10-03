// T2 paizi
#include <bits/stdc++.h>
using namespace std;
#include <windows.h>

signed main()
{
	while(1)
	{
		system("data.exe");
		system("baoli.exe");
		system("my.exe");
		if(system("fc my.out right.out"))
		{
			cout << "WA";
			break;
		}
		else
			cout << "AC" << endl;
	}
}