//T2
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+10;

int num[maxn], ver[maxn];
char sign[maxn];
int n, idx, numcnt, signcnt;

signed main()
{
	cin >> n;
	
	int flagnum = true, flagsign = true;
	while(flagnum && flagsign)
	{
		if(cin >> num[numcnt++]) flagnum = true;
			else flagnum = false;
		if(cin >> sign[signcnt++]) flagsign = true;
			else flagsign = false;
	}
	
	n = numcnt;
	
	for(int i = 0 ; i < signcnt ; i++)
	{
		if(sign[i] == '*' || sign[i] == '/')
			ver[i] = ++idx;
		else if(sign[i] == '+' || sign[i] == '-')
			continue;
	}
	
	for(int i = 0 ; i < signcnt ; i++)
	{
		if(sign[i] == '+' || sign[i] == '-')
			ver[i] = ++idx;
		else if(sign[i] == '*' || sign[i] == '/')
			continue;
	}
	
	for(int i = 0 ; i < numcnt-1 ; i++)
	{
		cout << num[i] << sign[i] << '[' << ver[i] << ']';
	}
	cout << num[numcnt-1];
}
/*
int flagnum = true, flagsign = true;
while(flagnum && flagsign)
{
	if(cin >> num[numcnt]) flagnum = true;
	else flagnum = false;
	if(cin >> sign[signcnt]) flagsign = false;
		else flagsign = false;
}
*/