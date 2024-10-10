#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int a[maxn]={0};
void quick_sort(int a[],int l,int r)
{
	if(l>=r) return;
	int i=l-1,j=r+1,flag=a[(l+r)/2];
	while(i<j)
	{
		do i++;while(a[i]< flag);
		do j--;while(a[j]>flag);
		if(i<j) swap(a[j],a[i]);
	}
	quick_sort(a,l,j);
	quick_sort(a,j+1,r);
}
int main()
{
	int n;
	cin >> n;
	for(int i = 0;i < n;i++) scanf("%d",&a[i]);
	quick_sort(a,0,n-1);
	for(int i = 0;i < n;i++) cout << a[i] << " ";
	return 0;
}