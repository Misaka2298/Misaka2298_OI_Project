#include <bits/stdc++.h>
using namespace std;

int main()
{
	while(true)
	{
		system("data.exe > data.in");
		system("baoli.exe < data.in >baoli.out");
		system("std.exe < data.in > std.out");
		if(system(fc std.out baoli.out)) cout << "AC" << endl;
		else cout << "error" << endl , break;
	}
	return 0;
}