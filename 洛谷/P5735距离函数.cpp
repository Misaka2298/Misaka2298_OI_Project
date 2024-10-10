#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
double dist(double x1,double y1,double x2,double y2)
{
	return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
}
int main()
{
	double x1,y1,x2,y2,x3,y3,dist1,dist2,dist3,ans;
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	dist1=dist(x1,y1,x2,y2);
	dist2=dist(x3,y3,x2,y2);
	dist3=dist(x1,y1,x3,y3);
	ans=dist1+dist2+dist3;
	printf("%.2lf",ans);
}