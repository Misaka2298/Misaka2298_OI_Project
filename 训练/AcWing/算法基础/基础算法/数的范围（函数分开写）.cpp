#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+10;
int n , q , arr[maxn];

int left(int check)
{
	int l=0 , r=n-1;
	while(l<r)
	{
		int mid = (l+r)/2;
		if(arr[mid] >= check) r = mid;
		else l = mid + 1;
	}
	if(arr[l] != check) return -1;
	else return l;
}

int right(int check)
{
	int l=0 , r=n-1;
	while(l<r)
	{
		int mid = (l+r+1)/2;
		if(arr[mid] <= check) l = mid;
		else r = mid - 1;
	}
	if(arr[l] != check) return -1;
	else return l;
}


int main()
{
	scanf("%d%d",&n,&q);
	for(int i = 0 ; i < n ; i++) scanf("%d",&arr[i]);
	
	while(q--)
	{
		int check;
		scanf("%d",&check);
		cout << left(check) << ' ' << right(check) << endl;
	}
	return 0;
}