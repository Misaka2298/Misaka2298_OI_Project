#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int a[maxn],tmp[maxn];

void merge_sort(int a[],int l,int r)
{
	if(l>=r) return;
	int mid=(l+r)/2;
	
	merge_sort(a,l,mid);
	merge_sort(a,mid+1,r);
	
	int cnt=0,i=l,j=mid+1;
	while(i<=mid&&j<=r)
	{
		if(a[i]<=a[j]) tmp[cnt++]=a[i++];
		else tmp[cnt++]=a[j++];
	}
	while(i<=mid) tmp[cnt++]=a[i++];
	while(j<=r) tmp[cnt++]=a[j++];
	for(int i=l,j=0;i<=r;i++,j++) a[i]=tmp[j];
}

int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	merge_sort(a,0,n-1);
	for(int i=0;i<n;i++) cout << a[i]<< " ";
	return 0;
}