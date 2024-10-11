#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N]={0};
void quick_sort(int a[],int l,int r)
{
	if(l>=r) return;
	int i=l-1,j=r+1,flag=a[(l+r)/2];
	while(i<j)
	{
		do i++;while(a[i]<flag);
		do j--;while(a[j]>flag);
		if(i<j) swap(a[i],a[j]);
	}
	quick_sort(a,l,j);
	quick_sort(a,j+1,r);
}
int main()
{
	int n,k;
	cin >> n>> k;
	//int a[n+5];
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	quick_sort(a,0,n-1);
	cout << a[k-1];
	return 0;
}