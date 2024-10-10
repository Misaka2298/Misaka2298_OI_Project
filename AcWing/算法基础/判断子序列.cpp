#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin >> n>> m;
	int a[n+10],b[n+10];
	for(int i=0;i<n;i++)cin >> a[i];
	for(int i=0;i<m;i++)cin >> b[i];
	
	int i=0,j=0;
	while(i<n||j<m)
	{
		if(a[i]==b[j]) i++;
		j++;
	}
	//cout <<i<<" "<<n<<" "<< j << " " << m<<endl;//debug line
	if(i!=n) cout << "No";
	else cout << "Yes";
	return 0;
}