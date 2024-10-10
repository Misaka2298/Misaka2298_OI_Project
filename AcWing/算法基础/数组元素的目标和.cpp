#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,x;
	cin >> n>>m>>x;
	int a[n+5],b[m+5];
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<m;i++) cin >> b[i];
	
	int j=m-1;
	for(int i=0;i<n;i++)
	{
		while(j>=0&&a[i]+b[j]>x) j--;
		if(j>=0&&a[i]+b[j]==x)
		{
			cout << i << " " <<j;
			return 0;
		}
	}
	//暴力
	/*
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(a[i]+b[j]==x)
			{
				cout << i << " " <<j;
				return 0;
			}
	*/
	return 0;
}