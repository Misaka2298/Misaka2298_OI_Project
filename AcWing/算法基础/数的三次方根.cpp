#include<bits/stdc++.h>
using namespace std;
int main()
{
	double x;
	cin >> x;
	double l=-100,r=x;
	while(r-l>1e-6)
	{
		double mid=(l+r)/2;
		if(pow(mid,3)>=x) r=mid;
		else l=mid;
	}
	printf("%.6lf",l);
	return 0;
}