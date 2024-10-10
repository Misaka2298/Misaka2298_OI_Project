#include <bits/stdc++.h>
using namespace std;
int main()
{
	int max=0,min=10000,a[100]={0};
	for(int i=1;i<=100;i++)
	{
		cin >> a[i-1];
		if(a[i-1]>max) max=a[i-1];
		if(a[i-1]<min) min=a[i-1];
	}
	cout<<max<<" "<<min;
	return 0;
}