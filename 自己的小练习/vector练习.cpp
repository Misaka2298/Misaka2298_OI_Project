#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector<int>a;
	a.push_back(1);
	a.push_back(4);
	a.push_back(2);
	a.push_back(100);
	a.push_back(0);
	for(int i=0;i<a.size();i++)
	{
		cout << a[i]<<endl;
	}	
	reverse(a.begin(),a.end());
	cout << endl;
	for(int i=0;i<a.size();i++)
	{
		cout << a[i]<<endl;
	}
}