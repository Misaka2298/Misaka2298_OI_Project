#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
typedef long long LL;
int a[maxn],tmp[maxn];

LL solve(int a[],int l,int r)
{
	if(l>=r) return 0;
	
	int mid=(l+r)/2;
	
	LL res=solve(a,l,mid)+solve(a,mid+1,r);
	
	int cnt=0,i=l,j=mid+1;
	while(i<=mid&&j<=r)
	{
		if(a[i]<=a[j]) tmp[cnt++]=a[i++];
		else
		{
			tmp[cnt++]=a[j++];
			res+=mid-i+1;
		}
	}
	while(i<=mid)tmp[cnt++]=a[i++];
	while(j<=r)tmp[cnt++]=a[j++];
	for(int i=l,j=0;i<=r;i++,j++) a[i]=tmp[j];
	
	return res;
}

int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	cout << solve(a,0,n-1);
	return 0;
}