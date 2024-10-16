#include <bits/stdc++.h>
using namespace std;
int main()
{
	bool flag=true;
	int a[100]={0};
	for(int i=1;i<=100;i++)
	{
		a[i-1]=i;
		if(a[i-1]==0||a[i-1]==1) continue;
		else for(int j=2;pow(j,2)<=a[i-1];j++)
			{
				if(a[i-1]%j==0) flag=false;
			}
		//cout <<int(flag)<<endl;
		if (flag)cout << a[i-1]<<endl;
		flag = true;
	}
	return 0;
}